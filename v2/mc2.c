#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "mc1.h"
#include <inttypes.h>
#include <errno.h>

int midDayComm();

struct newCommands {
		int numElements;
		//create array of ten char* with 30 chars each
		char input[10][30];
};

int main() {


	struct newCommands *newCs = malloc(1*sizeof(struct newCommands));
	//below is test code for custom commands
	/*
	strcpy( (*newCs).input[0],  "ls" );
	strcpy( (*newCs).input[1], "pwd" );
	(*newCs).numElements = 2;
	*/

	
	//======
	//activate our commander
	//keep running until user forcefully exits
	while (1) {
		midDayComm(newCs);
		//midDayComm(newCommands);
	}

	
	//exit
	return(0);


}

//int midDayComm(char* newCommands) {
int midDayComm(struct newCommands* newCs) {	
	
	
	//endptr is a thing needed to make strtoi work in the accessing the array of comm
	char* endptr;
	
	

	int numElements = (*newCs).numElements;
	

	// Introduce our program
	printf("===== Mid-Day Commander, v0 =====\n");
	printf("G'day, Commander! What command would you like to run?\n");
	printf("   0. whoami  : Prints out the result of the whoami command\n");
	printf("   1. last    : Prints out the result of the last command\n");
	printf("   2. ls      : Prints out the result of a listing on a user-specified path\n");

	//here, we interrupt to print out our custom commands, if any
	for (int i = 0; i < numElements; i++){
		printf("   %d. %s : User added command\n", i+3, (*newCs).input[i]);
	}
	
	//continue with the scheduled commands
	printf("   a. add command : Adds a new command to the menu.\n");
	printf("   c. change directory : Changes process working directory\n");
	printf("   e. exit : Leave Mid-Day Commandar\n");
	printf("   p. pwd : Prints working directory\n");	
	
	//we create a character to hold what the user gives us

	char* comm = (char*)malloc(128*sizeof(char*));
	printf("Option?: ");
	fgets(comm, 128, stdin);
	comm = strtok(comm, "\n");
	
	
	
	//c is for change directory
	if (0 == strcmp(comm, "c")) {
		char* dir = (char*)malloc(128*sizeof(char*));
		printf("\n\n");
		printf("-- Change Directory --\n");
		printf("New Directory?: ");
		fgets(dir, 128, stdin);
		dir = strtok(dir, "\n");
		chdir(dir);
		printf("\n\n");
	}
	//a for add command
	else if (0 == strcmp(comm, "a")) {
		printf("\n");
		printf("-- Add a command --\n");
		
		// ask for the command input and put it into the array of stored
		char* args = (char*)malloc(128*sizeof(char*));
		printf("Command to add?: ");
		fgets(args, 128, stdin);
		int len;
		// remove newline
		len = strlen(args);
		if( args[len-1] == '\n' ) {
			args[len-1] = 0;
		}
		
		//store as input[numElements] because if there are x elements, numElements will be x+1
		//for example, if there are elements 0, 1, we will store as 2
		strcpy( (*newCs).input[numElements],  args);
		
		//increment the count
		(*newCs).numElements = (*newCs).numElements+1;
		//update the local count as well
		int numElements = (*newCs).numElements;
	
		printf("Okay, added with ID %d!\n\n", numElements+2);
			
	}
	//else, if it is none of the original commands, cycle through our array to see if we have a match
	//might need to check for error above
	
	//p is for current working directory
	else if (0 == strcmp(comm, "p")) {
		printf("\n\n");
		char cwd[1024];
		printf("-- Current Directory --\n");
		getcwd(cwd, sizeof(cwd));
		printf("Directory : %s\n", cwd);
		//execl("/bin/sh", "/bin/sh", "-c", "pwd", (char *)0);
		printf("\n\n");
	}
	//e is for exiting the program
	else if (0 == strcmp(comm, "e")) {
		printf("Logging you out, Commander.\n");
		exit(EXIT_SUCCESS);
	}
	//
	//in this else, we run the child and parent threads
	else {
		//start the timer
		clock_t timey = clock();
		double time =((double)timey)/CLOCKS_PER_SEC;
	
		//fork it
		int childId = fork();
	
		//now if we are the child, we go through the options
		if (childId == 0) {
			//0 is for whoami
			if (0 == strcmp(comm, "0")) {
				printf("\n\n");
				printf("-- Who Am I? --\n");
				execl("/bin/sh", "/bin/sh", "-c", "whoami", (char *)0);
			}
			//1 is for last
			else if (0 == strcmp(comm, "1")) {
				printf("\n\n");
				printf("-- Last Logins --\n");
				execl("/bin/sh", "/bin/sh", "-c", "last", (char *)0);
			}
			//2 is for ls
			else if (0 == strcmp(comm, "2")) {
				printf("\n\n");
				printf("-- Directory Listing --\n");

				// starting to write a list of commands as a string
				char* command = (char*)malloc(128*sizeof(char*));
				strcpy(command, "ls");
				strcat(command, " ");

				// ask for the Arguments input and put it into a list of commands
				char* args = (char*)malloc(128*sizeof(char*));
				printf("Arguments?: ");
				fgets(args, 128, stdin);
				args = strtok(args, "\n");
				strcat(command, args);
				strcat(command, " ");

				// ask for the Path input and put it into a list of commands
				char* path = (char*)malloc(128*sizeof(char*));
				printf("Path?: ");
				fgets(path, 128, stdin);
				path = strtok(path, "\n");
				strcat(command, path);
				strcat(command, "\n");

				// execute the command
				execl("/bin/sh", "/bin/sh", "-c", command, (char *)0);
			}
			//we have the entered value, presumably one of our new commands
			else if (strtoimax(comm, &endptr, 0) > 2) {
				//get the inputVal
				int inputVal = strtoimax(comm, &endptr, 0);
				for (int i = 0; i < numElements; i++) {
					//now check the two
					if (i+3 == inputVal) {
						//store the userCommand locally, for convenience
						char* userCommand = (*newCs).input[i];
					
						printf("\n\n");
						printf("-- Command: %s --\n", userCommand);
					
						//run the user command
						execl("/bin/sh", "/bin/sh", "-c", userCommand, (char *)0);
					
						//we have our command, stop checking
						break;
					}
				}
			}
			//trash
			printf ("this is the default\n");
		
		
			return 1;
		}
		//otherwise, parent thread active
		else {
            struct rusage usage;
			//give the kid some time
			wait3(NULL, WNOHANG, &usage);
			//once the kid's done see how long he took
			clock_t timey1= clock();
			double time1 =((double)timey1)/CLOCKS_PER_SEC;
			double elapsed = (time1-time)*1000;		
		
			//then print the score
			printf("\n\n");
			printf("== Statistics ===\n");
			printf("Elapsed time: %f milliseconds\n", elapsed);
			//rusage gets page faults/reclaims
		
			getrusage(RUSAGE_SELF, &usage);
        		long pageFaults = usage.ru_majflt;
        		long pageReclaims = usage.ru_minflt;
        		printf("Page Faults: %ld\n", pageFaults);
        		printf("Page Faults (reclaimed): %ld\n", pageReclaims);
		
			printf("\n");
			return 1;

		}

	}
	return 1;
}

