#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

int calculateTotalSeekTime(int *requests, int numRequests)
{
    int totalSeekTime = 0;
    int currentTrack = 0;
    int direction = 1;

    for (int i = 0; i < numRequests; i++)
    {
        while (currentTrack >= 0 && currentTrack <= 199)
        {
            if (requests[i] == currentTrack)
            {
                totalSeekTime += abs(currentTrack - requests[i]);
                requests[i] = -1;
                break;
            }
            currentTrack += direction;
            totalSeekTime++;
        }
        if (currentTrack == 200)
        {
            direction=-1;
            currentTrack=199;
        }
        else if(currentTrack == -1){
            direction = 1;
            currentTrack=0;
        }
    }
    return totalSeekTime;
}

int main(){
    int request[MAX_REQUESTS]= {82,170,43,140,24,16,190};
    int numRequests = 7;
    int totalSeekTime=calculateTotalSeekTime(request,numRequests);
    printf("the total seek time is : %d \n", totalSeekTime);
    return 0 ;
}