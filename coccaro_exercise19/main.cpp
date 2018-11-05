//
//  main.cpp
//  coccaro_exercise19
//
//  Created by Carly on 11/4/18.
//  Copyright © 2018 Carly. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

int jobs[10][3] = {{1, 0, 16}, {2, 3, 2}, {3, 5, 11}, {4, 9, 6}, {5, 10, 1}, {6, 12, 9},
    {7, 14, 4}, {8, 16, 14}, {9, 17, 1}, {10, 19, 8}};

// Function to print the Letter name of each job
void jobName() {
    for(int x = 0; x < 10; x++) {
        switch (jobs[x][0]) {
            case 1:
                cout << "A   ";
                break;
            case 2:
                cout << "B   ";
                break;
            case 3:
                cout << "C   ";
                break;
            case 4:
                cout << "D   ";
                break;
            case 5:
                cout << "E   ";
                break;
            case 6:
                cout << "F   ";
                break;
            case 7:
                cout << "G   ";
                break;
            case 8:
                cout << "H   ";
                break;
            case 9:
                cout << "I   ";
                break;
            case 10:
                cout << "J\n";
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
    // First Come First Serve
    cout << "First Come First Serve\n";
    
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
    cout << "\nFCFS Turnaround Time for each job:\n";
    jobName();
    for (int i = 0; i < 10; i++) {
        cout << fcfsTurnaround[i] << "  ";
    }
    cout << endl;
    
    // Calculate wait time for each job
    int fcfsWaitTime[10];
    fcfsWaitTime[0] = 0;
    
    for (int i = 1; i < 10; i++) {
        fcfsWaitTime[i] = fcfsFinishTime[i-1] - jobs[i][1];
    }
    cout << "\nFCFS Wait Time for each job:\n";
    jobName();
    for (int i = 0; i < 10; i++) {
        cout << fcfsWaitTime[i] << "  ";
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
    
    int temp1, temp2;
    
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            if (jobs[j+1] < jobs[j]) {
                temp1 = jobs [j][1];
                temp2 = jobs [j][0];
                jobs[j][1] = jobs[j + 1][1];
                jobs[j][0] = jobs[j + 1][0];
                jobs[j + 1][1] = temp1;
                jobs[j + 1][0] = temp2;
            }
        }
    }
    
    // Print the jobs waiting array
    cout << "Job's waiting to be processed:\n\n";
    cout << "Job\t\tArrival\t\tCPU Cycle\n";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            cout << jobs[i][j] << "\t\t\t";
        }
        cout << endl;
    }
    cout << endl;
    

}


/**
 * Main Function
 **/
int main(int argc, const char * argv[]) {
    
    // Print the jobs waiting array
    cout << "Job's waiting to be processed:\n\n";
    cout << "Job\t\tArrival\t\tCPU Cycle\n";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 3; j++) {
            cout << jobs[i][j] << "\t\t\t";
        }
        cout << endl;
    }
    cout << endl;
    
    // Run First Come First Serve Function
    fcfs();
    cout << endl;
    sjn();
    cout << endl;
    return 0;
}




    

