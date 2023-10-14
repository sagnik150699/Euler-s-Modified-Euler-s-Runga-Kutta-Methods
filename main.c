#include<stdio.h>
#include<math.h>

const float TOLERANCE = 0.0001;

float eulerFunction(float x, float y, float h) {
    return (h * (x + y));
}

void eulerMethod(float x, float y, float a, float h) {
    while (x <= a) {
        y = y + eulerFunction(x, y, h);
        x = x + h;
        printf("%0.3f \t%0.3f \n", x, y);
    }
}

float rungeKuttaFunction(float x, float y) {
    return (x * x) + (y * y * x);
}

void rungeKuttaMethod(float x, float y, float a, float h) {
    float k1, k2, k3, k4, k;
    int i;
    float n = (a - x) / h;
    for (i = 0; i < n; i++) {
        k1 = h * rungeKuttaFunction(x, y);
        k2 = h * rungeKuttaFunction(x + (h / 2), y + (k1 / 2));
        k3 = h * rungeKuttaFunction(x + (h / 2), y + (k2 / 2));
        k4 = h * rungeKuttaFunction(x + h, y + k3);
        k = (k1 + (2 * k2) + (2 * k3) + k4) / 6;
        y = y + k;
        x = x + h;
    }
    printf("The required value= %.3f\n", y);
}

float modifiedEulerFunction(float x, float y) {
    return (x * x) + y;
}

void modifiedEulerMethod(float x, float y, float a, float h) {
    float m0, k, t = 0, m1, m2, w;
    int i;
    printf("The respective values of x and y are...\n");
    printf("x \t y \n");
    for (i = 0; x <= a; i++) {
        w = TOLERANCE * 10;  // Initial value greater than TOLERANCE
        m0 = modifiedEulerFunction(x, y);
        printf("%.3f\t%.3f\n", x, y);
        x = x + h;
        k = y;
        while (w > TOLERANCE) {
            m1 = modifiedEulerFunction(x, k);
            m2 = (m0 + m1) / 2;
            t = y + (m2 * h);
            w = fabs(k - t);
            k = t;
        }
        y = t;
    }
}

int main() {
    // Hardcoded values for demonstration
    float x = 0.0;  // Starting x value
    float y = 1.0;  // Starting y value
    float a = 2.0;  // x value for which y is to be found
    float h = 0.1;  // Step size
    int c = 1;      // Choice of method: 1 for Euler's, 2 for Modified Euler's, 3 for Runge-Kutta

    /* Uncomment below for user input
    printf("Enter a point (x,y)\n");
    scanf("%f%f", &x, &y);
    printf("Enter the x for which the value of y is to be found\n");
    scanf("%f", &a);
    printf("Enter value of h\n");
    scanf("%f", &h);
    printf("1-->Euler's\n2-->Modified eulers\n3-->Runga kutta\nEnter choice\n");
    scanf("%d", &c);
    */

    switch (c) {
        case 1:
            eulerMethod(x, y, a, h);
            break;
        case 2:
            modifiedEulerMethod(x, y, a, h);
            break;
        case 3:
            rungeKuttaMethod(x, y, a, h);
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}
