#include "CFinalReview.h"

// =========================
// Generics in C
// =========================


// - The equivalent in C is to use 'void *' pointers. (not an actual Generic like in Java!)
// - 'void *' pointers can point to any type of data.

// Example:
// - The following function takes in a 'void *' pointer and prints the value it points to.
void swap(void *a, void *b, int size) {
    char temp[size];
    memcpy(temp, a, size); // memcpy(destination, source, size) - copies the values of 'size' bytes from 'source' to 'destination', it works for any data type.
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

// =======================================
// ===== Losing Static Type Checking =====
// =======================================
// Be cautious! You will lose static type checking when using 'void *' pointers.
// - The compiler will not be able to detect type errors.
// Example:
// Good example using swap function:
void goodExample() {
    unsigned int x = 0xaaaaaaaa;
    unsigned int y = 0xbbbbbbbb;
    swap(&x, &y, sizeof(unsigned int)); // size matches the actual size of the data type.
    printf("[Good Example] x = %x, y = %x\n", x, y);
}

void badExample() {
    unsigned int x = 0xaaaaaaaa;
    unsigned int y = 0xbbbbbbbb;
    swap(&x, &y, sizeof(unsigned char)); // [BAD! the size does not match the actual size of the data type, and the compiler will not detect this error!]
    printf("[Bad Example] x = %x, y = %x\n", x, y);
}

// =====================================
// ===== Casting 'void *' Pointers =====
// =====================================
// - 'void *' pointers can be casted to any other pointer type.
// - The compiler will not be able to detect type errors.
// - We cast so we can access the data pointed to by the 'void *' pointer, since we cannot dereference a 'void *' pointer.
// Example:
void castingExample() {
    int x = 10;
    void *p = &x;
    int *q = (int *) p; // Casting 'void *' pointer to an 'int *' pointer.
    printf("[Casting Example] x = %d, *q = %d\n", x, *q);
}

void badCastingButStillWorksExample() {
    int x = 10;
    void *p = &x;
    char *q = (char *) p; // [BAD! Casting 'void *' pointer to a 'char *' pointer.]
    printf("[Bad Cast But Still Works] x = %d, *q = %d\n", x, *q); //It prints '10' because int and char are both 4 bytes, so it prints the first 4 bytes of the int.
}

void badCastingAndDoesntWorkExample() {
    double x = 1.2345;
    void *p = &x;
    int *q = (int *) p; // BAD: Casting 'void *' pointer to an 'int *' pointer, resulting in undefined behaviour.

    printf("[Bad Cast And Doesn't Work] x = %f, *q = %d\n", x, *q);
}

//int main() {
//    // Using the swap function to swap two integers using "generics":
//    int a = 10;
//    int b = 20;
//    printf("Before swapping: a = %d, b = %d\n", a, b);
//    swap(&a, &b, sizeof(int));
//    printf("After swapping: a = %d, b = %d\n", a, b);
//
//    // Losing static type checking:
//    goodExample();
//    badExample();
//
//    // Casting 'void *' pointers:
//    castingExample();
//    badCastingButStillWorksExample();
//    badCastingAndDoesntWorkExample();
//}