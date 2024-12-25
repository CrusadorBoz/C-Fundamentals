// In the C programming language, a pointer is a variable that stores the memory address of another variable. Here's a breakdown of key concepts related to pointers:

// Memory Address: Every variable in a program is stored somewhere in the computer's memory, and each location has a unique address.
// Pointer Declaration: You declare a pointer by specifying the type of data it points to followed by an asterisk (*). For example, int *ptr; declares ptr as a 
// pointer to an integer.  Assignment: Assigning an address to a pointer is done using the address-of operator (&). For instance, if you have an integer x, you can 
// set ptr to point to x with ptr = &x;. Now ptr contains the memory address of x.  Dereferencing: To access the value at the address stored in a pointer, you use 
// the dereference operator (*). So, *ptr would give you the value of x.

// Here's a simple example to illustrate:

#include <stdio.h>

int main() {
    int x = 10;  // An integer variable
    int *ptr;    // A pointer to an integer
    
    ptr = &x;    // ptr now holds the address of x
    
    printf("Value of x: %d\n", x);      // Prints the value of x
    printf("Address of x: %p\n", (void*)&x); // Prints the address of x
    printf("Value pointed to by ptr: %d\n", *ptr); // Prints the value at the address ptr is pointing to
    
    return 0;
}


// Pointer Arithmetic: Pointers can be incremented or decremented, which moves the pointer by the size of the data type it points to. For example, 
// incrementing an int* will move the pointer by sizeof(int) bytes. Null Pointer: A pointer can be set to NULL, indicating it points to nowhere. 
// Checking for NULL is a common practice to prevent accessing invalid memory.  Void Pointers: void* is a pointer that has no associated data type 
// with it. It's used for dealing with memory at a low level without specifying the type.

// Pointers are fundamental in C for dynamic memory allocation, creating data structures like linked lists or trees, and for passing arguments by 
// reference to functions. However, they require careful management to avoid common pitfalls like segmentation faults or memory leaks.

// gcc -o C:\Users\"Name"\Documents\Programs\pointers.exe pointers.c
