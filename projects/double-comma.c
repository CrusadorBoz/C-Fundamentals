#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Needs some work.  Not putting the comma in the correct place
// Function to format double with comma as thousands separator
void formatDoubleWithComma(double num, char *buffer, size_t bufferSize) {
    // Convert double to string without formatting
    snprintf(buffer, bufferSize, "%.2f", num);
    
    int length = strlen(buffer);
    int i, j, count = 0;
    for (i = length - 1, j = length - 1; i >= 0; i--, j--) {
        if (buffer[i] == '.') {
            // Move everything including and after '.' to its position
            memmove(buffer + j + 1, buffer + i, length - i + 1);
            j -= 3;  // Account for the dot and two decimal places
            count = 0;
            break;
        }
        if (count == 3 && buffer[i] != '-') {
            buffer[j + 1] = ',';  // Insert comma
            count = 0;
            j--;  // Adjust j to account for the inserted comma
        }
        count++;
    }
    // If there are groups of three before the first comma or negative sign
    while (j >= 0 && (buffer[j] != '-' || count == 3)) {
        if (count == 3) {
            memmove(buffer + j + 2, buffer + j + 1, length - j);
            buffer[j + 1] = ',';
            count = 0;
            j--;
            length++;
        }
        count++;
        j--;
    }
}

int main() {
    double number = 1234567.89;
    char formattedNumber[50];  // Ensure buffer is large enough

    formatDoubleWithComma(number, formattedNumber, sizeof(formattedNumber));
    printf("Formatted number: $%s\n", formattedNumber);

    return 0;
}

// gcc -o mortgage-payments.exe mortgage-payments.c -lm
