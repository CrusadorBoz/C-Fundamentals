#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

int main() {
    // Basic types
    int count = 10;
    float temperature = 36.6;
    char grade = 'A';

    // Array
    int scores[5] = {90, 85, 78, 92, 88};

    // Structure
    Person person1;
    strcpy(person1.name, "Alice");
    person1.age = 30;

    // Enumeration
    enum Color {RED, GREEN, BLUE};
    enum Color favoriteColor = BLUE;

    printf("Count: %d\n", count);
    printf("Temperature: %.1f\n", temperature);
    printf("Grade: %c\n", grade);
    printf("First score: %d\n", scores[0]);
    printf("Person: %s, Age: %d\n", person1.name, person1.age);
    printf("Favorite color: %d\n", favoriteColor);

    return 0;
}

// gcc -o print.exe strings.c
