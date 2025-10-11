#include <stdio.h>
#include <stdbool.h>

int main(){
    // Variable: vartype name = value; A reusable container for a value, we must use ';' at the end of a statement to indicate we've finished.
    
    // Integer type variables
    printf("===== Int type variables =====\n\n");
    int age = 25;
    int year = 2025;
    int quantity = 1;

    printf("You are %d years old\n", age); /* %d is a format specifier, used for printing int variables.
                                            Then we must specify the variable we want to use (age, in this case) */

    printf("The year is: %d\n",year);

    printf("You have ordered %d x items.\n\n", quantity); // these variables can be changed manually, and will change after run code.


    // Floating point type variables
    printf("===== Floating point / Float type variables =====\n\n");
     float gpa = 2.56778;
     float price = 19.99;
     float temperature = -7.5; // The maximum amount of digits after a comma (.) is about 6-7 digits. 

     printf("Your full GPA is %f.\n",gpa); // %f is a format specifier for "float" type variables, works like int variables.
     printf("Your rounded to two decimals GPA is %.2f.\n", gpa); // We can use '.x' before the 'f' to specify the amount of decimals to round to.
     printf("The price is $%.2f.\n",price);
     printf("The temperature is %.1f degrees celscius.\n\n", temperature);



     // Double type variables.
     printf("===== Double type variables =====\n\n");

     double pi = 3.14159265358979; // In contrast to float variables, we can store up to 15-16 digits after a comma. Used for better precision.
     double e = 2.7182818284590;

     printf("The value of pi is %lf.\n",pi); // %lf means 'long floating point number' format specifier.
     printf("The value of e is %.15lf.\n\n",e); //  Default print amount is 6, must use .x to specify the amount of digits to print, up to 15-16 digits.


     // Character type variables.
     printf("===== Character / Char type variables =====\n\n");

     char grade = 'A'; // Used for storing a single character. We must use single quotes to represent a character.
     char symbol = '|';
     char currency_symb = '$';

     printf("Your grade is %c.\n", grade); // %c is a format specifier for "char" type variables.
     printf("The delimiter symbol is %c.\n", symbol);
     printf("Your currency symbol of your country is %c.\n\n", currency_symb);

     // "String" type variables.
     printf("===== String / Char Array type variables =====\n\n");

     char name[] = "Your name"; // In C, we don't have String/string type varibles like in Java or C++, therefore we must use a char array, which stores multiple characters, and use double quotes.
     char food[] = "pizza";
     char email[] = "fake123@service.extension"; // We can use numbers in strings, yet they'll be interpreted as char value and we won't be able to do math with them.

     printf("Hello %s\n", name); // %s is the "string" format specifier to make somewhat of a string using a character array.
     printf("Your favourite food is %s\n", food);
     printf("Your email is %s\n\n", email);

     // Boolean type variables (and a bit of conditional statements).
     printf("===== Boolean type variables =====\n\n");

     bool isOnline = true; // Boolean type variables must be included with #include <stdbool.h> since the header is not included by default. There are only 2 values, 1 or 0 / true or false

     printf("Our boolean value is %d.\n", isOnline); // Since true == 1 and false == 0, we can use the %d format specifier, though it is not common to display their value.
     if(isOnline){
        printf("You are ONLINE.\n"); // if isOnline is true or 1, we print this.
     }
     else{
        printf("You are OFFLINE.\n"); // if isOnline is false or 0, we skip the if{} statement and proceed to do whatever is inside the else{} statement.
     }
     // Example 2:
     bool isStudent = false;

     if(isStudent){
        printf("You are a STUDENT.\n");
     }
     else{
        printf("You are NOT a STUDENT.\n");
     }

     // Example 3:
     bool forSale = true;

     if(forSale){
        printf("The item IS for sale.\n");
     }
     else{
        printf("The item is NOT for sale.\n");
     }
    return 0;
}