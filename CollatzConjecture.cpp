
#include <iostream>
using namespace std;

int Collatz(long int x) {
    int n = 0;
    while (x != 1) {
        if (x % 2 == 0) {
            x /= 2;
        }
        else {
            x = x * 3 + 1;
        }
        n++;
    }
    return n;
}


int main() {
    long int x = 0;
    cout << "Software calculating length of Collatz conjecture for given n \n";
    cout << "Please enter a positive integer: ";
    cin >> x;
    x <= 0 ? cout << "Invalid input!" : cout << "The length of Collatz conjecture  for n = " << x << " is: " << Collatz(x);
    



    return 0;
}

/* ABSTRACT
Collatz Conjecture has been nicknamed the "easiest unsolved mystery of math", and many have had a try at cracking it
So far, no one has succeeded
Rules are trivial: Take a number n, if it's even, divide it by 2, if not, multiply by 3 and add 1
Until you get to 1, which you eventually will in an infinite 4 - 2 - 1 - 2 - 1 loop

So let us calculate the steps it takes in order for us to reach 1 for positive integer n

*/