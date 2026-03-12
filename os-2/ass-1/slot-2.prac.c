#include<stdio.h>

int ALLOC[10][10], MAX[10][10], NEED[10][10];
int AVAIL[10], REQ[10], FINISH[10], WORK[10], SAFESEQ[10];

int n = 5, m = 3, proc;

void calculate_need() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            NEED[i][j] = MAX[i][j] - ALLOC[i][j];
}

int safety_algorithm(){
    for(int i = 0; i < m; i++){
        WORK[i] = AVAIL[i];
    }

    for(int i = 0; i < n; i++){
        FINISH[i] = 0;
    }

    int count = 0;

    while(count < n){
        int found = 0;
        for(int i = 0; i < n; i++){
            if(FINISH[i] == 0){
                int j;
                for(j = 0; j < m; j++){
                    if(NEED[i][j] > WORK[j]){
                        break;
                    }
                }

                if(j == m) {
                    for(int k = 0; k < m; k++){
                        WORK[k] += ALLOC[i][k];
                    }

                    SAFESEQ[count++] = i;
                    FINISH[i] = 1;
                    found = 1;
                }
            }
        }
        if(!found){
            printf("System in in unsafe state\n");
            return 0;
        }
    }

    printf("System is in safe state\nSafe Sequence: ");
    for(int i = 0; i < n; i++){
        printf("P%d ", SAFESEQ[i]);
    }
    printf("\n");
    return 1;
}

void resource_request(){
    printf("Enter process number (0-4): ");
    scanf("%d", &proc);

    printf("Enter Request Vector: \n");
    for(int i = 0; i < m; i++){
        scanf("%d", &REQ[i]);
    }

    //Check Req < Need
    for(int i = 0; i < m; i++){
        if(REQ[i] > NEED[proc][i]){
            printf("Req is greater than need\n");
            return;
        }
    }

    //Check Req < Available
    for(int i = 0; i < m; i++){
        if(REQ[i] > AVAIL[i]){
            printf("Req is greater than available, process must wait\n");
            return;
        }
    }

    //Pretend Allocation
    for(int i = 0; i < m; i++){
        ALLOC[proc][i] += REQ[i];
        AVAIL[i] -= REQ[i];
        NEED[proc][i] -= REQ[i];
    }

    if(!safety_algorithm()){
        for(int i = 0; i < m; i++){
        ALLOC[proc][i] -= REQ[i];
        AVAIL[i] += REQ[i];
        NEED[proc][i] += REQ[i];
        }
        printf("Request cannot be granted\n");
    } else {
        printf("Request granted successfully\n");
    }
}

int main(){
    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &ALLOC[i][j]);
printf("Enter Max Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &MAX[i][j]);

    printf("Enter Available Resources:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &AVAIL[i]);

    calculate_need();
    safety_algorithm();
    resource_request();

    return 0;
}