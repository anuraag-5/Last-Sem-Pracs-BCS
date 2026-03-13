#include <stdio.h>
#include <string.h>

struct file {
    char name[10];
    int start;
    int length;
} dir[10];

int bit[20], n, count = 0;

void show_bit() {
    for (int i = 0; i < n; i++)
        printf("%d ", bit[i]);
    printf("\n");
}

int check_space(int len) {
    for (int i = 0; i <= n - len; i++) {
        int free = 1;
        for (int j = i; j < i + len; j++) {
            if (bit[j] == 1) {
                free = 0;
                break;
            }
        }
        if (free) return i;
    }
    return -1;
}

void create_file() {
    char fname[10];
    int len, pos;

    printf("Enter file name: ");
    scanf("%s", fname);
    printf("Enter file length: ");
    scanf("%d", &len);

    pos = check_space(len);
    if (pos == -1) {
        printf("No sufficient contiguous space\n");
        return;
    }

    strcpy(dir[count].name, fname);
    dir[count].start = pos;
    dir[count].length = len;

    for (int i = pos; i < pos + len; i++)
        bit[i] = 1;

    count++;
    printf("File created successfully\n");
}

void show_dir() {
    printf("\nFile\tStart\tLength\n");
    for (int i = 0; i < count; i++)
        printf("%s\t%d\t%d\n", dir[i].name, dir[i].start, dir[i].length);
}

int main() {
    int ch;
    printf("Enter number of blocks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        bit[i] = 0;

    while (1) {
        printf("\n1.Show Bit Vector\n2.Create File\n3.Show Directory\n4.Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: show_bit(); break;
            case 2: create_file(); break;
            case 3: show_dir(); break;
            case 4: return 0;
        }
    }
}