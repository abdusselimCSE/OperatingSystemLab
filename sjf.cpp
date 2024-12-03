#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Process
{
    int pid;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

void findSJF(vector<Process> &proc)
{
    int n = proc.size();
    vector<int> remainingTime(n);

    // Initialize remaining burst times
    for (int i = 0; i < n; i++)
    {
        remainingTime[i] = proc[i].burstTime;
    }

    int currentTime = 0;
    int complete = 0;
    int shortest = 0;
    int minBurst = INT_MAX;

    while (complete < n)
    {
        minBurst = INT_MAX;

        // Find the process with the shortest remaining burst time
        for (int i = 0; i < n; i++)
        {
            if (proc[i].arrivalTime <= currentTime && remainingTime[i] < minBurst && remainingTime[i] > 0)
            {
                minBurst = remainingTime[i];
                shortest = i;
            }
        }

        remainingTime[shortest]--;

        if (remainingTime[shortest] == 0)
        {
            complete++;
            proc[shortest].completionTime = currentTime + 1;
            proc[shortest].turnaroundTime = proc[shortest].completionTime - proc[shortest].arrivalTime;
            proc[shortest].waitingTime = proc[shortest].turnaroundTime - proc[shortest].burstTime;
        }

        currentTime++;
    }
}

void displayProcessDetails(const vector<Process> &proc)
{
    cout << "Process\tArrivalTime\tBurstTime\tCompletionTime\tTurnaroundTime\tWaitingTime" << endl;

    for (const auto &p : proc)
    {
        cout << p.pid << "\t\t" << p.arrivalTime << "\t\t" << p.burstTime << "\t\t"
             << p.completionTime << "\t\t" << p.turnaroundTime << "\t\t" << p.waitingTime << endl;
    }
    cout << endl;
}

void calculateAverageWaitingTime(const vector<Process> &proc)
{
    double totalWaitingTime = 0;

    for (const auto &p : proc)
    {
        totalWaitingTime += p.waitingTime;
    }

    double averageWaitingTime = totalWaitingTime / proc.size();
    cout << "Average Waiting Time: " << fixed << setprecision(2) << averageWaitingTime << endl;
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
        cin >> proc[i].arrivalTime >> proc[i].burstTime;
    }

    findSJF(proc);
    displayProcessDetails(proc);
    calculateAverageWaitingTime(proc);

    return 0;
}
