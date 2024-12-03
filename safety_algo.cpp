#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Process
{
    int id;
    vector<int> max;
    vector<int> allocation;
    vector<int> need;
    bool finished;
};

void calculateNeed(vector<Process> &processes, int m)
{
    for (auto &process : processes)
    {
        process.need.resize(m);
        for (int j = 0; j < m; j++)
        {
            process.need[j] = process.max[j] - process.allocation[j];
        }
    }
}

bool isSafe(vector<Process> &processes, vector<int> &available, int m)
{
    vector<int> work = available;
    vector<bool> finish(processes.size(), false);

    vector<int> safeSequence;

    while (true)
    {
        bool found = false;
        for (int i = 0; i < processes.size(); i++)
        {
            Process &process = processes[i];
            if (!process.finished)
            {
                bool canProceed = true;
                for (int j = 0; j < m; j++)
                {
                    if (process.need[j] > work[j])
                    {
                        canProceed = false;
                        break;
                    }
                }

                if (canProceed)
                {
                    for (int j = 0; j < m; j++)
                        work[j] += process.allocation[j];

                    process.finished = true;
                    safeSequence.push_back(process.id + 1);
                    found = true;
                }
            }
        }

        if (!found)
            break;
    }

    for (const auto &process : processes)
    {
        if (!process.finished)
            return false;
    }

    cout << "Safe Sequence: ";
    for (int id : safeSequence)
        cout << "P" << id << " ";
    cout << endl;

    available = work;

    return true;
}

int main()
{
    int n, m;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    vector<int> available(m);
    cout << "Enter available resources: ";
    for (int i = 0; i < m; i++)
        cin >> available[i];

    vector<Process> processes(n);
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i;
        processes[i].max.resize(m);
        processes[i].allocation.resize(m);
        processes[i].finished = false;

        cout << "Enter max resources for Process P" << i << ": ";
        for (int j = 0; j < m; j++)
            cin >> processes[i].max[j];

        cout << "Enter allocated resources for Process P" << i << ": ";
        for (int j = 0; j < m; j++)
            cin >> processes[i].allocation[j];
    }

    calculateNeed(processes, m);

    if (isSafe(processes, available, m))
    {
        cout << "##################################\n";
        cout << "The system is in a SAFE state.\n";
    }
    else
    {
        cout << "##################################\n";

        cout << "The system is in an UNSAFE state.\n";
    }

    cout << "##################################\n";
    cout << "Final Available Resources: ";
    for (int i = 0; i < m; i++)
    {
        cout << available[i] << " ";
    }
    cout << endl;

    return 0;
}
