#include <stdio.h>
#include <stdbool.h>

int main(){
    // int = whole numbers (4 bytes in modern systems)
    // float = single-precision decimal number (4 bytes)
    // double = double-precision decimal number (8 bytes)
    // char = single characters (1 byte)
    // char[] = array of characters (size varies)
    // bool = true or false / 1 or 0 (requires <stdbool.h>)

    /* Format specifiers = Special tokens that being with a '%' symbol,
                            followed by a character that specifies the data type
                            and optional modifiers (width, precision, flags...).
                            They control how data is displayed or interpreted.
    */
    int age = 25;
    float price = 19.99;
    double pi = 3.1415926535;
    char currency = '$';
    char name[] = "YourName";

    printf("%d\n",age); // %d means decimal FS.
    printf("%f\n", price); // %f means float FS.
    printf("%lf\n", pi); // %lf means long float FS, can also be used with %f to show less, yet it's convinient using %lf.
    printf("%c\n", currency); // %c means character FS.
    printf("%s\n", name); // %s means string FS, also known as an "array of characters".
    printf("==========\n");

    // Optional modifiers

        // Width
    int num1, num2, num3, num4;
    num1 = 1;
    num2 = 10;
    num3 = 100;
    printf("%3d\n", num1); // Adding a number before the 'd' specifies the maximum amount of characters to print. Spaces count as a character, though not shown, it's '\t'.
    printf("%3d\n", num2); // Adds a space and the other 2 remaining spaces are allocated by the number 10.
    printf("%3d\n", num3); // Since '100' occupies 3 characters, no space is added.
    printf("==========\n");
    // Positive numbers mean right justification, therefore, we can left justify just by using negative numbers:
    printf("%-3d\n", num1);
    printf("%-3d\n", num2);
    printf("%-3d\n", num3);
    printf("==========\n");
    // We can add leading characters (apparently only 0 works, for now) to be printed in the missing spaces instead of having a space (works with right justification):
    printf("%04d\n", num1);
    printf("%04d\n", num2);
    printf("%04d\n", num3);
    printf("==========\n");

        // Flags
    // If we have positive and negative numbers, we can use '+' to show the sign of each number (even though negative numbers have the sign by default):
    num4 = -100;
    printf("%+d\n", num1);
    printf("%+d\n", num2);
    printf("%+d\n", num3);
    printf("%+d\n",num4);
    printf("==========\n");

        // Precision
    float price1, price2, price3;
    price1 = 19.99;
    price2 = 1.50;
    price3 = -100.00;
    printf("%f\n", price1); // The default display is 6 digits after a comma, if not used, it is filled with zeros.
    printf("%f\n", price2);
    printf("%f\n", price3);
    printf("==========\n");
    // We can use the dot (.) after the percentage symbol to show decimals from 1 to 6 (as a float type var) and it WILL rounded.:
    printf("%.2f\n", price1);
    printf("%.2f\n", price2);
    printf("%.2f\n", price3);
    printf("==========\n");

        // Example: combination of width, flags and precision.
    printf("%+07.2f\n", price1); // "Print the price1, price2 and price3 variables with their sign, 7 characters of width, changing the spaces with a 0, but round them to 2 decimals."
    printf("%+07.2f\n", price2);
    printf("%+07.2f\n", price3);
    return 0;
}