#include <iostream>

using namespace std;

double horner(int n, double coefficients[], double x) // The degree of a polynomial, its coefficients, and the actual value
{
    if (n == 0) // If we reached the 0th degree of a polynomial
    {
        return coefficients[0] * x; // Anything to the power of 0 is 1, so we just return the coefficient * x 
    }
    return horner(n-1, coefficients, x)*x + coefficients[n];
}


int main() {
    unsigned int n, x = 0;
    cout << "Program purposed to calculate the value of a given polynomial W(x) for any X \n";
    cout << "Enter the degree of a polynomial: ";
    cin >> n;
    n--; // For whatever reason this doesnt work if we dont include this heresy
    if (!cin) {
        cout << "Invalid input!";
        return 1;
    }
    double coefficients[n+1];
    for (int i = 0; i < n+1; i++) {
        cout << "Enter the coefficient: ";
        cin >> coefficients[i];
    }
    cout << "What is the x?: ";
    cin >> x;
    cout << "The value of W(" << x << ")" << " is " << horner(n, coefficients, x); 
    return 0;
}
/* 
ABSTRACT

To calculate a value of a polynomial we need to perform n(n+1) / 2 multiplications, which is a lot for  large n 
So wiser people than myself have come up with a method to reduce the number of multiplications down to n operations 

We call it Horner's method 

Basically, it turns a polynomial P(x) = 2x^3 + 3x^2 + 5x + 4 

Into P(x) = x * (x * (2 *x + 3) + 5) + 4 
This is also hella effective when it comes to dividing polynomials 

Some day I will make a program that prints a full polynomial, but its far future


*/

