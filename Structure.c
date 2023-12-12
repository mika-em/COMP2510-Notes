# include "CFinalReview.h"

// =======================
// Structure
// =======================

// ===== 1. Initialization of Structure Variables: =====
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

// ===== 2. Copying & Comparing Struct Variables: =====
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

// ===== 3. Array of Structures: =====
// - An array of structures is an array in which each element is of structure type.

// There are 2 ways to define an array of structs:
// 1.
struct student {
    char name[20];
    int id;
    char gender;
    int phone_no;
};

struct student studentStructArray[1000];

// 2.
struct people {
    char name[20];
    int id;
    char gender;
    int phone_no;
} peopleStructArray[1000];

// To access individual members of individual structures in arrays:
// Function to modify and display a 'student' structure
void modifyAndDisplayStudent(int i) {
    strcpy(studentStructArray[i].name, "Alice");
    studentStructArray[i].id = 1001;
    studentStructArray[i].gender = 'F';
    studentStructArray[i].phone_no = 1234567890;

    printf("Student %d: Name = %s, ID = %d, Gender = %c, Phone = %d\n",
           i, studentStructArray[i].name, studentStructArray[i].id, studentStructArray[i].gender, studentStructArray[i].phone_no);
}

// Function to modify and display a 'people' structure
void modifyAndDisplayPeople(int i) {
    strcpy(peopleStructArray[i].name, "Bob");
    peopleStructArray[i].id = 2002;
    peopleStructArray[i].gender = 'M';
    peopleStructArray[i].phone_no = 123;

    printf("People %d: Name = %s, ID = %d, Gender = %c, Phone = %d\n",
           i, peopleStructArray[i].name, peopleStructArray[i].id, peopleStructArray[i].gender, peopleStructArray[i].phone_no);
}

// ===== 4. Array within a Structure =====
// - A structure can contain an array as one of its members.
struct books {
    char title[50];
    char author[50];
    int book_id;
} book;

// ===== 5. Structure within a different structure =====
// - A structure can contain another structure as one of its members.

struct Date {
    int day;
    int month;
    int year;
};

struct calendarEvent {
    char name[50];
    struct Date date;
};

// ===== 6. Pointer to a Structure =====
// - A pointer to a structure can be declared and used similar to a pointer to any other variable.
// - The arrow operator (->) is used to access members of a structure using a pointer to that structure.
// [pointer_name]->[member_name]
// - The arrow operator is a shorthand notation for (*ptr).member.
// [(*pointer_name)].[member_name]

// - This WON'T work: (*pointer.member)
// (because the '.' operator has higher precedence than the '*' operator), so it is trying to access member in pointer, which is not a struct

struct library {
    char name[50];
    char location[50];
};

// Declare a pointer to the library structure type called 'libPtr'
struct library *libPtr;

// To access individual members of a structure using a pointer to that structure:
void usingPointers() {
    // Accessing members of the structure using the pointer:

    // Using the arrow operator
    strcpy(libPtr->name, "Central Library");

    //Using the dereference operator
    strcpy((*libPtr).location, "Main Street");

    // Displaying the members of the structure using the pointer
    printf("Library Name: %s\n", (*libPtr).name);
    printf("Library Location: %s\n", libPtr->location);

}

//
//// Main function demonstrating structure usage.
//int main() {
//    //1. Pointer Initialization
//    print1();  // Calls function to demonstrate structure printing.
//
//    //2. Comparing and Copying
//    struct point p1 = {10, 20};
//    struct point p2 = {30, 40};
//    printf("p1 before copying: ");
//    printf("p2 before copying: ");
//    displayPoint(p1);
//    displayPoint(p2);
//
//    //compare p1 and p2 before copying
//    if (arePointsEqual(p1, p2)) {
//        printf("[before copying]: p1 and p2 are equal\n");
//    } else {
//        printf("[before copying]: p1 and p2 are not equal\n");
//    }
//
//    // Copy p2 to p1
//    copyPoint(&p1, &p2);
//
//    // Display copied values
//    printf("p1 after copying: ");
//    displayPoint(p1);
//    printf("p2: ");
//    displayPoint(p2);
//
//    // Compare p1 and p2
//    if (arePointsEqual(p1, p2)) {
//        printf("[after copying]: p1 and p2 are equal\n");
//    } else {
//        printf("[after copying]: p1 and p2 are not equal\n");
//    }
//
//    //3. Array of Structures
//    // Modifying and displaying the first student and person
//    modifyAndDisplayStudent(0);
//    modifyAndDisplayPeople(0);
//
//    return 1;
//}
