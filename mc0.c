#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <mc0.h>

int main() {
	// Introduce our program
	printf("===== Mid-Day Commander, v0 =====\n");
	printf("G'day, Commander! What command would you like to run?\n");
	printf("   0. whoami  : Prints out the result of the whoami command\n");
	printf("   1. last    : Prints out the result of the last command\n");
	printf("   2. ls      : Prints out the result of a listing on a user-specified path\n");
	
	//we create a character to hold what the user gives us
	char* comm = (char*)malloc(sizeof(char*));
	printf("Option?: ");
	scanf("%c", comm); //actually ask the user for the code
	
	//start the timer
	clock_t timey = clock();
	double time =((double)timey)/CLOCKS_PER_SEC;
	
	//now if we are the child, we go through the options
	if (fork() ==0) {
		//0 is for whoami
		if (0 == strcmp(comm, "0")) {
			printf("\n\n");
			printf("-- Who Am I? --\n");
			execl("/bin/sh", "/bin/sh", "-c", "whoami", 0);
		}
		//1 is for last
		if (0 == strcmp(comm, "1")) {
			printf("\n\n");
			printf("-- Last Logins --\n");
			printf("doesn't do shit yet\n");
		}
		//2 is for ls
		if (0 == strcmp(comm, "2")) {
			printf("\n\n");
			printf("-- Directory Listing --\n");
			printf("doesn't do shit yet\n");
		}

	}
	//otherwise, parent thread active
	else {
		//give the kid some time
		wait();
		
		//once the kid's done see how long he took
		clock_t timey1= clock();
		double time1 =((double)timey1)/CLOCKS_PER_SEC*1000;
		double elapsed = time1-time;		
		//then print the score
		printf("\n\n");
		printf("== Statistics ===\n");
		printf("Elapsed time: %f milliseconds\n ", elapsed);

		
		
	}
	//exit
	return(0);
}

