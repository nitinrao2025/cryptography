#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate gcd of two numbers using Extended Euclidean Algorithm
long long gcdExtended(long long a, long long b, long long *x, long long *y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }

    long long x1, y1;
    // Recursive call
    long long gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}



int main() {
    int a = 248;
    int b = 324;
    cout << "GCD(" << a << "," << b <<") is ";
}