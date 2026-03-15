#include <stdio.h>

int abs_val(int x) {
    return x < 0 ? -x : x;
}

void fcfs(int req[], int n, int head) {
    int total = 0;

    printf("Seek Sequence: %d ", head);

    for (int i = 0; i < n; i++) {
        total += abs_val(req[i] - head);
        head = req[i];
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

    fcfs(req, n, head);
    return 0;
}