#include <stdio.h>
#include <time.h>
//#include <mc0.h>

int main() {
	// call a function in another file
	printf("===== Mid-Day Commander, v0 =====\n");
	printf("G'day, Commander! What command would you like to run?\n");
	printf("   0. whoami  : Prints out the result of the whoami command\n");
	printf("   1. last    : Prints out the result of the last command\n");
	printf("   2. ls      : Prints out the result of a listing on a user-specified path\n");
	
	char* name = (char*) malloc(sizeof(char*));
	printf("Option?: ");
	scanf("%c", &name);
	if (&name == "0") {
		printf("\nwhat\n");
	}
	//printf("%s", name);
	
	clock_t timey = clock();
	double time_taken = ((double)timey)/CLOCKS_PER_SEC; // in seconds 
	printf("%f seconds\n",time_taken);

	//system calls
	

	return(0);
}

