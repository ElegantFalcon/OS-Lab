#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    pid_t pid =fork();

    if(pid == -1){
        perror("Fork Failed");
        exit(EXIT_FAILURE);
    }

    else if(pid==0){
        printf("Child process (PID %d): Executing ls -l\n",getpid());
        
        char *args[] = {"ls","-l",NULL};
        execvp(args[0],args);

        perror("execvp failed");
        exit(EXIT_FAILURE);
    }

    else{

        printf("Parent process (PID %d): Waiting for child process ...\n",getpid());
        wait(NULL);
        printf("Parent process: Child process completed.\n");

    }

    return 0 ;

}