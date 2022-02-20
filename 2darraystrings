#include <stdio.h>
#include <string.h> // To allow for the string copy function.

int main()
{
    char cars[][10] = {"Mustang", "Corvette", "Camaro"};

    // We cannot change a specific value of a character string because it is an array of strings.
    printf("%s\n", cars[0]);

    strcpy(cars[0], "Tesla");
    strcpy(cars[2], "Jeep");
    
    printf("%d\n", sizeof(cars));
    printf("%d\n", sizeof(cars[0]));

    for(int i = 0; i < sizeof(cars)/sizeof(cars[0]); i++)
    {
        printf("%s\n", cars[i]);
    }

    return 0;
}
