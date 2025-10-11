#include <stdio.h>
#include <string.h>
int main(){
    /* Let's declare BUT NOT assign a value to the following variables.
    int age;
    float gpa;
    char grade;
    char name[30]; // Since we're not assigning a value to the char array, we MUST assign it a size (for now), so let's try with 30 bytes (or 30 chars).

    It's important to bear in mind that in C, the memory slots assigned to each variable MAY already have a value
    since they MAY have been used before in our computer. Not assigning values to vars in C may show undefined behaviour when printed.
    However, in Java this cannot happen due to it's config, for example:

    printf("%d\n",age);
    printf("%f\n",gpa);
    printf("%c\n",grade);
    printf("%s\n",name);
    
    Each time we execute the program with the prints above, it will show trash info, and I think that
    fucks with the computer memory, so uhh, don't do it, even though you can test with it
    to check what happens. Therefore, it's recommended to assign the NULL equivalent value to each var:*/

    int age = 0; // Literally fucking number 0, no surprises.
    float gpa = 0.0f; // Since it's a float type var, we must use the 'f' to indicate that it SHOULD be a floating point number. If we dont use it, it may behave as a double and lead to errors.
    char grade = '\0'; // '\0' indicates the NULL terminator for char type variables.
    char name[30] = ""; // We can use an empty value for our string since it won't change anything and it's max value will still be 30 chars, or whatever we put its size as.

    // In order to get user input, we use the 'scanf' function from the stdio library. Protip: add a space before the scanning so whenever we press the ENTER key, AKA '\n', it clears de input buffer and lets us write.
    /*
    DISCLAIMER:
        DO NOT TRY TO PRINT A MESSAGE WITHIN THE scanf(); FUNCTION, I THINK IT MAKES THE COMPUTER CRY AND THE PROGRAM WON'T WORK XD
        just use another print fuction for now, until our fella Bro Code shows us something else.
        Shoutout to Bro Code.
    END OF DISCLAIMER
    */
    printf("Please input your age: ");
    scanf(" %d", &age); // The '&' symbol is used to assign a value to whatever the memory address of 'age' is. We'll later use it for something called 'pointers'.
    printf("Your age has successfuly been set to: %d\n\n",age);

    printf("Please input your GPA average (0.0 - 4.0?): ");
    scanf(" %f", &gpa); // "At the memory address of the variable gpa, stick the value the user inputs."
    printf("Your GPA average value has succesfully been set to: %f\n\n",gpa);

    printf("Please inpur your grade average (A to F): ");
    scanf(" %c", &grade);
    getchar(); // What this does, essentially, is delete that '\n' character at the end of the scan, otherwise, the program fucking bugs or something due to the fgets(); function, so we gotta use it. If it were with the scanf(); function, it wouldn't be neccessary.
    printf("Your grade average has succesfully been set to: %c\n\n", grade);
    
    printf("Please input your full name (30 characters): ");
    // scanf(" %s", &name); // scanf will store the data up until a 'space' character is found, therefore we can use the following function.
    fgets(name, sizeof(name), stdin); /* fgets() = "file get string", whose arguments are: name = the variable, sizeof(var) gets the size of our char array, otherwise must be changed manually, and we don't want that!, stdin = will catch from the standart input of the computer (AKA the holy keyboard).
                                    HOWEVER, since we used the fgets() function, it stores the enter key after we pressed it. Therefore, we have included the <string.h> header / library.*/
    name[strlen(name)-1] = '\0'; // We're setting the last character of the array to a NULL terminator '0\'. Essentially we're changin that new line indicator with 'nothing'. This is an advanced thing to do, but we'll look to it later.
    printf("Your name has successfully been set to: %s\n\n", name);

    printf("===== Personal data =====\n");
    printf("\tName: %s\n\tAge: %d\n\tAvg GPA: %f\n\tAvg grade: %c\n",name,age,gpa,grade);
    return 0;
}