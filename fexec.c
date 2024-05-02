#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
pid_t pid = fork();

if (pid == -1) {

    perror("fork failed");
    exit(EXIT_FAILURE);

} else if (pid == 0) {

// Child process
printf("Child process (PID %d): Executing ls -l\n", getpid());

char *args[]={"ls","-l",NULL};
execvp(args[0],args);

perror("execvp failed");
exit(1);
}

else {

// Parent process
printf("Parent process (PID %d): Waiting for child...\n", getpid());
wait(NULL); // Wait for the child process to finish
printf("Parent process: Child process completed.\n");
}

return 0;
}

