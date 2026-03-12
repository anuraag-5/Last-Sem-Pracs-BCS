#include <stdio.h>

int n = 5;   // number of processes
int m = 3;   // number of resources

int Alloc[10][10], Max[10][10], Need[10][10];
int Avail[10];

void accept_allocation() {
    int i, j;
    printf("\nEnter Allocation Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &Alloc[i][j]);
        }
    }
}

void accept_max() {
    int i, j;
    printf("\nEnter Max Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &Max[i][j]);
        }
    }
}

void calculate_need() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            Need[i][j] = Max[i][j] - Alloc[i][j];
        }
    }
}

void accept_available() {
    int i;
    printf("\nEnter Available Resources:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &Avail[i]);
    }
}

void display_matrices() {
    int i, j;
    printf("\nProcess\tAllocation\tMax\t\tNeed\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t", i);

        for (j = 0; j < m; j++)
            printf("%d ", Alloc[i][j]);

        printf("\t\t");

        for (j = 0; j < m; j++)
            printf("%d ", Max[i][j]);

        printf("\t\t");

        for (j = 0; j < m; j++)
            printf("%d ", Need[i][j]);

        printf("\n");
    }
}

void display_available() {
    int i;
    printf("\nAvailable Resources:\n");
    for (i = 0; i < m; i++) {
        printf("%d ", Avail[i]);
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Banker's Algorithm (Slot I) ---\n");
        printf("1. Accept Allocation\n");
        printf("2. Accept Max\n");
        printf("3. Calculate Need\n");
        printf("4. Accept Available\n");
        printf("5. Display Matrices\n");
        printf("6. Display Available\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: accept_allocation(); break;
            case 2: accept_max(); break;
            case 3: calculate_need(); break;
            case 4: accept_available(); break;
            case 5: display_matrices(); break;
            case 6: display_available(); break;
            case 7: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}