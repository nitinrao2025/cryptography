#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// This function calculates the greatest common divisor (gcd) of two numbers a and b using
// the Extended Euclidean Algorithm. It also calculates the coefficients x and y of 
// Bézout’s identity, which are integers such that ax + by = gcd(a, b).
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

// This function calculates the modular multiplicative inverse of a modulo m. 
// It uses the Extended Euclidean Algorithm to do this. If the gcd of a and m is not 1,
// it throws an exception because the inverse does not exist.
long long modInverse(long long a, long long m) {
    long long x, y;
    // Call extendedGCD() to find modular inverse
    long long g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        throw "Public key is not valid!";
    else {
        // m is added to handle negative x
        long long res = (x%m + m) % m;
        return res;
    }
}

// Function to calculate (x^y) % p in O(log y)
// This function calculates (x^y) mod p using a fast exponentiation method.
long long power(long long x, unsigned int y, int p) {
    long long res = 1; // Initialize result
    x = x % p; // Update x if it is more than or equal to p

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p; // Change x to x^2
    }
    return res;
}

int main() {
    int e, n;
    cin >> e >> n; // Input public key
    int m;
    cin >> m; // Input length of encoded message

    vector<int> codedtext(m);
    for(int i=0; i<m; i++)
        cin >> codedtext[i]; // Input encoded message

    int p,q;
    for(int i=2; i<=sqrt(n); i++) {
        if(n%i == 0) {
            p = i;
            q = n/i; // Find prime factors of n
            break;
        }
    }

    try {
        int phi = (p-1)*(q-1); // Calculate Euler's totient function
        int d = modInverse(e, phi); // Calculate private key

        cout << p << " " << q << " " << phi << " " << d << endl;

        vector<int> plaintext(m);
        for(int i=0; i<m; i++) {
            plaintext[i] = power(codedtext[i], d, n); // Decrypt codedtext
            cout << plaintext[i] << " ";
        }
        cout << endl;

        for(int i=0; i<m; i++) {
            // Decode plaintext into characters using given mapping
            if(plaintext[i] >= 5 && plaintext[i] <= 30)
                cout << char(plaintext[i]-5+'A');
            else if(plaintext[i] == 31)
                cout << ' ';
            else if(plaintext[i] == 32)
                cout << '"';
            else if(plaintext[i] == 33)
                cout << ',';
            else if(plaintext[i] == 34)
                cout << '.';
            else if(plaintext[i] == 35)
                cout << "'";
        }
        cout << endl;

    } catch(const char* msg) {
        cerr << msg << endl; // Print error message if public key is invalid
    }

    return 0;
}
