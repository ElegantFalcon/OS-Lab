#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

void main()
{
    
    printf("HELLO\n");
    fork();
    printf("WELCOME\n");
}
