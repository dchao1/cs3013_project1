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
	printf("%f seconds", time);
	
	if (fork() ==0) {
		printf("i am child\n");
		execl("/bin/sh", "/bin/sh", "-c", "whoami", 0);
		printf("done being child\n");
	}
	else {
		wait();
		printf("i am parent\n");
		printf("child should be done\n");
	}
	
	//printf("%s", name);
	printf("safe");

	return(0);
}

