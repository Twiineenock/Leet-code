#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int numSquares(int n);
int isPerfectSquare(int n);

int main() {
    int n = 18;
    int result = numSquares(n);
    printf("Result: %d\n", result);
    return 0;
}

// int isPerfectSquare(int n) {
//     int root = sqrt(n);
//     return root * root == n;
// }

int isPerfectSquare(int n) {
    if (n < 0) return 0;  // negative numbers can't be perfect squares

    double root = sqrt(n);
    int rounded = (int)(root + 0.5);  // round to nearest integer

    return rounded * rounded == n;
}

int numSquares(int n) {
    int perfectSquares = 0;
    int workingValue = n;
    int possiblePerfectSquare = workingValue;
    
    while (workingValue > 0) {
        if(isPerfectSquare(possiblePerfectSquare)) {
            perfectSquares++;
            workingValue -= possiblePerfectSquare;
            possiblePerfectSquare = workingValue;
        } else {
            possiblePerfectSquare--;
        }
    }

    return perfectSquares;
}
