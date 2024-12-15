#include <stdio.h>

int main()
{
    size_t length = 5;  // You need to declare variables.
    char misc[length];

    misc[0] = '4';
    misc[1] = '1';
    misc[2] = 'W';
    misc[3] = 'H';
    misc[4] = '(';
    
    for(int a = 0; a < length; a++) // I did not initilize with 0 for a here
    {
        printf("%c", misc[a]);
    }

    printf("\nSize of Array: %d\n", length);

    for(int i = 0; i<length; i++) // did not initilize with 0 for i here
    {
        if (misc[i] >= '0' && misc[i] <= '9')
        {
            printf("%c - ", misc[i]);
            printf("Yes, this is a number\n");
        }
        else if ((misc[i] >= 'a' && misc[i] <= 'z') || (misc[i] >= 'A' && misc[i] <= 'Z'))
        {
            printf("%c - Yes, this is an alphabet.\n", misc[i]);
        }
        else
        {
            printf("%c - ", misc[i]);
            printf("No, this is not a number or alphabet\n");
        }
    }
    return 0;
}
