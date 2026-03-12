#include <stdio.h>
#include <stdlib.h>

int n = 5, m = 3;
int Alloc[10][10], Max[10][10], Need[10][10];
int Avail[10], Request[10];
int Finish[10], SafeSeq[10], Work[10];
int proc;

void calculate_need() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            Need[i][j] = Max[i][j] - Alloc[i][j];
}

int safety_algorithm() {
    for (int i = 0; i < m; i++)
        Work[i] = Avail[i];

    for (int i = 0; i < n; i++)
        Finish[i] = 0;

    int count = 0;

    while (count < n) {
        int found = 0;

        for (int i = 0; i < n; i++) {
            if (Finish[i] == 0) {
                int j;
                for (j = 0; j < m; j++) {
                    if (Need[i][j] > Work[j])
                        break;
                }

                if (j == m) {
                    for (int k = 0; k < m; k++)
                        Work[k] += Alloc[i][k];

                    SafeSeq[count++] = i;
                    Finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("\nSystem is in UNSAFE state\n");
            return 0;
        }
    }

    printf("\nSystem is in SAFE state\nSafe Sequence: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", SafeSeq[i]);
    printf("\n");

    return 1;
}

void resource_request() {
    printf("\nEnter process number (0–4): ");
    scanf("%d", &proc);

    printf("Enter Request vector: ");
    for (int i = 0; i < m; i++)
        scanf("%d", &Request[i]);

    // Request <= Need
    for (int i = 0; i < m; i++) {
        if (Request[i] > Need[proc][i]) {
            printf("Error: Request exceeds maximum need\n");
            return;
        }
    }

    // Request <= Available
    for (int i = 0; i < m; i++) {
        if (Request[i] > Avail[i]) {
            printf("Resources not available. Process must wait.\n");
            return;
        }
    }

    // Pretend allocation
    for (int i = 0; i < m; i++) {
        Avail[i] -= Request[i];
        Alloc[proc][i] += Request[i];
        Need[proc][i] -= Request[i];
    }

    if (!safety_algorithm()) {
        // Rollback
        for (int i = 0; i < m; i++) {
            Avail[i] += Request[i];
            Alloc[proc][i] -= Request[i];
            Need[proc][i] += Request[i];
        }
        printf("Request cannot be granted\n");
    } else {
        printf("Request granted successfully\n");
    }
}

int main() {
    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &Alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &Max[i][j]);

    printf("Enter Available Resources:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &Avail[i]);

    calculate_need();
    safety_algorithm();
    resource_request();

    return 0;
}