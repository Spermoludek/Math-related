#include <iostream>
using namespace std;

void fibonacci(unsigned int len) {
    long long num1 = 0, num2 = 1;
    for (int i = 0; i < len; i++) {
        cout << num2 << "\t";
        num2 += num1; // Next number in the sequence
        num1 = num2 - num1; // Replace the first number with the second
    }

}

int main() {
    
    unsigned int num, len = 0;
    cout << "A Fibonacci's sequence calculating program \n";

    cout << "For how many iterations should the sequence proceed?:  ";
    cin >> len; 
    if (!cin || len <= 0 ) {
        cout << "Bro what are you smoking";
        return 1;
    }
    else {
        fibonacci(len);
    }
    return 0;
}
/*
ABSTRACT

The Fibonacci sequence is defined as f(n) such that f(n) = f(n-1) + f(n-2), for n > 1 
So the next element is a sum of two previous ones
Simple as
This time its iterative not recursive, because recursive variation is painfully slow and resource intensive

 

*/
