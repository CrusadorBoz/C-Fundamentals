#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_PHONE 20
#define MAX_MEMO 100
#define MAX_RECORDS 100

// Define the structure for our records
struct Record {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    char memo[MAX_MEMO];
};

// Function to add a new record to the file
void createRecord(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    struct Record newRecord;
    printf("Enter name: ");
    fgets(newRecord.name, MAX_NAME, stdin);
    newRecord.name[strcspn(newRecord.name, "\n")] = 0; // Remove trailing newline

    printf("Enter phone: ");
    fgets(newRecord.phone, MAX_PHONE, stdin);
    newRecord.phone[strcspn(newRecord.phone, "\n")] = 0;

    printf("Enter memo: ");
    fgets(newRecord.memo, MAX_MEMO, stdin);
    newRecord.memo[strcspn(newRecord.memo, "\n")] = 0;

    fprintf(file, "%s|%s|%s\n", newRecord.name, newRecord.phone, newRecord.memo);
    fclose(file);
    printf("Record added successfully.\n");
}

// Function to read all records from the file
void readRecords(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    struct Record record;
    char line[MAX_NAME + MAX_PHONE + MAX_MEMO + 3]; // +3 for separators and newline
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%[^|]|%[^|]|%[^\n]", record.name, record.phone, record.memo) == 3) {
            printf("Name: %s,\t Phone: %s,\t Memo: %s\n", record.name, record.phone, record.memo);
        }
    }
    fclose(file);
}

// Function to update a record in the file
void updateRecord(const char *filename) {
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char targetName[MAX_NAME];
    printf("Enter the name of the record to update: ");
    fgets(targetName, MAX_NAME, stdin);
    targetName[strcspn(targetName, "\n")] = 0;

    char tempFilename[] = "temp_records.txt";
    FILE *tempFile = fopen(tempFilename, "w");
    if (tempFile == NULL) {
        perror("Error creating temporary file");
        fclose(file);
        return;
    }

    struct Record record;
    char line[MAX_NAME + MAX_PHONE + MAX_MEMO + 3];
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%[^|]|%[^|]|%[^\n]", record.name, record.phone, record.memo) == 3) {
            if (strcmp(record.name, targetName) == 0) {
                printf("Enter new phone: ");
                fgets(record.phone, MAX_PHONE, stdin);
                record.phone[strcspn(record.phone, "\n")] = 0;
                
                printf("Enter new memo: ");
                fgets(record.memo, MAX_MEMO, stdin);
                record.memo[strcspn(record.memo, "\n")] = 0;
                
                fprintf(tempFile, "%s|%s|%s\n", record.name, record.phone, record.memo);
                found = 1;
            } else {
                fprintf(tempFile, "%s", line);
            }
        } else {
            fprintf(tempFile, "%s", line); // Handle potential malformed records
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(filename);
        rename(tempFilename, filename);
        printf("Record updated successfully.\n");
    } else {
        remove(tempFilename);
        printf("Record not found.\n");
    }
}

// Function to delete a record from the file
void deleteRecord(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char targetName[MAX_NAME];
    printf("Enter the name of the record to delete: ");
    fgets(targetName, MAX_NAME, stdin);
    targetName[strcspn(targetName, "\n")] = 0;

    char tempFilename[] = "temp_records.txt";
    FILE *tempFile = fopen(tempFilename, "w");
    if (tempFile == NULL) {
        perror("Error creating temporary file");
        fclose(file);
        return;
    }

    struct Record record;
    char line[MAX_NAME + MAX_PHONE + MAX_MEMO + 3];
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%[^|]|%[^|]|%[^\n]", record.name, record.phone, record.memo) == 3) {
            if (strcmp(record.name, targetName) != 0) {
                fprintf(tempFile, "%s", line);
            } else {
                found = 1;
            }
        } else {
            fprintf(tempFile, "%s", line); // Handle potential malformed records
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(filename);
        rename(tempFilename, filename);
        printf("Record deleted successfully.\n");
    } else {
        remove(tempFilename);
        printf("Record not found.\n");
    }
}

int main() {
    const char *filename = "contacts.txt";
    int choice;

    while (1) {
        printf("\n--- Contact Management System ---\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Update Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // clear the input buffer
            continue;
        }
        while(getchar() != '\n'); // clear the input buffer

        switch(choice) {
            case 1: createRecord(filename); break;
            case 2: readRecords(filename); break;
            case 3: updateRecord(filename); break;
            case 4: deleteRecord(filename); break;
            case 5: 
                printf("Exiting program.\n");
                exit(0);
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// gcc -o CRUD CRUD-struct.c
