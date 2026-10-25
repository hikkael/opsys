#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int response_time; 
} Process;


void arrival_sort(Process *p , int size){
    for (int i = 0; i < size-1; i++)
    {
        for(int j = i+1 ; j<size;j++){
            if(p[i].arrival_time>p[j].arrival_time){
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}





void print_gnatt(Process *p , int size){

    printf("Gantt Chart: ");
    for (int i = 0; i < size; i++) {
        printf("| P%d ", p[i].pid);
    }
    printf("|\n");

    printf("PID\tAT\tBT\tWT\tTAT\tRT\n");
    float total_wt = 0, total_tat = 0, total_rt = 0;

    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", 
               p[i].pid, 
               p[i].arrival_time, 
               p[i].burst_time, 
               p[i].waiting_time, 
               p[i].turnaround_time, 
               p[i].response_time);

        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
        total_rt += p[i].response_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / size);
    printf("Average Turnaround Time: %.2f\n", total_tat / size);
    printf("Average Response Time: %.2f\n", total_rt / size);
}


void fcfs(Process *p , int size){

    int CT = 0;
    int current_time = 0;
    for(int i=0;i<size; i++){
        if(current_time <= p[i].arrival_time){
        current_time = p[i].arrival_time;
        }
        CT = current_time + p[i].burst_time;
        current_time = CT; 
        p[i].turnaround_time = CT - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        p[i].response_time = p[i].waiting_time;
    }

    printf("\n=== First Come First Served (FCFS) ===\n");
    print_gnatt(p , size);
}


void sjf(Process *p, int size) {
    int current_time = 0;

    for (int i = 0; i < size; i++) {

        if (current_time < p[i].arrival_time) {
            current_time = p[i].arrival_time;
        }

        int min_id = i;
        for (int j = i + 1; j < size; j++) {
            if (p[j].arrival_time <= current_time) {
                if (p[j].burst_time < p[min_id].burst_time) {
                    min_id = j;
                }
                else if (p[j].burst_time == p[min_id].burst_time) {
                    if (p[j].arrival_time < p[min_id].arrival_time) {
                        min_id = j;
                    }
                }
            }
        }

        if (min_id!= i) {
            Process temp = p[i];
            p[i] = p[min_id];
            p[min_id] = temp;
        }

        int CT = current_time + p[i].burst_time;
        current_time = CT;

        p[i].turnaround_time = CT - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        p[i].response_time = p[i].waiting_time;
    }

    printf("\n=== Shortest Job First (SJF) ===\n");
    print_gnatt(p, size);
}


int main() {
    Process *processes;
    int size;
    printf("Enter Number of processes: ");
    scanf("%d", &size);
    processes = (Process *)malloc(size * sizeof(Process));
    if (processes == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }    

    int arrival_input;
    int burst_input;
    for(int i=0 ; i<size ; i++){
        printf("Enter the arrival time and burst time for process %d : ", i+1);
        scanf("%d", &arrival_input);
        scanf("%d", &burst_input);
        
        processes[i].pid = i+1;
        processes[i].arrival_time = arrival_input;
        processes[i].burst_time = burst_input;
    }

    arrival_sort(processes, size);

    fcfs(processes , size);
    sjf(processes , size);

    free(processes);
    return 0;
}
