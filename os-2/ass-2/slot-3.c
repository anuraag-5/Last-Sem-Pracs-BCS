#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct file_detail {
    char name[10];
    int index_block;
    int size;
} dir[10];

struct block {
    int allocated;      // 0 = free, 1 = allocated, -9 = EOF
    int index[20];      // data block numbers (used only by index block)
} bit_vector[20];

int n, count = 0;

/* ---------- GET RANDOM FREE BLOCK ---------- */
int get_random_free_block() {
    while (1) {
        int r = rand() % n;
        if (bit_vector[r].allocated == 0)
            return r;
    }
}

/* ---------- SHOW MEMORY BLOCKS ---------- */
void show_memory_blocks() {
    printf("\nMemory Blocks Status:\n");
    for (int i = 0; i < n; i++) {
        printf("Block %d : %d\n", i, bit_vector[i].allocated);
    }
}

/* ---------- CREATE FILE ---------- */
void create_file() {
    char name[10];
    int size, idx;

    printf("Enter file name: ");
    scanf("%s", name);

    printf("Enter file size: ");
    scanf("%d", &size);

    /* Allocate index block randomly */
    idx = get_random_free_block();
    bit_vector[idx].allocated = 1;

    strcpy(dir[count].name, name);
    dir[count].index_block = idx;
    dir[count].size = size;

    int last_block = -1;

    /* Allocate data blocks randomly */
    for (int i = 0; i < size; i++) {
        int b = get_random_free_block();
        bit_vector[b].allocated = 1;
        bit_vector[idx].index[i] = b;
        last_block = b;
    }

    /* Mark last data block as EOF */
    bit_vector[last_block].allocated = -9;

    count++;
    printf("File created successfully\n");
}

/* ---------- DISPLAY DIRECTORY ---------- */
void display_directory() {
    for (int i = 0; i < count; i++) {
        printf("\nFile Name   : %s", dir[i].name);
        printf("\nIndex Block : %d", dir[i].index_block);
        printf("\nData Blocks : ");
        for (int j = 0; j < dir[i].size; j++)
            printf("%d ", bit_vector[dir[i].index_block].index[j]);
        printf("\n");
    }
}

/* ---------- MAIN ---------- */
int main() {
    int choice;

    srand(time(NULL));   // seed random generator

    printf("Enter number of disk blocks: ");
    scanf("%d", &n);

    /* Initialize all blocks as free */
    for (int i = 0; i < n; i++)
        bit_vector[i].allocated = 0;

    while (1) {
        printf("\n1.Create File");
        printf("\n2.Show Directory");
        printf("\n3.Show Memory Blocks");
        printf("\n4.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create_file(); break;
            case 2: display_directory(); break;
            case 3: show_memory_blocks(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}