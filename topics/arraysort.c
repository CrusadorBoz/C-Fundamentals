#include <stdio.h>

void sort(int array[], int size)
    {
        for(int i = 0; i < size - 1; i++)
        {
            for(int j = 0; j < size - i - 1; j++)
            {
                if(array[j] > array[j+1])  // to make descending you just switch to less than.  
                {
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
            }
        }
    }
    
    void printArray(int array[], int size)
    {
        for(int i = 0; i < size; i++)
        {
            printf("%d ", array[i]);
        }
    }

int main()
{
    int array[] = {9, 1, 8, 2, 7, 3, 6, 4, 5};
    // the sizeof(array) gives the size of the array in bytes.  4 on this computer. When calculating the size of the array we are looking 
    // for the number of array blocks of 4 bytes. 
    int size = sizeof(array)/sizeof(array[0]);
    int size1 = sizeof(array);
    int size2 = sizeof(array[0]);
    // printf("%d", size);
    // printf("\n%d", size1);
    // printf("\n%d", size2);

    sort(array, size);
    printArray(array, size);

    return 0;
}
