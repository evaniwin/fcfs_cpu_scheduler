#include <stdio.h>
#include <stdlib.h>

struct proc {
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
};
void fcfs(void);

static int proc_no = 0;
static struct proc *processes = NULL;
static int *map = NULL;

int main(void)
{
	scanf("%d", &proc_no);
	if(proc_no<1){
		printf("Enter a positive intiger as input.\n");
		return -1;
	}
	processes = (struct proc *)malloc(sizeof(struct proc) * (unsigned long)proc_no);
	if (processes == NULL) {
		perror("Failed to allocate Memory");
		return -1;
	}
	map = (int *)malloc(sizeof(int) * (unsigned long)proc_no);
	if (map == NULL) {
		perror("Failed to allocate Memory");
		free(processes);
		return -1;
	}
	for (int i = 0; i < proc_no; i++) {
		printf("P%d  ", i+1);
		scanf("%d %d", &processes[i].at, &processes[i].bt);
		map[i] = i;
	}
	fcfs();

	int sum_tat = 0;
	int sum_wt = 0;

	printf("\nWaiting Time:\n");
	for (int i = 0; i < proc_no; i++) {
		sum_wt = sum_wt + processes[i].wt;
		printf("P%d  %d\n", i+1, processes[i].wt);
	}

	printf("\nTurnaround Time:\n");
	for (int i = 0; i < proc_no; i++) {
		sum_tat = sum_tat + processes[i].tat;
		printf("P%d  %d\n", i+1, processes[i].tat);
	}
	float avg_tat = (float)sum_tat / (float)proc_no;
	float avg_wt = (float)sum_wt / (float)proc_no;

	printf("\nAverage Waiting Time: %.2f\n", (double)avg_wt);
	printf("Average Turnaround Time: %.2f\n", (double)avg_tat);

	free(map);
	free(processes);
	return 0;
}
static int sort(const void *a, const void *b)
{
	const int int_a = (*((const int *)a));
	const int int_b = (*((const int *)b));
	int diff = processes[int_a].at - processes[int_b].at;
	if(diff == 0){
		diff = int_a - int_b;
	}
	return diff;
}
void fcfs(void)
{
	int time = 0;
	qsort(map, (unsigned long)proc_no, sizeof(int), sort);
	for (int i = 0; i < proc_no; i++) {
		struct proc *procs = &processes[map[i]];
		if (time > procs->at) {
			time = time + procs->bt;
		} else {
			time = procs->at + procs->bt;
		}
		procs->ct = time;
		procs->tat = procs->ct - procs->at;
		procs->wt = procs->tat - procs->bt;
	}
}
