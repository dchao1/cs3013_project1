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
//#include <mc0.h>

int main() {
	
	while (1) {
		midDayComm();
	}
	
	//exit
	return(0);


}

int midDayComm() {
	
	// Introduce our program
	printf("===== Mid-Day Commander, v0 =====\n");
	printf("G'day, Commander! What command would you like to run?\n");
	printf("   0. whoami  : Prints out the result of the whoami command\n");
	printf("   1. last    : Prints out the result of the last command\n");
	printf("   2. ls      : Prints out the result of a listing on a user-specified path\n");
	
	//we create a character to hold what the user gives us

	char* comm = (char*)malloc(128*sizeof(char*));
	printf("Option?: ");
	fgets(comm, 128, stdin);
	//printf(comm);
	comm = strtok(comm, "\n");
	//printf(comm2);
	//scanf("%c", comm); //actually ask the user for the code
	
	//start the timer
	clock_t timey = clock();
	double time =((double)timey)/CLOCKS_PER_SEC;

	//struct rusage usage;
	
	//fork it
	int childId = fork();
	
	//now if we are the child, we go through the options
	if (childId == 0) {
		//0 is for whoami
		if (0 == strcmp(comm, "0")) {
			printf("\n\n");
			printf("-- Who Am I? --\n");
			execl("/bin/sh", "/bin/sh", "-c", "whoami", 0);
		}
		//1 is for last
		else if (0 == strcmp(comm, "1")) {
			printf("\n\n");
			printf("-- Last Logins --\n");
			execl("/bin/sh", "/bin/sh", "-c", "last", 0);
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
			execl("/bin/sh", "/bin/sh", "-c", command, 0);
		}
		else {
			printf ("this is the default\n");
		}
		
		return 1;
	}
	//otherwise, parent thread active
	else {
		//give the kid some time
		wait(NULL);
		//once the kid's done see how long he took
		clock_t timey1= clock();
		double time1 =((double)timey1)/CLOCKS_PER_SEC*1000;
		double elapsed = time1-time;		
		
		//then print the score
		printf("\n\n");
		printf("== Statistics ===\n");
		printf("Elapsed time: %f milliseconds\n ", elapsed);
		//rusage gets page faults/reclaims
		
		struct rusage usage;
		getrusage(RUSAGE_SELF, &usage);
        	long pageFaults = usage.ru_majflt;
        	long pageReclaims = usage.ru_minflt;
        	printf("%ld page faults\n", pageFaults);
        	printf("%ld page reclaims\n", pageReclaims);
		
		printf("\n");
		return 1;

	}
	return 1;
}

