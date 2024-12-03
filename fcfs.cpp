#include <iostream>
using namespace std;

struct Process
{
    int pid;             // process id
    int arrival_time;    // arrival time
    int burst_time;      // burst time
    int completion_time; // completion time
    int turnaround_time; // turnaround time
    int waiting_time;    // waiting time
};

void findWaitingTime(Process proc[], int n)
{
    // waiting time for first process is 0
    proc[0].waiting_time = 0;

    // calculate waiting time for each process
    for (int i = 1; i < n; i++)
    {
        proc[i].waiting_time = proc[i].turnaround_time - proc[i].burst_time;
        if (proc[i].waiting_time < 0)
        {
            proc[i].waiting_time = 0;
        }
    }
}

void findTurnaroundTime(Process proc[], int n)
{
    // calculate turnaround time for each process
    for (int i = 0; i < n; i++)
    {
        proc[i].turnaround_time = proc[i].completion_time - proc[i].arrival_time;
    }
}

void findCompletionTime(Process proc[], int n)
{
    // calculate completion time for each process
    proc[0].completion_time = proc[0].burst_time;

    for (int i = 1; i < n; i++)
    {
        proc[i].completion_time = proc[i - 1].completion_time + proc[i].burst_time;
    }
}

void findFCFS(Process proc[], int n)
{
    // calculate waiting time, turnaround time, and completion time
    findCompletionTime(proc, n);
    findTurnaroundTime(proc, n);
    findWaitingTime(proc, n);
}

void printFCFS(Process proc[], int n)
{
    cout << "FCFS Scheduling:" << endl;
    cout << "PID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround "
            "Time\tWaiting Time"
         << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "P"<<proc[i].pid << "\t" << proc[i].arrival_time << "\t\t"
             << proc[i].burst_time << "\t\t" << proc[i].completion_time << "\t\t"
             << proc[i].turnaround_time << "\t\t" << proc[i].waiting_time << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process proc[n];

    for (int i = 0; i < n; i++)
    {
        proc[i].pid = i + 1;
        cout << "Enter arrival time and burst time for process " << proc[i].pid << ": ";
        cin >> proc[i].arrival_time >> proc[i].burst_time;
    }

    findFCFS(proc, n);
    printFCFS(proc, n);

    return 0;
}
