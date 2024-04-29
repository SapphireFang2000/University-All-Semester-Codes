#include<bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;

struct Process{
    int processNo;
    int arrivalTime;
    int cpuTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;

    bool operator<(const Process & rhs) const{
        return cpuTime > rhs.cpuTime;
    }
};

bool compare(Process lhs, Process rhs){
    return lhs.arrivalTime < rhs.arrivalTime;
}

bool compare2(Process lhs, Process rhs){
    return lhs.processNo < rhs.processNo;
}

int main(){
    int n;
    cin >> n;
    Process p[n+1];
    for(int i = 0; i < n; i++)
        cin >> p[i].processNo >> p[i].arrivalTime >> p[i].cpuTime;
    sort(p, p+n, compare);
    priority_queue<Process> pq;
    vector<pair<int,int> > pr;
    pq.push(p[0]);

    int count = 1;
    int currentTime = 0;
    Process t;
    while(count < n){
        t = pq.top();
        pq.pop();
        t.cpuTime--;
        currentTime++;
        pr.push_back(make_pair(t.processNo, currentTime));
        if(t.cpuTime > 0) pq.push(t);
        for(int i = count; i < n; i++){
            if(p[i].arrivalTime <= currentTime){
                pq.push(p[i]);
                count++;
            }
        }
    }

    while(!pq.empty()){
        t = pq.top();
        currentTime += t.cpuTime;
        pr.push_back(make_pair(t.processNo, currentTime));
        pq.pop();
    }

    cout << "|";
    for(int i = 0; i < pr.size(); i++){
        cout << "--P" << pr[i].first << "---|";
    }

    cout << endl;

    cout << 0 << "\t";
    for(int i = 0; i < pr.size(); i++){
        cout << pr[i].second << "\t";
    }

    cout << endl;

    int totTAT = 0, totWT = 0;
    for(int i = pr.size(), j = 0; i >= 0 && j <= n; i--){
        if(pr[i].first == p[j].processNo){
            p[j].completionTime = pr[i].second;
            p[j].turnaroundTime = p[j].completionTime - p[j].arrivalTime;
            p[j].waitingTime = p[j].turnaroundTime - p[j].cpuTime;
            totTAT += p[j].turnaroundTime;
            totWT += p[j].waitingTime;
            j++;
            i = pr.size();
        }
    }

    sort(p, p+n, compare2);

	for(int i = 0; i < n; i++){
		cout << "Process: " << p[i].processNo << "=> Waiting Time: " << p[i].waitingTime << "     Turnaround Time: " << p[i].turnaroundTime << endl;
	}

    float avgTAT = (float) totTAT / n;
    float avgWT = (float) totWT / n;

    cout << "Average waiting Time: " << avgWT << endl;
    cout << "Average turnaround Time: " << avgTAT << endl;


    return 0;
}
