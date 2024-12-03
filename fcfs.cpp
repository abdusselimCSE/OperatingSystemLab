#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Process
{
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

void findWaitingTime(vector<Process> &proc)
{
    // waiting time for first process is 0
    proc[0].waiting_time = 0;

    for (size_t i = 1; i < proc.size(); i++)
    {
        proc[i].waiting_time = proc[i].turnaround_time - proc[i].burst_time;
        if (proc[i].waiting_time < 0)
        {
            proc[i].waiting_time = 0;
        }
    }
}

void findTurnaroundTime(vector<Process> &proc)
{
    for (auto &p : proc)
    {
        p.turnaround_time = p.completion_time - p.arrival_time;
    }
}

void findCompletionTime(vector<Process> &proc)
{
    proc[0].completion_time = proc[0].arrival_time + proc[0].burst_time;

    for (size_t i = 1; i < proc.size(); i++)
    {
        proc[i].completion_time = max(proc[i - 1].completion_time, proc[i].arrival_time) + proc[i].burst_time;
    }
}

void findFCFS(vector<Process> &proc)
{
    findCompletionTime(proc);
    findTurnaroundTime(proc);
    findWaitingTime(proc);
}

void printFCFS(const vector<Process> &proc)
{
    cout << "FCFS Scheduling:" << endl;
    cout << "PID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time" << endl;

    for (const auto &p : proc)
    {
        cout << "P" << p.pid << "\t" << p.arrival_time << "\t\t"
             << p.burst_time << "\t\t" << p.completion_time << "\t\t"
             << p.turnaround_time << "\t\t" << p.waiting_time << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> proc(n);

    for (int i = 0; i < n; i++)
    {
        proc[i].pid = i + 1;
        cout << "Enter arrival time and burst time for process P" << proc[i].pid << ": ";
        cin >> proc[i].arrival_time >> proc[i].burst_time;
    }

    findFCFS(proc);
    printFCFS(proc);

    return 0;
}
