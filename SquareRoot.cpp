#include <iostream>
#include <iomanip>
using namespace std;

long double root = 1;
long double squareRoot(double num, double root, unsigned int tries) { // The target number, our guess, and number of iterations
    if (tries == 0) {
        return root;
    }

    root = 0.5*(root + num / root);

    return squareRoot(num, root, tries - 1);
}

int main() {
    cout << fixed;
    cout << setprecision(6);
    double num = 0;
    unsigned int tries = 0;
    cout << "Program that computes square root of a number...manually \n";
    cout << "Please enter a positive number: ";
    cin >> num;
    cout << "Please enter a number of iterations: ";
    cin >> tries;
    !cin || num < 0 || tries <= 0 ? cout << "Invalid input!" :
     (num == 0 ? cout << "The square root of zero is 0" : cout << "The square root of " << num << " is: " << squareRoot(num, num+1, tries) ); // Guess can be anything we desire, I assumed it will be one more than the target
    

    return 0;
}
/* ABSTRACT
Q: My programming language doesn't have a built-in function to calculate square Roots, what can I do?
A: #include <cmath>?

In all seriousness, we can pretty quickly calculate an accurate estimate of a square root
Suppose we took a random guess of our root, then we take an average of that guess + number we are trying to compute / guess

If our guess is higher, then the fraction will be lower and we are getting closer to our root either way, give it a few tries and our estimate is good enough to work with
Same goes for a case when guess < root, just in a different order

The formula goes like this

sqrt(a) = 1/2(guess + a / guess)

For a = 3 and guess = 2

sqrt(3) ≈ 1/2(2 + 3 / 2) // 1.75
sqrt(3) ≈ 1/2(1.75 + 3 / 1.75) // 1.7321
sqrt(3) ≈ 1/2(1.7321 + 3 / 1.7321) //  1.73205080827, which is close enough 

The formula cannot be used to directly calculate negative square roots


*/