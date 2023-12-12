
#include "CFinalReview.h"
// =============================
// Memory Allocation
// =============================

// Local, Global, and Static Variables are the different types of variables used in C.
// Variables are stored in memory in 3 phases:
// 1. Allocation - Process of assigning a specific memory area to a variable (when the function is called).
// 2. Deallocation - The system reclaiming the memory area from a variable (when the function exits).
// 3. Lifetime - Duration from its allocation to its deallocation.

// ==== Local Variables ====
// - They are called local because their scope and lifetime are confined to the function they are declared in.
// - Allocated memory upon function call and deallocated upon function exit.
// Scope: Local to the function
// Storage: Stack (LIFO)

// Example
int square(int number) {
    // 'number' and 'result' are local variables
    int result = number * number; // Allocated when 'square' is called
    return result; // Deallocated when 'square' function exits
}

// Stack vs. Heap:
// HEAP:
// - Used for dynamic memory allocation. NOT automatic; programmers must manually allocate and free the memory.
// STACK:
// - Used for static memory allocation. IS automatic; allocated and deallocated automatically.
// Stack is LIFO, also called "local memory." It stores local variables, function parameters, return addresses, etc.

// Dynamic Memory Allocation:
// - Dynamic memory allocation is a way of allocating memory at run time, typically on the heap.
// - malloc() and calloc() are used to allocate memory dynamically.

// ==== malloc() ====
void *malloc(size_t size);
// - Allocates a block of 'size' bytes. Use sizeof(data_type) to get the size.
// - Does not initialize the allocated memory.

// ==== calloc() ====
void *calloc(size_t num_elements, size_t element_size);
// - Allocates a block of size 'num_elements * element_size'.
// - Initializes each block with 0 (default value).

// ==== realloc() ====
void *realloc(void *ptr, size_t new_size);
// - Used to change the size of previously allocated memory.
// - Returns a pointer to the newly allocated memory.
// - If block size is increased, previous block is copied to new memory.
// - If block size is decreased, previous block is copied to new memory, and the original pointer is still valid.

// ==== free() ====
void free(void *ptr);
// - Used to free up dynamically allocated memory.
// - Does not delete the pointer, only frees up the memory.

// Dynamic Memory Allocation with malloc()
int *allocateMemoryWithMalloc() {
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation with malloc() failed.\n");
    } else {
        *ptr = 42;
        printf("Value at ptr (malloc()): %d\n", *ptr);
    }
    return ptr;
}

// Dynamic Memory Allocation with calloc()
double *allocateMemoryWithCalloc() {
    double *dblPtr = (double *)calloc(2, sizeof(double));
    if (dblPtr == NULL) {
        printf("Memory allocation with calloc() failed.\n");
    } else {
        for (int i = 0; i < 2; i++) {
            printf("Value at dblPtr[%d]: %lf\n", i, dblPtr[i]);
        }
    }
    return dblPtr;
}

//Reallocating Memory
void reallocMemory() {
    int *ptr = (int *)malloc(10 * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation with malloc() failed.\n");
    } else {
        for (int i = 0; i < 10; i++) {
            ptr[i] = i + 1;
        }
        printf("Values in ptr before realloc():\n");
        for (int i = 0; i < 10; i++) {
            printf("%d ", ptr[i]);
        }
        printf("\n");
    }

    // Reallocating memory
    ptr = (int *)realloc(ptr, 20 * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation with realloc() failed.\n");
    } else {
        for (int i = 10; i < 20; i++) {
            ptr[i] = i + 1;
        }
        printf("Values in ptr after realloc() to size 20:\n");
        for (int i = 0; i < 20; i++) {
            printf("%d ", ptr[i]);
        }
        printf("\n");
    }
}

// Must free up dynamically allocated memory:
void freeMemory(void *ptr) {
    free(ptr);
}

int main() {
    int num = 5;
    int squared = square(num);

    printf("Square of %d is %d\n", num, squared); // After function call, local variables in 'square' are deallocated

    // Dynamic Memory Allocation with malloc()
    int *ptrM = allocateMemoryWithMalloc();
    // Free the allocated memory when done
    freeMemory(ptrM);

    // Dynamic Memory Allocation with calloc()
    double *dblPtrC = allocateMemoryWithCalloc();

    // Reallocating Memory
    reallocMemory();

    // Free the allocated memory when done
    freeMemory(dblPtrC);

    return 0;
}
