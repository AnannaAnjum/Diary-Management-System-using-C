#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold diary entry
struct DiaryEntry {
    char date[20];
    char entry[500];
};

// Function to add a new entry
void addEntry(struct DiaryEntry journal[], int *count) {
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", journal[*count].date);
    printf("Enter entry: ");
    getchar(); // Clear buffer
    fgets(journal[*count].entry, sizeof(journal[*count].entry), stdin);
    (*count)++;
}

// Function to view entries for a specific date
void viewEntry(struct DiaryEntry journal[], int count) {
    char date[20];
    printf("Enter date to view (YYYY-MM-DD): ");
    scanf("%s", date);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(journal[i].date, date) == 0) {
            printf("Entry for %s:\n%s\n", journal[i].date, journal[i].entry);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No entry found for %s\n", date);
    }
}

// Function to display all entries
void viewAllEntries(struct DiaryEntry journal[], int count) {
    if (count == 0) {
        printf("Diary is empty\n");
        return;
    }
    printf("All Entries:\n");
    for (int i = 0; i < count; i++) {
        printf("Date: %s\nEntry: %s\n", journal[i].date, journal[i].entry);
        printf("-------------------\n");
    }
}

int main() {
    struct DiaryEntry journal[100]; // Array to hold diary entries
    int count = 0; // Counter for entries

    int choice;
    do {
        printf("\t---Diary Management System using C Program---\n");
        printf("1. Add Entry\n");
        printf("2. View Entry for a Date\n");
        printf("3. View All Entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (count < 100) {
                    addEntry(journal, &count);
                    printf("Entry added successfully!\n");
                } else {
                    printf("Diary is full\n");
                }
                break;
            case 2:
                viewEntry(journal, count);
                break;
            case 3:
                viewAllEntries(journal, count);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.");
        }
    } while (choice != 4);

    return 0;
}
