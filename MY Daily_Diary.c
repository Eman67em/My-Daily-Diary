
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY 3000
#define MAX_DATE 30

void addEntry() {
    FILE *file = fopen("diary.txt", "a");
    if (file == NULL) {
        printf("Error opening file.
");
        return;
    }

    char date[MAX_DATE];
    char entry[MAX_ENTRY];

    printf("Enter the date (e.g., 2025-06-10): ");
    scanf(" %[^
]%*c", date);

    printf("Write your diary entry:\n");
    scanf(" %[^
]%*c", entry);

    fprintf(file, "Date: %s\n", date);
    fprintf(file, "Entry: %s\n", entry);
    fprintf(file, "--------------------------\n");

    fclose(file);
    printf("Diary entry saved successfully.\n");
}

void viewEntries() {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("No diary entries found.\n");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}

void searchByDate() {
    FILE *file = fopen("diary.txt", "r");
    if (file == NULL) {
        printf("No diary entries found.\n");
        return;
    }

    char searchDate[MAX_DATE];
    char line[MAX_ENTRY];
    int found = 0;

    printf("Enter the date to search for: ");
    scanf(" %[^
]%*c", searchDate);

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, searchDate)) {
            found = 1;
            printf("%s", line);
            while (fgets(line, sizeof(line), file) && strcmp(line, "--------------------------\n") != 0) {
                printf("%s", line);
            }
            printf("--------------------------\n");
        }
    }

    if (!found) {
        printf("No entries found for that date.\n");
    }

    fclose(file);
}

int main() {
    int choice;

    do {
        printf("\n--- Diary Journal ---\n");
        printf("1. Add New Entry\n");
        printf("2. display All Entries\n");
        printf("3. Search by Date\n");
        printf("4. Exit\n");
        printf("Your choice is: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEntry(); break;
            case 2: viewEntries(); break;
            case 3: searchByDate(); break;
            case 4: printf("Goodbye!\n"); break;
            default: printf("Invalid choice try somthing else.\n");
        }

    } while (choice != 4);

    return 0;
}
