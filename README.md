# FCFS CPU Scheduling

This project simulates the **First Come First Serve (FCFS)** CPU scheduling algorithm. It calculates the Waiting Time (WT) and Turnaround Time (TAT) for a set of processes based on their Arrival Time (AT) and Burst Time (BT).

### This project is build using make

> [!WARNING]
> The make Build Utility must be manually installed in windows.

Build the project with
``` bash
make all
```

Run the project with
``` bash
make run
```

Clean old build files with 
``` bash
make clean
```

### Test Case

**Input Format**
The input consists of the number of processes n, followed by n lines containing the Process ID (PID), Arrival Time (AT), and Burst Time (BT).

**Sample Input**
``` text
5
P1 0 4
P2 1 5
P3 2 1
P4 3 2
P5 10 3
```

**Sample Output**
``` text
Waiting Time:
P1 0
P2 3
P3 7
P4 8
P5 0

Turnaround Time:
P1 4
P2 8
P3 8
P4 10
P5 3

Average Waiting Time: 3.60
Average Turnaround Time: 6.60
```