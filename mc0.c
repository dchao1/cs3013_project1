#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <mc0.h>

int main() {
	// call a function in another file
	printf("===== Mid-Day Commander, v0 =====\n");
	printf("G'day, Commander! What command would you like to run?\n");
	printf("   0. whoami  : Prints out the result of the whoami command\n");
	printf("   1. last    : Prints out the result of the last command\n");
	printf("   2. ls      : Prints out the result of a listing on a user-specified path\n");
	
	char* comm = (char*) malloc(sizeof(char*));
	printf("Option?: ");
	scanf("%c", comm);
	printf(comm);
	
	clock_t timey = clock();
	double time =((double)timey)/CLOCKS_PER_SEC;
	
	if (fork() ==0) {
		printf("i am child\n");
		execl("/bin/sh", "/bin/sh", "-c", "whoami", 0);
		printf("done being child\n");
	}
	else {
		wait();
		
		clock_t timey1= clock();
		double time1 =((double)timey1)/CLOCKS_PER_SEC*1000;
		double elapsed = time1-time;		
		printf("\n\n");
		printf("== Statistics ===\n");
		printf("Elapsed time: %f milliseconds\n ", elapsed);

		
		printf("i am parent\n");
		printf("child should be done\n");
	}

	return(0);
}

