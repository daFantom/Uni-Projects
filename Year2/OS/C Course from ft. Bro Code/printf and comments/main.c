#include <stdio.h>

int main(){ // usually has no arguments / stuff that needs to be inside the '()' whenever we call the function. Shown later whenever we see functions and procedures.

    // This is a single line comment.
    
    /* This is a
        multiple
        line
        comment.
    */
    printf("Hello World!\n"); // printf("text"); is the standart function in C to show stuff in the terminal. Whatever it is inside must be between double quotes. 
    printf("This is my first C program!\n"); // If we want to make a break line after a message, we gotta use '\n' for now.
    return 0; /* Whenever our program finishes, depending on our config, we will get the following message: "[Done] exited with code=0 in 0.247 seconds".
                If this shows, it means our program has finished correctly since we know that it has exited with "code=0", meaning our main function has returned the number 0 to our system.
                If the program has exited with any other number than 0, it means that the program has compiled correctly but executed poorly.
                If we're using the terminal and we close by clicking the 'X' button, it will give an exit code different from 0, but it usually doesn't mean a problem.
            */
}