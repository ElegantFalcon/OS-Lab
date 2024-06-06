#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

int calculateTotalSeekTime(int *requests, int numRequests)
{
    int totalSeekTime = 0;
    int currentTrack = 0;

    for (int i = 0; i < numRequests; i++)
    {
        int seekTime = abs(currentTrack - requests[i]);
        currentTrack = requests[i];
        totalSeekTime += seekTime;
    }

    return totalSeekTime;
}

int main()
{
    int requests[MAX_REQUESTS] = {82, 170, 43, 140, 24, 16, 190};
    int numRequests = 7;
    int tst = calculateTotalSeekTime(requests, numRequests);
    printf("Total seek time using FCFS: %d\n", tst);
}