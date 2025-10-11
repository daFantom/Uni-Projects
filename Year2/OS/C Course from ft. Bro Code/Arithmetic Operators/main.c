#include <stdio.h>

int main(){

    // Arithemtic operators symbols -> =,+,-,*,/,%, ++,--
    printf("===== Initialization of our variables =====\n");
    int x = 10; // int operand 1
    int y = 3; // int operand 2
    float u = 10; // float operand 1
    float v = 3; // float operand 2
    int z = 0; // result variable.
    float t = 0; // floating point result variable (necessary for divisions)
    char symb = '%'; // Additional symbol for explanation
    printf("x = %d\n",x);
    printf("y = %d\n",y);
    printf("z = %d\n",z);
    printf("u = %f\n",u);
    printf("v = %f\n",v);
    printf("t = %f\n\n",t);
    printf("===== Operations =====\n");
    printf("\t- Addition:\n");
    z = x + y; // addition
    printf("\t\tx + y = %d\n", z);
    printf("\t- Substraction:\n");
    z = x - y; // substraction
    printf("\t\tx - y = %d\n",z);
    printf("\t- Product:\n ");
    z = x*y; // product
    printf("\t\tx * y = %d\n",z);
    printf("\t- Integer / Whole Division:\n");
    z = x/y; // Integer division, if result is 0.x, it shows the "whole" part, so 0, and will not print the decimals.
    printf("\t\tx / y = %d\n",z);
    printf("\t- Floating point - Integer division / Division w/ decimals:\n");
    t = x/y; // Same division as above, but this time it shows the decimals.
    printf("\t\tx / y = %f\n",t); // However, if you see, it  prints 3 but looks like an exact division, which it isn't. This is due to the fact that we're doing a division between two INT variables.
    t = u/v;
    printf("\t\tu / v = %f\n",t); // As you can see, after using FLOAT type vars, we get the ACTUAL value that we couldn't get with the INT vars.
    printf("\t- Division reminder (modulus symbol '%c'):\n",symb);
    z = x%y; 
    printf("\t\tx %c y = %d\n",symb,z); // Prints the reminder of the divison between two numbers. If the division is exact, the remainder SHOULD be 0 if no issues happened.
    printf("\t- Increment(++) and decrement(--) operators:\n");
    printf("\tOur current value of 'x' is = %d\n",x);
    x++; // Increments the value of 'x' by 1.
    printf("\tx++ = %d",x);
    x--; // Decrements the value of 'x' by 1.
    printf("\tx-- = %d\n",x);
    printf("\t* Very useful for iteraiting in 'for' loops.\n");
    printf("\t- Augmented assignment operators (+= , -=):\n");
    printf("\t Used with the value of a variable to sum its value with another value. e.g -> x = x+2\n");
    printf("\tOur current value of 'x' is = %d\n",x);
    x+=2;
    printf("\t x+=2 -> %d", x);
    x-=2;
    printf("\t x-=2 -> %d\n", x);
    printf("\t ~ Works with product and divisions, with each format and type shown before.\n");

    return 0;
}