#include <iostream>

using namespace std;

int main() {
    int numProcesses;
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    int processes[numProcesses], burstTimes[numProcesses], priorities[numProcesses];

    cout << "Enter the process IDs, burst times, and priorities (separated by spaces):\n";
    for (int i = 0; i < numProcesses; i++) {
        cin >> processes[i] >> burstTimes[i] >> priorities[i];
    }

    // Sort processes based on priority (higher priority first)
    for (int i = 0; i < numProcesses - 1; i++) {
        for (int j = 0; j < numProcesses - i - 1; j++) {
            if (priorities[j] > priorities[j + 1]) {
                swap(processes[j], processes[j + 1]);
                swap(burstTimes[j], burstTimes[j + 1]);
                swap(priorities[j], priorities[j + 1]);
            }
        }
    }

    // Calculate waiting and turnaround times
    int waitingTimes[numProcesses], turnaroundTimes[numProcesses];
    waitingTimes[0] = 0;  // First process has no waiting time
    for (int i = 1; i < numProcesses; i++) {
        waitingTimes[i] = burstTimes[i - 1] + waitingTimes[i - 1];
    }
    for (int i = 0; i < numProcesses; i++) {
        turnaroundTimes[i] = burstTimes[i] + waitingTimes[i];
    }

    // Print the results
    cout << "\nProcesses\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < numProcesses; i++) {
        cout << processes[i] << "\t\t" << burstTimes[i] << "\t\t"
             << priorities[i] << "\t\t" << waitingTimes[i] << "\t\t" << turnaroundTimes[i] << endl;
    }

    // Calculate average waiting and turnaround times
    float avgWaitingTime = 0, avgTurnaroundTime = 0;
    for (int i = 0; i < numProcesses; i++) {
        avgWaitingTime += waitingTimes[i];
        avgTurnaroundTime += turnaroundTimes[i];
    }
    avgWaitingTime /= numProcesses;
    avgTurnaroundTime /= numProcesses;

    cout << "\nAverage waiting time: " << avgWaitingTime << endl;
    cout << "Average turnaround time: " << avgTurnaroundTime << endl;

    return 0;
}
