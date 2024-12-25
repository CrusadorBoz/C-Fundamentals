#include <stdio.h>

int main()
{
    // 2D array - an array, where each element is an entire array
    //          useful if you need a matrix, grid, or table of data

/*
    int numbers[2][3] = 
    {
        {1, 2, 3}, 
        {4, 5, 6}
    };
*/

    int numbers[3][3];
    int weird[3][4];

    // int a[1];  // An array with 17 variables.  Ints are in 4 bytes on my computer.  Run example to verify.
    // size_t n = sizeof(a);

    // printf("%d\n", n);

    int rows = sizeof(numbers)/sizeof(numbers[0]);
    int columns = sizeof(numbers[0])/sizeof(numbers[0][0]);

    printf("rows: %d\n", rows);
    printf("columns: %d\n", columns);

    printf("Weird Bytes: %d\n", sizeof(weird[0]));  // This seems strange.  Because weird[0] for a 2D means it is the whole row.

    printf("%d\n", sizeof(numbers[0]));
    printf("%d\n", sizeof(numbers[0][0]));
 
    numbers[0][0] = 1;
    numbers[0][1] = 2;
    numbers[0][2] = 3;

    numbers[1][0] = 4;
    numbers[1][1] = 5;
    numbers[1][2] = 6;

    numbers[2][0] = 7;
    numbers[2][1] = 8;
    numbers[2][2] = 9;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// gcc -o C:\Users\"Name"\Documents\Programs\2D-Array.exe 2darray.c
