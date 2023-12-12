// =============================
// C Preprocessor:
// =============================



// ===== 1. Examples of Preprocessor Directives: =====

// #include “filename.h”
// - This directive looks for the file in the current directory first.
// - It is generally used for including user-defined header files.
#include "CFinalReview.h"

// #include <filename.h>
// - This directive looks for the file in system header files.
// - It is used for including standard library header files.
#include <stdbool.h>

// Macro Definition:
// - #define directive is used to define macros. Like a constant.
// - It substitutes the 'replacement-text' wherever 'NAME' appears in your code.
// - It's a simple text substitution mechanism.
#define PI 3.14159

// Function-like Macros:
// - Macros can take arguments.
#define AREA(r) (PI * (r) * (r))

// Example:
// - The following macro is used to find the maximum of two numbers.
#define MAX(a, b) ((a) > (b) ? (a) : (b))

//int main() {
//// Using 'PI' macro:
//int radius = 10;
//double area = PI * radius * radius;
//    printf("[Using the PI macro] The area of a circle with radius %d is %lf\n", radius, area);
//
//// Using 'MAX' macro:
//int maximum = MAX(10, 20);
//printf("[using the MAX macro] The maximum of 10 and 20 is %d\n", maximum);
//
//// Using 'AREA' macro:
//double area2 = AREA(10);
//printf("[Using the AREA macro] The area of a circle with radius 10 is %lf\n", area2);
//}


