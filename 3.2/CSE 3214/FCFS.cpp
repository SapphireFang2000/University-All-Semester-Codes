#include<bits/stdc++.h>
using namespace std;

int main()
{
    int numberOfProcess;
    cout << "Enter the Number of Process: ";
    cin >> numberOfProcess;

    int arrivalTimes[numberOfProcess], process[numberOfProcess], cpuTime[numberOfProcess], waitingTime[numberOfProcess]={0}, turnaroundTime[numberOfProcess];

    cout << "Enter the CPU Times: ";
    for(int i=0; i<numberOfProcess; i++)
    {
        process[i] = i+1;
        cin >> cpuTime[i];
    }

    cout << "Enter the Arrival Times: ";
    for(int i=0; i<numberOfProcess; i++)
    {
        cin >> arrivalTimes[i];
    }
    //sorting via arrival times
    for(int i=0; i<numberOfProcess-1; i++)
    {
        for(int j=0; j<numberOfProcess-1-i; j++)
        {
            if(arrivalTimes[j]>arrivalTimes[j+1])
            {
                swap(arrivalTimes[j],arrivalTimes[j+1]);
                swap(process[j],process[j+1]);
                swap(cpuTime[j],cpuTime[j+1]);
            }
        }
    }

    for(int i=0; i<numberOfProcess; i++)
    {
        for(int j=0; j<i; j++)
        {
            waitingTime[i]+=cpuTime[j];
        }

        waitingTime[i] = waitingTime[i]-arrivalTimes[i];
    }

    for(int i=0; i<numberOfProcess; i++)
    {
        turnaroundTime[i] = cpuTime[i]+waitingTime[i];
    }

    int value = 0;
    cout << endl << "Gantt Chart: " << value;
    for(int i=0; i<numberOfProcess; i++)
    {
        value += cpuTime[i];
        cout << "-----P" << process[i] << "-----" << value;
    }
    cout << endl;
    //Sorting via process number
    for(int i=0; i<numberOfProcess-1; i++)
    {
        for(int j=0; j<numberOfProcess-1-i; j++)
        {
            if(process[j]>process[j+1])
            {
                swap(process[j],process[j+1]);
                swap(arrivalTimes[j],arrivalTimes[j+1]);
                swap(cpuTime[j],cpuTime[j+1]);
                swap(waitingTime[j],waitingTime[j+1]);
                swap(turnaroundTime[j],turnaroundTime[j+1]);
            }
        }
    }

    for(int i=0; i<numberOfProcess; i++)
    {
        cout << "Process: " << process[i] << "=> Waiting Time: " << waitingTime[i] << "     Turnaround Time: " << turnaroundTime[i] << endl;
    }

    double averageWaitingTime=0, averageTurnaroundTime=0;
    for(int i=0; i<numberOfProcess; i++)
    {
        averageWaitingTime+=waitingTime[i];
        averageTurnaroundTime+=turnaroundTime[i];
    }

    cout << "Average Waiting Time= " << averageWaitingTime/numberOfProcess << endl;
    cout << "Average Turnaround Time= " << averageTurnaroundTime/numberOfProcess << endl;
}
