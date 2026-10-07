#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    char buf[10];
    while (true) {
        fgets(buf, 10, stdin);
        buf[strcspn(buf, "\n")] = '\0';
        pid_t pid = fork();
        if (pid == 0) {
            char *args[2];
            args[0] = buf;
            args[1] = NULL;
            execvp(args[0], args);
        } else {
            waitpid(pid, NULL, 0);
        }
    }
}
