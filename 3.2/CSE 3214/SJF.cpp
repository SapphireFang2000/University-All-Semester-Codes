#include<bits/stdc++.h>

using namespace std;

struct Process{
	int waitingTime;
	int arrivalTime;
	int cpuTime;
	int process;
	int turnaroundTime;
}arr[10];

bool cmp(Process a, Process b)
{
	return a.arrivalTime < b.arrivalTime;
}

bool cmp2(Process a, Process b)
{
	if(a.cpuTime == b.cpuTime){
		return a.arrivalTime < b.arrivalTime;
	}
	else{
		return a.cpuTime < b.cpuTime;
	}
}

bool cmp3(Process a, Process b)
{
	return a.process < b.process;
}

int main()
{
	int n, currentTime = 0;
    cout << "Enter the Number of Process: ";
    cin >> n;

	vector<int> vec;

	cout << "Enter the CPU Times: ";
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		arr[i].cpuTime = x;
		arr[i].process = i + 1;
	}

    cout << "Enter the Arrival Times: ";
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		arr[i].arrivalTime = x;
	}
    cout << endl;

	sort(arr, arr + n, cmp);

    cout << "Gentt Chart: " << currentTime;
	currentTime += arr[0].cpuTime;
    cout << "-----P" << arr[0].process << "-----" << currentTime;

	arr[0].waitingTime = 0;
	arr[0].turnaroundTime = arr[0].cpuTime;

	sort(arr + 1, arr + n, cmp2);

	for(int i = 1; i < n;){
		if(arr[i].arrivalTime <= currentTime){
			arr[i].waitingTime = currentTime - arr[i].arrivalTime;
			arr[i].turnaroundTime = arr[i].waitingTime + arr[i].cpuTime;
			currentTime += arr[i].cpuTime;
            cout << "-----P" << arr[i].process << "-----" << currentTime;
			i++;
		}
		else{
			currentTime++;
		}
	}
    cout << endl;

    sort(arr, arr + n, cmp3);

	for(int i = 0; i < n; i++){
		cout << "Process: " << arr[i].process << "=> Waiting Time: " << arr[i].waitingTime << "     Turnaround Time: " << arr[i].turnaroundTime << endl;
	}

    double averageWaitingTime=0, averageTurnaroundTime=0;
    for(int i=0; i<n; i++)
    {
        averageWaitingTime+=arr[i].waitingTime;
        averageTurnaroundTime+=arr[i].turnaroundTime;
    }

    cout << "Average Waiting Time= " << averageWaitingTime/n << endl;
    cout << "Average Turnaround Time= " << averageTurnaroundTime/n << endl;

	return 0;
}
