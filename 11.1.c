#include <stdio.h>
#include <math.h>

double ln(double x, int n, double E, double sum) {
    double term = pow(x-1, 2*n+1) / pow((2*n+1)*(x+1), 2*n+1);

    if (term < E) {
        return sum;
    } else {
        sum += term;
        return ln(x, n+1, E, sum);
    }
}

int main() {
    double x = 2;
    int n = 1;
    double E = pow(10,-3);
    double sum = 0;

    sum = ln(x, n, E, sum);

    printf("ln(%f) = %f\n", x, sum);
    printf("Number of terms added to sum: %d\n", n-1);

    return 0;
}
