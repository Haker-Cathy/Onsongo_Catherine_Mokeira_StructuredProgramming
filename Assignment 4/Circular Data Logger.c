#include <stdio.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int start = 0;
int count = 0;

void insertSample(int value) {
    if (count < BUFFER_SIZE) {
        buffer[(start + count) % BUFFER_SIZE] = value;
        count++;
    } else {
        buffer[start] = value;
        start = (start + 1) % BUFFER_SIZE;
    }
}

// Function to print samples in chronological order
void printSamples() {
    if (count == 0) {
        printf("Buffer is empty.\n");
        return;
    }

    printf("Samples in buffer (oldest -> newest): ");
    for (int i = 0; i < count; i++) {
        int index = (start + i) % BUFFER_SIZE;
        printf("%d ", buffer[index]);
    }
    printf("\n");
}

int main() {
    int value, choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert new sample\n");
        printf("2. Print buffer contents\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter new sample value: ");
                scanf("%d", &value);
                insertSample(value);
                break;
            case 2:
                printSamples();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

