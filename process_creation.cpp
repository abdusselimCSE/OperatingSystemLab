#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pid_t pid = fork();
    cout << "Initial id : " << pid << endl;
    if (pid < 0)
    {
        cout << "Fork invalid" << endl;
    }
    else if (pid == 0)
    {
        cout << "It's child process: " << getpid() << " Parent process of " << getpid() << " is " << getppid() << endl;
    }
    else
        cout << "It's parent process: " << getpid() << endl;

    return 0;
}