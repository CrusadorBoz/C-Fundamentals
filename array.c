#include <stdio.h>

int main() 
{
    // Array = a data structure that can store many values of the same data type.

    double prices[] = {5.0, 10.0, 1500.0, 25.0, 20.0, 250.00};

    double store[3];

    store[0] = 5.0;
    store[1] = 15.0;
    store[2] = 20.0;

    // printf("%.2lf", prices[2]);

    printf("%d bytes\n", sizeof(prices));

    // to get size of array to replace: for(int i; i < 5; i++)
    for(int i; i < sizeof(prices)/sizeof(prices[0]); i++)
    {
        printf("$%.2lf\n", prices[i]);
    }

    return 0;
}
