#include <stdio.h>

// Initialization of Structure Variables:
// - Individual members can be initialized separately using designated initializers.
// - Can initialize only the first few structure variables; the rest are set to default values.
// - If initialized with empty braces {}, all members are set to default values.


// Definition of the 'point' structure.
struct point {
    int x;  // X-coordinate
    int y;  // Y-coordinate
};

// Function to print a point structure.
void printPoint(struct point p) {
    printf("(%d, %d)\n", p.x, p.y);
}

// Function demonstrating structure initialization and printing.
void print1() {
    struct point somePoint = {1, 2}; // Initializes both x and y to their default values (0).
    printPoint(somePoint);       // Prints the initialized point.
}

// Copying & Comparing Struct Variables:
// - The '=' operator is used to COPY contents to another structure of the same type. CANNOT use on diff struct types
// The '==' or '!=' operators are used for COMPARISON of individual structure members. CANNOT compare entire structs



// Function to copy one point structure to another
void copyPoint(struct point *dest, struct point *src) {
    *dest = *src; // Copy all members of src to dest
}

// Function to compare two point structures
int arePointsEqual(struct point p1, struct point p2) {
    // Compare individual members
    return (p1.x == p2.x) && (p1.y == p2.y);
}

// Function to display a point
void displayPoint(struct point p) {
    printf("(%d, %d)\n", p.x, p.y);
}

// Array of Structures:
// -

//There are 2 ways to define an array of structs:
//1.
struct student {
    char name[20];
    int id;
    char gender;
    int phone_no;
};
struct student st[1000];

//2.
struct people {
    char name[20];
    int id;
    char gender;
    int phone_no;
} ppl[1000];

//To access individual members of individual strcutures in arrays:









// Main function demonstrating structure usage.
int main() {
    //1. Pointer Initialization
    print1();  // Calls function to demonstrate structure printing.

    //2. Comparing and Copying
    struct point p1 = {10, 20};
    struct point p2 = {30, 40};
    printf("p1 before copying: ");
    printf("p2 before copying: ");
    displayPoint(p1);
    displayPoint(p2);

    //compare p1 and p2 before copying
    if (arePointsEqual(p1, p2)) {
        printf("[before copying]: p1 and p2 are equal\n");
    } else {
        printf("[before copying]: p1 and p2 are not equal\n");
    }

    // Copy p2 to p1
    copyPoint(&p1, &p2);

    // Display copied values
    printf("p1 after copying: ");
    displayPoint(p1);
    printf("p2: ");
    displayPoint(p2);

    // Compare p1 and p2
    if (arePointsEqual(p1, p2)) {
        printf("[after copying]: p1 and p2 are equal\n");
    } else {
        printf("[after copying]: p1 and p2 are not equal\n");
    }

    //3. Array pf Structures


    return 1;  // Program returns 1 indicating completion.
}
