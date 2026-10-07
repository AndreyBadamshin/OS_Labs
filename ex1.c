#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main() {
    clock_t start;
	pid_t child1 = fork();
	if (child1 == 0) {
	    printf("Child process 1: ID: %d. Parent ID: %d.\n", getpid(), getppid());
	} else {
	    pid_t child2 = fork();
	    if (child2 == 0) {
	        printf("Child process 2: ID: %d. Parent ID: %d.\n", getpid(), getppid());
	    } else {
	        printf("Parent process: ID: %d. Parent ID: %d.\n", getpid(), getppid());
	    }
	}
	printf("Execution time of %d: %f\n", getpid(), ((float)(clock()))/CLOCKS_PER_SEC*1000);
}

