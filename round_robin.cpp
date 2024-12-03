#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct process
{
    int id;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnAroundTime;
};

void calculateRoundRobin(vector<process> &RRprocess, int tq)
{
    int n = RRprocess.size();
    int currTime = 0;
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        RRprocess[i].remainingTime = RRprocess[i].burstTime;
        q.push(i);
    }

    while (!q.empty())
    {
        int head = q.front();
        q.pop();

        if (RRprocess[head].remainingTime > tq)
        {
            currTime += tq;
            RRprocess[head].remainingTime -= tq;
            q.push(head);
        }
        else
        {
            currTime += RRprocess[head].remainingTime;
            RRprocess[head].remainingTime = 0;
            RRprocess[head].turnAroundTime = currTime;
            RRprocess[head].waitingTime = currTime - RRprocess[head].burstTime;
        }
    }
}

void printResults(const vector<process> &processes)
{
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    cout << "Process\tB-Time\tW-Time\tT-Time\n";
    for (const auto &process : processes)
    {
        cout << "P" << process.id << "\t" << process.burstTime << "\t"
             << process.waitingTime << "\t" << process.turnAroundTime << "\n";

        totalWaitingTime += process.waitingTime;
        totalTurnaroundTime += process.turnAroundTime;
    }

    cout << "\nAverage Waiting Time: " << (float)totalWaitingTime / processes.size();
    cout << "\nAverage Turnaround Time: " << (float)totalTurnaroundTime / processes.size() << "\n";
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n;
    cout << "Number of process: ";
    cin >> n;

    vector<process> processes(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Burst time for Process-" << i + 1 << ": ";
        processes[i].id = i + 1;
        cin >> processes[i].burstTime;
    }

    int tq;
    cout << "Enter the time quantum: ";
    cin >> tq;

    calculateRoundRobin(processes, tq);
    printResults(processes);

    return 0;
}