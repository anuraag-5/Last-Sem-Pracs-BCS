#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct file_details {
    char file_name[10];
    int file_start;
    int file_end;
} dir[10];

int bit_vector[20];     // -1 = free, otherwise stores next block
int n, free_blocks, count = 0;

/* ---------- SHOW MEMORY BLOCKS (RAW BIT VECTOR) ---------- */
void show_memory_blocks() {
    printf("\nMemory Blocks (Bit Vector):\n");
    for (int i = 0; i < n; i++)
        printf("Block %d : %d\n", i, bit_vector[i]);
    printf("Free Blocks = %d\n", free_blocks);
}

/* ---------- GET RANDOM FREE BLOCK ---------- */
int get_random_free_block() {
    if (free_blocks == 0)
        return -1;

    while (1) {
        int r = rand() % n;
        if (bit_vector[r] == -1)
            return r;
    }
}

/* ---------- CREATE FILE ---------- */
void create_file() {
    char name[10];
    int size, curr, prev = -1;

    printf("Enter file name: ");
    scanf("%s", name);

    printf("Enter file size: ");
    scanf("%d", &size);

    if (size > free_blocks) {
        printf("Not enough memory\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        curr = get_random_free_block();
        if (curr == -1)
            return;

        if (prev != -1)
            bit_vector[prev] = curr;   // link previous block
        else
            dir[count].file_start = curr;  // random start block

        prev = curr;
        bit_vector[curr] = -9;   // end-of-file (temporary)
        free_blocks--;
    }

    strcpy(dir[count].file_name, name);
    dir[count].file_end = prev;
    count++;

    printf("File created successfully\n");
}

/* ---------- DISPLAY DIRECTORY ---------- */
void display_directory() {
    printf("\nFile\tStart\tEnd\n");
    for (int i = 0; i < count; i++)
        printf("%s\t%d\t%d\n",
               dir[i].file_name,
               dir[i].file_start,
               dir[i].file_end);
}

/* ---------- MAIN ---------- */
int main() {
    int choice;

    srand(time(NULL));   // seed random generator

    printf("Enter number of disk blocks: ");
    scanf("%d", &n);

    free_blocks = n;
    for (int i = 0; i < n; i++)
        bit_vector[i] = -1;

    while (1) {
        printf("\n1.Show Memory Blocks");
        printf("\n2.Create File");
        printf("\n3.Show Directory");
        printf("\n4.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: show_memory_blocks(); break;
            case 2: create_file(); break;
            case 3: display_directory(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}