#include <iostream>

using namespace std;

int main() {
    // Get the number of processes from the user
    int numProcesses;
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    // Create arrays to store process IDs and burst times
    int processes[numProcesses], burstTimes[numProcesses];

    // Get process IDs and burst times from the user
    cout << "Enter the process IDs and burst times:\n";
    for (int i = 0; i < numProcesses; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> processes[i] >> burstTimes[i];
    }

    // Calculate waiting times for each process
    int waitingTimes[numProcesses];
    waitingTimes[0] = 0;  // First process has no waiting time
    for (int i = 1; i < numProcesses; i++) {
        waitingTimes[i] = burstTimes[i - 1] + waitingTimes[i - 1];
    }

    // Calculate turnaround times for each process
    int turnaroundTimes[numProcesses];
    for (int i = 0; i < numProcesses; i++) {
        turnaroundTimes[i] = burstTimes[i] + waitingTimes[i];
    }

    // Print the results in a clear table format
    cout << "\nProcesses\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < numProcesses; i++) {
        cout << processes[i] << "\t\t" << burstTimes[i] << "\t\t" << waitingTimes[i] << "\t\t" << turnaroundTimes[i] << endl;
    }

    // Calculate average waiting and turnaround times
    float avgWaitingTime = 0, avgTurnaroundTime = 0;
    for (int i = 0; i < numProcesses; i++) {
        avgWaitingTime += waitingTimes[i];
        avgTurnaroundTime += turnaroundTimes[i];
    }
    avgWaitingTime /= numProcesses;
    avgTurnaroundTime /= numProcesses;

    // Print the average times
    cout << "\nAverage waiting time: " << avgWaitingTime << endl;
    cout << "Average turnaround time: " << avgTurnaroundTime << endl;

    return 0;
}
