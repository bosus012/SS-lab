#include<stdio.h>
#include<stdlib.h>

#define max 100

void roundrobin();
void SRTF();

int main()
{
    int choice;
    while(1)
    {
        printf("\n1. Round robin\n2. SRTF\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                roundrobin();
                break;
            case 2:
                SRTF();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
}

void roundrobin()
{
    int i, NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0, bt[10], temp[10];
    float avg_wt, avg_tat;

    printf("Total number of processes in the system: ");
    scanf("%d", &NOP);
    y = NOP;

    for (i = 0; i < NOP; i++)
    {
        printf("\nEnter the Burst time of Process[%d]: ", i + 1);
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }

    printf("Enter the Time Quantum for the process: ");
    scanf("%d", &quant);

    printf("\nProcess No \tBurst Time \tTAT \tWaiting Time\n");

    for (sum = 0, i = 0; y != 0;)
    {
        if (temp[i] <= quant && temp[i] > 0)
        {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }

        if (temp[i] == 0 && count == 1)
        {
            y--;
            printf("Process No[%d] \t%d\t\t%d\t\t%d\n", i + 1, bt[i], sum, sum - bt[i]);
            wt = wt + sum - bt[i];
            tat = tat + sum;
            count = 0;
        }

        if (i == NOP - 1)
            i = 0;
        else if (i < NOP)
            i++;
        else
            i = 0;
    }

    avg_wt = wt * 1.0 / NOP;
    avg_tat = tat * 1.0 / NOP;
    printf("\nAverage Turn Around Time: %f", avg_wt);
    printf("\nAverage Waiting Time: %f\n", avg_tat);
}


void SRTF()
{
    int n, AT[max], WT[max], ET[max], TAT[max], CT[max], PID[max], RT[max], i, min, j, temp, maxCT;
    double avg_WT = 0, avg_TAT = 0, thrpt;
    
    printf("Please enter the number of processes: ");
    scanf("%d", &n);
    
    if(n > max)
    {
        printf("Limit exceeded.\n");
    }
else if(n < 1)
    {
        printf("No processes exist or negative input.\n");
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            printf("Enter details for process %d:\n", i + 1);
            printf("Arrival Time: ");
            scanf("%d", &AT[i]);
            printf("Execution Time: ");
            scanf("%d", &ET[i]);
            PID[i] = i + 1;
        }
        
        // Sorting for arrival time
        for(i = 0; i < n - 1; i++)
        {
            min = i;
            for(j = i + 1; j < n; j++)
            {
                if(AT[j] < AT[min])
                {
                    min = j;
                }
            }
            
            temp = AT[i];
            AT[i] = AT[min];
            AT[min] = temp;
            
            temp = ET[i];
            ET[i] = ET[min];
            ET[min] = temp;
            
            temp = PID[i];
            PID[i] = PID[min];
            PID[min] = temp;
        }
        
        for(i = 0; i < n; i++)
        {
            RT[i] = ET[i];
        }
        RT[n] = 9999;
        j = 0;
        for(min = 0; j != n; min++)
        {
            temp = n;
            for(i = 0; i < n; i++)
            {
                if(AT[i] <= min && RT[i] < RT[temp] && RT[i] > 0)
                {
                    temp = i;
                }
            }
            
            RT[temp]--;
            if(RT[temp] == 0)
            {
                j++;
                thrpt = min + 1;
                CT[temp] = thrpt;
                if(maxCT < thrpt)
                {
                    maxCT = thrpt;
                }
            }
        }
        
        printf("Process\tArrival Time\tExecution Time\tCompletion Time\tTAT\tWaiting Time\n");
        
        for(i = 0; i < n; i++)
        {
            TAT[i] = CT[i] - AT[i];
            WT[i] = TAT[i] - ET[i];
            avg_TAT = avg_TAT + TAT[i];
            avg_WT = avg_WT + WT[i];
            printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t%d\n", PID[i], AT[i], ET[i], CT[i], TAT[i], WT[i]);
        }
        
        avg_TAT = (double)avg_TAT / n;
        avg_WT = (double)avg_WT / n;
        thrpt = (double)n / (maxCT - AT[0]);
        
        printf("\nAvg.TAT = %.2f\n", avg_TAT);
        printf("Avg.WT = %.2f\n", avg_WT);
        printf("Throughput = %.2f\n", thrpt);
    }
}
