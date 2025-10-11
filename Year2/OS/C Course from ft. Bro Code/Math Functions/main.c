#include <stdio.h>
#include <string.h>
#include <math.h>

// Test Hello World

int main(){
    /* In order to do math functions, we must include the <math.h> header / library. Otherwise, we'd have an error.*/

    int x = 9; // Let's declare a variable and assign it a value.
    float y = 9.0;
    float PI = 3.141592; // PI for floating point operations.
    int negNum = -1337;
    float res = 0.0f; // And another variable to store the result
    printf("===== Variables =====\n");
    printf("x = %d\n",x);
    printf("PI = %f\n",PI);
    printf("negNum = %d\n",negNum);
    printf("res = %f\n\n",res);
    printf("===== Math Functions =====\n\n");
    printf("\t===== Square root [sqrt(a)] =====\n");
    res = sqrt(x); // Calculates the square root of a.
    printf("\t\tThe square root of x is: %f\n\n",res);
    printf("\t===== Power [pow(a,b)] =====\n");
    int pwr = 2; // Let's make a variable 'pwr' to represent the power we want to calculate a number of.
    res = pow(x,pwr); // Calculates a to the power of b.
    printf("\t\tThe power %d of x is: %f\n\n",pwr,res);
    printf("\t===== Rounding [round(a)] =====\n");
    res = round(PI); // Rounds a to the closest number.
    printf("\t\tPI rounded is equal to: %f\n\n",res);
    printf("\t===== Cealing round [ceil(a)] =====\n");
    res = ceil(PI); // Rounds UP a number.
    printf("\t\tPI rounded UP is equal to: %f\n\n",res);
    printf("\t===== Floor round [floor(a)] =====\n");
    res = floor(PI); // Rounds DOWN a number.
    printf("\t\tPI rounded DOWN is equal to: %f\n\n",res);
    printf("\t===== Absolute value [abs(a)] =====\n");
    res = abs(negNum); // Returns the absolute value of a number -> res = |a|
    printf("\t\tThe absolute value of negNum is: %f\n\n",res);
    printf("\t===== Natural Logarithm [log(a)] =====\n");
    res = log(x); // Returns the natural logarithm AKA Ln(x) of a number.
    printf("\t\tThe natural logarithm of x is: %f\n\n",res);
    printf("\t===== Sin, Cos and Tangent [sin(a), cos(a), tan(a)] =====\n");
    res = sin(y); // Returns the sine of x. For some reason, the result may not be true.
    printf("\t\tsin(x) is: %f\n",res);
    res = cos(y); // Returns the cosine of x. Same issue as sine.
    printf("\t\tcos(x) is: %f\n",res);
    res = tan(y); // Returns the tangent of x. Same issue as sine.
    printf("\t\ttan(x): %f\n\n",res);
    return 0;

}
