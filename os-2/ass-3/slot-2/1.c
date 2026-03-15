#include <stdio.h>

void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
}

int abs_val(int x) {
    return x < 0 ? -x : x;
}

void scan(int req[], int n, int head, int disk_size) {
    int total = 0;
    sort(req, n);

    int i;
    for (i = 0; i < n && req[i] < head; i++);

    for (int j = i; j < n; j++) {
        total += abs_val(req[j] - head);
        head = req[j];
    }

    total += abs_val((disk_size - 1) - head);
    head = disk_size - 1;

    for (int j = i - 1; j >= 0; j--) {
        total += abs_val(req[j] - head);
        head = req[j];
    }

    printf("Total Head Movement = %d\n", total);
}

int main() {
    int n, head, req[100];
    int disk_size = 200;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    scan(req, n, head, disk_size);
    return 0;
}