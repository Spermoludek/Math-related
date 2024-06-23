#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void Erastotenes(unsigned int n) {
    vector<bool> list(n, true); // Vector of n numbers, all set to true
    for (int i = 0; i < n; i++) {
        for (int p = 2; p < sqrt(n); p++)
        if (i % p == 0) {
            list[i] = false;
        }
    }
    for (int i = 2; i < n; i++) {
        if (list[i]) {
            cout << i << '\t';
        }
    }
}

int main() {
    cout << "Eratostenes sieve from 2 to n\n";
    unsigned int n = 0;
    cout << "Up to which n, chief?: ";
    cin >> n;
    if (!cin) {
        cout << "Invalid input!";
        return 1;
    }
    Erastotenes(n);

    return 0;
}
/*
ABSTRACT
From the dawn of time people have wondered about prime numbers and how to filter them out 
Erastotenes came up with a quick and efficient method to filter them out - Erastotenes' Sieve

1. Set p = 2, the smallest prime number 
2. Out of an array mark all multiples of p, by the first iteration (p = 2), we will have wiped out all even numbers
3. We set p = 3, and desintegrate all multiples of 3 
4. We set p = 5, since 4 had already been wiped out of the face of the earth on first iteration
5. Repeat until we have all the primes 
 




*/