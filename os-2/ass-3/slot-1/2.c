#include <stdio.h>

int abs_val(int x) {
    return x < 0 ? -x : x;
}

//req = [23, 18, 34, 30, 45, 80]

void sstf(int req[], int n, int head) {
    int visited[100] = {0};
    int total = 0;

    for (int i = 0; i < n; i++) {
        int min = 10000, index = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && abs_val(req[j] - head) < min) {
                min = abs_val(req[j] - head);
                index = j;
            }
        }

        visited[index] = 1;
        total += abs_val(req[index] - head);
        head = req[index];
        printf("-> %d ", head);
    }

    printf("\nTotal Head Movement = %d\n", total);
}

int main() {
    int n, head, req[100];

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    sstf(req, n, head);
    return 0;
}