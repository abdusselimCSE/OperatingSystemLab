#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Process
{
    int id;
    vector<int> max_res;
    vector<int> allocated_res;
    vector<int> need_res;
    bool finished;
};

void calculateNeedRes(vector<Process> &all_process, int numberOfRes)
{
    for (int i = 0; i < all_process.size(); i++)
    {
        Process &each_process = all_process[i];

        each_process.need_res.resize(numberOfRes);

        for (int j = 0; j < numberOfRes; j++)
        {
            each_process.need_res[j] = each_process.max_res[j] - each_process.allocated_res[j];
        }
    }
}

bool isSystemInSafe(vector<Process> &total_process, vector<int> &available_res, int numberOfRes)
{
    vector<int> initial_available_res = available_res;

    vector<int> safeSequence;

    while (true)
    {
        bool found = false;

        for (int i = 0; i < total_process.size(); i++)
        {
            Process &process = total_process[i];

            if (!process.finished)
            {
                bool canExecute = true;
                for (int j = 0; j < numberOfRes; j++)
                {
                    if (process.need_res[j] > initial_available_res[j])
                    {
                        canExecute = false;
                        break;
                    }
                }
                if (canExecute)
                {
                    for (int j = 0; j < numberOfRes; j++)
                    {
                        initial_available_res[j] += process.allocated_res[j];
                    }
                    process.finished = true;
                    safeSequence.push_back(process.id);
                    found = true;
                }
            }
        }

        if (!found)
            break;
    }

    for (auto &process : total_process)
    {
        if (!process.finished)
            return false;
    }

    cout << "Safe sequence: ";
    for (int id : safeSequence)
    {
        cout << "P" << id << " ";
    }
    cout << endl;

    available_res = initial_available_res;
    return true;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int numberOfProcess, numberOfRes;

    cout << "Enter the number of processes and resources: ";
    cin >> numberOfProcess >> numberOfRes;

    vector<int> initial_available_res(numberOfRes);

    cout << "Enter available resources: ";
    for (int i = 0; i < numberOfRes; i++)
    {
        cin >> initial_available_res[i];
    }

    vector<Process> total_process(numberOfProcess);
    cout << "Enter the allocated resources matrix row by row:" << endl;

    for (int i = 0; i < numberOfProcess; i++)
    {
        total_process[i].id = i;
        total_process[i].allocated_res.resize(numberOfRes);
        total_process[i].max_res.resize(numberOfRes);
        total_process[i].finished = false;

        for (int j = 0; j < numberOfRes; j++) // Input allocated resources for process i
        {
            cin >> total_process[i].allocated_res[j];
        }
    }

    cout << "Enter the maximum resources matrix row by row:" << endl;

    for (int i = 0; i < numberOfProcess; i++)
    {
        for (int j = 0; j < numberOfRes; j++) // Input maximum resources for process i
        {
            cin >> total_process[i].max_res[j];
        }
    }

    calculateNeedRes(total_process, numberOfRes);

    if (isSystemInSafe(total_process, initial_available_res, numberOfRes))
    {
        cout << "It's SAFE" << endl;
    }
    else
    {
        cout << "Not SAFE" << endl;
    }

    cout << "Final Available Resources: ";
    for (int i = 0; i < numberOfRes; i++)
    {
        cout << initial_available_res[i] << " ";
    }
    cout << endl;

    return 0;
}
