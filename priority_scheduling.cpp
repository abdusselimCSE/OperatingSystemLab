#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Process
{
    int id;
    int burstTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
};

bool comparePriority(Process a, Process b)
{
    return a.priority < b.priority;
}

void calculateWaitingTime(vector<Process> &processes)
{
    processes[0].waitingTime = 0;

    for (int i = 1; i < processes.size(); i++)
    {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
    }
}

void calculateTurnaroundTime(vector<Process> &processes)
{
    for (int i = 0; i < processes.size(); i++)
    {
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

void printResults(vector<Process> &processes, int n)
{
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    cout << "Process\tB-Time\tPrt\tW-Time\tT-Time\n";
    for (const auto &process : processes)
    {
        cout << "P" << process.id << "\t" << process.burstTime << "\t"
             << process.priority << "\t" << process.waitingTime << "\t"
             << process.turnaroundTime << "\n";

        totalWaitingTime += process.waitingTime;
        totalTurnaroundTime += process.turnaroundTime;
    }

    cout << "\nAverage Waiting Time: " << (float)totalWaitingTime / processes.size();
    cout << "\nAverage Turnaround Time: " << (float)totalTurnaroundTime / n << "\n";
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n;
    cout << "Number of process: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter burst time and priority " << i + 1 << ": ";
        processes[i].id = i + 1;
        cin >> processes[i].burstTime >> processes[i].priority;
    }

    sort(processes.begin(), processes.end(), comparePriority);

    calculateWaitingTime(processes);
    calculateTurnaroundTime(processes);

    printResults(processes, n);

    return 0;
}
