//
//  main.cpp
//  coccaro_exercise19
//
//  Created by Carly on 11/4/18.
//  Copyright © 2018 Carly. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int jobs[10][3] = {{1, 0, 16}, {2, 3, 2}, {3, 5, 11}, {4, 9, 6}, {5, 10, 1}, {6, 12, 9},
    {7, 14, 4}, {8, 16, 14}, {9, 17, 1}, {10, 19, 8}};

// Function to print the Letter name of each job
void jobName() {
    for(int x = 0; x < 10; x++) {
        switch (jobs[x][0]) {
            case 1:
                cout << "A" << setw(4);
                break;
            case 2:
                cout << "B" << setw(4);
                break;
            case 3:
                cout << "C" << setw(4);
                break;
            case 4:
                cout << "D" << setw(4);
                break;
            case 5:
                cout << "E" << setw(4);
                break;
            case 6:
                cout << "F" << setw(4);
                break;
            case 7:
                cout << "G" << setw(4);
                break;
            case 8:
                cout << "H" << setw(4);
                break;
            case 9:
                cout << "I" << setw(4);
                break;
            case 10:
                cout << "J" << setw(4);
                break;
            default:
                break;
        }
    }
}

/**
 * First Come First Serve Function
 **/
void fcfs() {
    // Calculate finish time for each job
    int fcfsFinishTime[10];
    fcfsFinishTime [0] = {16}; // Set first job finish time
    
    for (int i = 1; i < 10; i++) {
        fcfsFinishTime[i] = fcfsFinishTime[i - 1] + jobs[i][2];
    }
    
    // Calculate turnaround time for each job
    int fcfsTurnaround[10];
    
    for (int i = 0; i < 10; i++) {
        fcfsTurnaround[i] = fcfsFinishTime[i] - jobs[i][1];
    }
    cout << "\n\n*** FIRST COME FIRST SERVE ***\n";
    cout << "\nFCFS Turnaround Time for each job:\n";
    jobName();
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << left << fcfsTurnaround[i] << setw(4);
    }
    cout << right << endl;
    
    // Calculate wait time for each job
    int fcfsWaitTime[10];
    fcfsWaitTime[0] = 0;
    
    for (int i = 1; i < 10; i++) {
        fcfsWaitTime[i] = fcfsFinishTime[i-1] - jobs[i][1];
    }
    cout << "\nFCFS Wait Time for each job:\n";
    jobName();
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << left << fcfsWaitTime[i] << setw(4);
    }
    cout << endl;
    cout << endl;
    
    // Calculate Average Wait Time
    int avgWait = 0;
    for (int num : fcfsWaitTime) {
        avgWait = avgWait + num;
    }
    avgWait = avgWait / 10;
    
    cout << "FCFS Average Wait Time: " << avgWait << "\n";
    
    // Calculate Average Turnaround Time
    int avgTurn = 0;
    for (int num : fcfsTurnaround) {
        avgTurn = avgTurn + num;
    }
    avgTurn = avgTurn / 10;
    
    cout << "FCFS Average Turnaround Time: " << avgTurn << "\n";
}

/**
 * Shortest Job Next Function
 **/
void sjn() {
    // Copy of jobs array to reorganize for SJN job order
    int sjnJobs[10][3] = {{1, 0, 16}, {2, 3, 2}, {3, 5, 11}, {4, 9, 6}, {5, 10, 1}, {6, 12, 9},
        {7, 14, 4}, {8, 16, 14}, {9, 17, 1}, {10, 19, 8}};
    
    // Temporary variables for holding values
    int temp1a, temp1b, temp1c, temp2a, temp2b, temp2c;
    
    // Reorganize the job table based on CPU cycles (shortest ones next after the first job).
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            if (sjnJobs[j][2] > sjnJobs[i][2]) {
                temp1a = sjnJobs[j][0];
                temp1b = sjnJobs[j][1];
                temp1c = sjnJobs[j][2];
                temp2a = sjnJobs[i][0];
                temp2b = sjnJobs[i][1];
                temp2c = sjnJobs[i][2];
                sjnJobs[j][0] = temp2a;
                sjnJobs[j][1] = temp2b;
                sjnJobs[j][2] = temp2c;
                sjnJobs[i][0] = temp1a;
                sjnJobs[i][1] = temp1b;
                sjnJobs[i][2] = temp1c;
            }
        }
    }
    
//    // Print the jobs waiting array
//    cout << "Shortest Job Next Order:\n";
//    cout << "Job\t\tArrival\t\tCPU Cycle\n";
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j < 3; j++) {
//            cout << sjnJobs[i][j] << "\t\t\t";
//        }
//        cout << endl;
//    }
    
    // Calculate finish time for each job
    int sjnFinishTime[10];
    sjnFinishTime[0] = {16}; // Set first job finish time
    
    for (int i = 1; i < 10; i++) {
        sjnFinishTime[i] = sjnFinishTime[i - 1] + sjnJobs[i][2];
    }
    
    // Calculate turnaround time for each job
    int sjnTurnaround[10];
    
    for (int i = 0; i < 10; i++) {
        sjnTurnaround[i] = sjnFinishTime[i] - sjnJobs[i][1];
    }
    cout << "*** SHORTEST JOB NEXT ***\n";
    cout << right << "\nSJN Turnaround Time for each job:\n";
    jobName();
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << left << sjnTurnaround[i] << setw(4);
    }
    cout << right << endl;
    
    // Calculate wait time for each job
    int sjnWaitTime[10];
    sjnWaitTime[0] = 0;
    
    for (int i = 1; i < 10; i++) {
        sjnWaitTime[i] = sjnFinishTime[i-1] - sjnJobs[i][1];
    }
    cout << "\nSJN Wait Time for each job:\n";
    jobName();
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << left << sjnWaitTime[i] << setw(4);
    }
    cout << right << endl;
    cout << endl;
    
    // Calculate Average Wait Time
    int avgWait = 0;
    for (int num : sjnWaitTime) {
        avgWait = avgWait + num;
    }
    avgWait = avgWait / 10;
    
    cout << "SJN Average Wait Time: " << avgWait << "\n";
    
    // Calculate Average Turnaround Time
    int avgTurn = 0;
    for (int num : sjnTurnaround) {
        avgTurn = avgTurn + num;
    }
    avgTurn = avgTurn / 10;
    
    cout << "SJN Average Turnaround Time: " << avgTurn << "\n";
}

/**
 * Shortest Remaining Time Function
 **/
void srt() {
    
    // Develop algoritm
    
    
}

/**
 * Round Robin Function with 4ms Time Quantum
 **/
void rr() {
    int rrJobs[10][3] = {{1, 0, 16}, {2, 3, 2}, {3, 5, 11}, {4, 9, 6}, {5, 10, 1}, {6, 12, 9},
            {7, 14, 4}, {8, 16, 14}, {9, 17, 1}, {10, 19, 8}};
    int rrWaitTime[10];
    int time = 0;
    int rrFinishTime[10];
    int quantum = 4;
    bool notDone = true;
    
    // Calculate Finish Time and Wait Time
    while (notDone) { // While there is still time left in all jobs
        for (int i = 0; i < 10; i++) { // Loop through array of jobs
            if (rrJobs[i][2] > 0) { // If there is still time left in the job.
                notDone = false;
                if (rrJobs[i][2] > quantum) { // If the time left is greater than the quantum
                    time += quantum; // Increase time by quantum
                    rrJobs[i][2] -= quantum; // Decrease time in CPU cycle
                } else { // If the time left is less than the quantum
                    time = time + rrJobs[i][2]; // Increase the time by the job time remaining
                    rrFinishTime[i] = time; // Set the time finished for the job
                    rrWaitTime[i] = (quantum * rrJobs[i][0]) - rrJobs[i][1]; // Calculate the wait time (start time- arrival time)
                    rrJobs[i][2] = 0;
                }
            }
        }
        if (notDone == false) {
            break;
        }
    }
    
    // Calculate turnaround time for each job
    int rrTurnaround[10];
    
    for (int i = 0; i < 10; i++) {
        rrTurnaround[i] = rrFinishTime[i] - rrJobs[i][1];
    }
    cout << "*** ROUND ROBIN ***\n";
    cout << right << "\nRR Turnaround Time for each job:\n";
    jobName();
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << left << rrTurnaround[i] << setw(4);
    }
    cout << right << endl;
    
    // Calculate wait time for each job (calculated above)
    cout << "\nSJN Wait Time for each job:\n";
    jobName();
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << left << rrWaitTime[i] << setw(4);
    }
    cout << right << endl;
    cout << endl;
    
    // Calculate Average Wait Time
    int avgWait = 0;
    for (int num : rrWaitTime) {
        avgWait = avgWait + num;
    }
    avgWait = avgWait / 10;
    
    cout << "RR Average Wait Time: " << avgWait << "\n";
    
    // Calculate Average Turnaround Time
    int avgTurn = 0;
    for (int num : rrTurnaround) {
        avgTurn = avgTurn + num;
    }
    avgTurn = avgTurn / 10;
    
    cout << "RR Average Turnaround Time: " << avgTurn << "\n";
    
}

/**
 * Main Function
 **/
int main(int argc, const char * argv[]) {
    
    // Print the jobs waiting array
    cout << "Jobs Waiting to Be Processed:\n";
    cout << "Job\t\tArrival\t\tCPU Cycle\n";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            cout << jobs[i][j] << "\t\t\t";
        }
        cout << endl;
    }
  
    // Run First Come First Serve Function
    fcfs();
    cout << endl;
    cout << endl;
    
    // Run Shortest Job Next Function
    sjn();
    cout << endl;
    cout << endl;
    
    // Run Round Robin Function
    rr();
    cout << endl;
    cout << endl;
    
    return 0;
}




    

