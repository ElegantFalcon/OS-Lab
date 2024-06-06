#include <stdio.h>

struct Process
{
    int processNo;
    int arrivalTime;
    int burstTime;
    int priority;
};

void sortProcesses(struct Process proc[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (proc[j].arrivalTime < proc[i].arrivalTime || proc[j].arrivalTime == proc[i].arrivalTime && proc[j].priority < proc[i].priority)
            {
                struct Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

void calculateWaitingTime(struct Process proc[], int wt[], int n)
{
    wt[0] = 0;
    int pstart[n];
    pstart[0] = 0;
    for (int i = 1; i < n; i++)
    {
        pstart[i] = pstart[i - 1] + proc[i - 1].burstTime;
        wt[i] = pstart[i] - proc[i].arrivalTime;
    }
}

void calculateTurnaroundTime(struct Process proc[], int wt[], int tat[], int n)
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = proc[i].burstTime + wt[i];
    }
}

int main()
{
    int n = 5;
    int wt[n], tat[n];
    struct Process proc[] = {{1, 0, 4, 1}, {2, 0, 3, 2}, {3, 6, 7, 1}, {4, 11, 2, 2}, {5, 12, 4, 3}};

    sortProcesses(proc, n);
    calculateWaitingTime(proc, wt, n);
    calculateTurnaroundTime(proc, wt, tat, n);

    // Display results
    float awt = 0, atat = 0;
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].processNo, proc[i].arrivalTime,
               proc[i].burstTime, proc[i].priority, wt[i], tat[i]);
        awt = awt + wt[i];
        atat = atat + tat[i];
    }
    printf("AWT=%f\t ATAT=%f", awt / n, atat / n);
    return 0;
}