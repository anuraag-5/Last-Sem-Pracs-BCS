#include<stdio.h>

int n = 5, m = 3;
int ALLOC[10][10], MAX[10][10], NEED[10][10];
int AVAIL[10];

void accept_alloc(){
    printf("Enter Allocation Matrix\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &ALLOC[i][j]);
        }
    }
    printf("\n");
}

void accept_max(){
    printf("Enter Max Matrix\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &MAX[i][j]);
        }
    }
    printf("\n");
}

void accept_avail(){
    printf("Enter Available\n");
    for(int i = 0; i < m; i++){
        scanf("%d", &AVAIL[i]);
    }
    printf("\n");
}

void calculate_need(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            NEED[i][j] = MAX[i][j] - ALLOC[i][j];
        }
    }
}

void display_matrices(){
    printf("Process\tAlloc\tMax\t\tNeed\n");
    for(int i = 0; i < n; i++){
        printf("P%d\t", i);
        for(int j = 0; j < m; j++){
            printf("%d ", ALLOC[i][j]);
        }
        printf("\t");
        for(int j = 0; j < m; j++){
            printf("%d ", MAX[i][j]);
        }
        printf("\t\t");
        for(int j = 0; j < m; j++){
            printf("%d ", NEED[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void display_available(){
    printf("Available Matrix\n");
    for(int i = 0; i < m; i++){
        printf("%d ", AVAIL[i]);
    }
    printf("\n");
}

int main(){
    int choice;

    while(1){
        printf("----Banker's Algorithm----\n1. Accept Alloc\n2. Accept Max\n3. Calculate Need\n4. Accept Available\n5. Display Matrices\n6. Display Available\n7. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
            accept_alloc();
            break;

            case 2:
            accept_max();
            break;

            case 3:
            calculate_need();
            break;

            case 4:
            accept_avail();
            break;

            case 5:
            display_matrices();
            break;

            case 6:
            display_available();
            break;

            case 7:
            return 0;

            default:
            printf("Wrong Choice just as your ex.\n");
        }
    }

    return 0;
}