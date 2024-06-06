#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>


int main()
{
    pid_t p = fork();

    if (p < 0)
    {
        perror("Fork failed");
    }

    else if (p == 0)
    {
        printf("Hello from child!(PID: %d)\n", getpid());
    }
    else
    {
        printf("Hello from Parent!(PID: %d)\n", getpid());
    }
    return 0;
}