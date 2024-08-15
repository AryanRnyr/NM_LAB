#include <stdio.h>
#include <math.h>
#include <string.h>

// Define the function as an actual function
float func(float x) {
    return x * sin(x) - 1;
}

int main() {
    float a, b, x, fa, fb, fx, e;
    int step = 1;
    char shifta[] = "x->a";
    char shiftb[] = "x->b";
    char shift[5] = "";  // Ensure it is initialized
    //clrscr();

    // Inputs
    while (1) {
        printf("\nEnter two initial guesses:\n");
        scanf("%f %f", &a, &b);
        printf("Enter tolerable error:\n");
        scanf("%f", &e);

        // Calculating Functional Value
        fa = func(a);
        fb = func(b);

        // Checking whether given guesses bracket the root or not
        if (fa * fb > 0.0) {
            printf("Incorrect initial guesses.\n");
        } else {
            break;
        }
    }

    // Implementing Bisection Method
    printf("\nStep \t\t a \t\t b \t\t x \t\t f(x) \t\t shift \n");
    do {
        x = (a + b) / 2;
        fx = func(x);

        printf("%d\t\t%f\t%f\t%f\t%f\t%s\n", step, a, b, x, fx, shift);
        strcpy(shift, "");  // Clear the shift string

        if (fa * fx < 0) {
            b = x;
            fb = fx;
            strcpy(shift, shiftb);
        } else {
            a = x;
            fa = fx;
            strcpy(shift, shifta);
        }
        step = step + 1;
    } while (fabs(fx) > e);

    printf("\nRoot is: %f\n", x);

    return 0;
}

