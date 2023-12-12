
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

// ==== Stack vs. Heap ===
// HEAP:
// - Used for dynamic memory allocation. NOT automatic; programmers must manually allocate and free the memory.
// STACK:
// - Used for static memory allocation. IS automatic; allocated and deallocated automatically.
// Stack is LIFO, also called "local memory." It stores local variables, function parameters, return addresses, etc.

// Dynamic Memory Allocation:
// - Dynamic memory allocation is a way of allocating memory at run time, typically on the heap.
// - malloc() and calloc() are used to allocate memory dynamically.

// ==== malloc() ==== (memory allocation)
void *malloc(size_t size);
// - Allocates a block of 'size' bytes. Use sizeof(data_type) to get the size.
// - Does not initialize the allocated memory.

// ==== calloc() ==== (contiguous allocation)
void *calloc(size_t num_elements, size_t element_size);
// - Allocates a block of size 'num_elements * element_size'
// - Initializes each block with 0 (default value).
// - returns a pointer to the first byte of the allocated memory.

// ==== realloc() ====
void *realloc(void *ptr, size_t new_size);
// - Used to change the size of previously allocated memory.
// - Returns a pointer to the newly allocated memory.
// - If block size is increased, previous block is copied to new memory!
// - If block size is decreased, previous block is copied to new memory, and the original pointer is still valid (only contains the data that fits from the old data)

// ==== free() ====
void free(void *ptr);
// - Used to free up dynamically allocated memory.
// - Does not delete the pointer, only frees up the memory.

// === Ownership Models of Memory Allocation ===

// 1. Caller-Ownership:
// - The caller creates dynamic memory and passes a pointer to the function
// - The caller "owns" the memory
// - [IMPT] caller is responsible for freeing the data
// - the caller is where the pointer to the memory is created
// 2. Callee-Ownership:
// - The callee allocates a block of memory and returns a pointer to it
// - the calee operates on the data within that memory
// - the callee is the function where the memory is allocated

// Caller Ownership Example
void processArray(int *arr, int size) {
    // Callee function operates on the memory allocated by the caller
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;
    }
}

// Dynamic Memory Allocation with malloc()
int *allocateMemoryWithMalloc() {
    int *ptr = (int *) malloc(sizeof(int));
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
    double *dblPtr = (double *) calloc(2, sizeof(double));
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
    int *ptr = (int *) malloc(10 * sizeof(int));
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
    ptr = (int *) realloc(ptr, 20 * sizeof(int));
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

// Exercise 1:
void exercise1() {
    int *array = (int *) malloc(4 * sizeof(int)); // allocating memory for 4 integers
    for (int i = 0; i < 4; i++) {
        array[i] = i; // initializing the values of the array, as malloc does not initialize the memory
    }
    for (int i = 0; i < 4; i++) {
        printf("[Exercise 1, before freeeing] %d\n", array[i]);
    }
    int *copy = array; // copying the pointer to the array
    for (int i = 0; i < 4; i++) {
        copy[i] = i + 2;// modifying the values of the array through the copy
        printf("[Exercise 1, after modifying through copy] %d\n", array[i]);
    }
    free(copy); // freeing the copy of the pointer
    for (int i = 0; i < 4; i++) {
        printf("[Exercise 1, after freeing] %d\n", array[i]);
    }
}

// Exercise 2:
// What is happening here?
void exercise2() {
    char myName[10] = "Alex";
    free(myName); // trying to free non-dynamically allocated memory
    printf("[Exercise 2] %s\n", myName); //thjs will cause an error
}

// Exercise 3:
//Which of the following statements about memory allocation in C is true?
//1. malloc returns a pointer to a block of memory of a given size.
//2. calloc allocates a block of memory and initializes it to zero and returns a pointer to the first byte of the allocated memory.
//3. realloc can be used to resize a previously allocated block of memory.
//4. All of the above.

//Answer: all of the above

// Exercise 4:
//What is the difference between stack and heap memory allocation in C?
//1. Stack memory is automatically allocated and deallocated by the compiler, while heap memory is allocated and
// deallocated by the programmer using functions such as malloc and free.
//2. Stack memory is used for static data, while heap memory is used for dynamic data.
//3. Stack memory is allocated at compile time, while heap memory is allocated at runtime.
//4. All of the above.

// Answer:
//1. Stack memory is automatically allocated and deallocated by the compiler, while heap memory is allocated and
// deallocated by the programmer using functions such as malloc and free.

// False:
//2. Stack memory is used for static data, while heap memory is used for dynamic data.
    // - Stack memory is used for local variables, function parameters, return addresses, etc.
//3. Stack memory is allocated at compile time, while heap memory is allocated at runtime.
    // - Stack memory is allocated at runtime, while heap memory is allocated at compile time.

// Exercise 5:
// What is the output of this code:
void exercise5() {
    int n = 5;
    int *a = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    int *b = a;
    a = (int *) realloc(a, 2 * n * sizeof(int));
    for (int i = n; i < 2 * n; i++) {
        a[i] = i;
    }
    for (int i = 0; i < 2 * n; i++) {
        printf("[printing b] %d\n", b[i]);
    }
    free(a);
}

// Exercise 6:
// What is the output of this code:
void exercise6() {
    int *p = (int *) calloc(5, sizeof(int)); //pointer p points to a memory allocation of size 5*4 (20) for 4 integers. values initialized to 0
    int *q;
    int i, sum = 0; // initialize i and sum to be 0
    for (i = 0; i < 5; i++) {
        *(p+i) = i+1; // each pointer starting at index 1 will have the values 1, 2, 3, 4, 5
        sum += *(p+i); // the sum of all values all the pointers are pointing to ( 15 )
    }
    q = (int *) realloc(p, 10 * sizeof(int)); // reallocate the values in p to a memory locationp that is 10x larger, so 200 for 40 integers
    for (i = 5; i < 10; i++) {
        *(p+i) = i+1; // from pointer 6, each pointer has the value 6, 7, 8, 9, 10
        sum += *(p+i); // sum is all pointers from 1 - 10
    }

    printf("%d\n", sum);
    free(p);
}

//how about this:
void exercise7() {
    int *p = (int *) calloc(5, sizeof(int)); //pointer p points to a memory allocation of size 5*4 (20) for 4 integers. values initialized to 0
    int *q;
    int i, sum, sum1 = 0; // initialize i and sum to be 0
    for (i = 0; i < 5; i++) {
        *(p+i) = i+1; // each pointer starting at index 1 will have the values 1, 2, 3, 4, 5
        sum += *(p+i); // the sum of all values all the pointers are pointing to ( 15 )
    }
    q = (int *) realloc(p, 10 * sizeof(int)); // reallocate the values in p to a memory locationp that is 10x larger, so 200 for 40 integers
    for (i = 5; i < 10; i++) {
        *(q+i) = i+1; // from pointer 6, each pointer has the value 6, 7, 8, 9, 10
        sum += *(q+i); // sum is all pointers from 1 - 10
    }
    for (i = 5; i < 10; i++) {
        *(p+i) = i+1; // from pointer 6, each pointer has the value 6, 7, 8, 9, 10
        sum1 += *(p+i); // sum is all pointers from 1 - 10
    }

    printf("%d\n%d", sum, sum1);
    free(p);
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

    // Ownership Example:
    int *myArray = (int *) malloc(5 * sizeof(int)); // Caller allocates memory
    processArray(myArray, 5); // Caller passes the pointer to the callee
    free(myArray); // Caller deallocates the memory

    //Exercise 1:
   exercise1();

    //Exercise 2:
//    exercise2(); // comment out because it will cause an error

    //exercise 5: what is the output?
    exercise5();

    //exercise 6: what is the output?
    exercise6();

    exercise7();
    return 0;
}
