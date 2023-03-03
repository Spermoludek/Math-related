#include <iostream>
using namespace std;

double f(double x) {
    
    return x*x; // f(x) = x^2
}

const double C = 0.0000001; // Integration error constant, or the infamous C virgins keeps forgetting when integrating
long double Integral(double bottom, double upper) {
    double function = f(bottom);
    double area = 0;
    while (bottom < upper) {
        function = f(bottom) * C;
        area += function;
        bottom += C;
    }

    return area;
}



int main() {
    float bottomInterval = 0;
    float upperInterval = 0;
    cout << "Program calculating the integral of a given function \n";
    cout << "Please enter the bottom interval: ";
    cin >> bottomInterval;
    cout << "Please enter the upper interval:  ";
    cin >> upperInterval;
    !cin ? cout << "Invalid input!" : cout << '\n';
    if (bottomInterval > upperInterval) {
        bottomInterval += upperInterval;
        upperInterval = upperInterval - bottomInterval; // Simple swap to switch places between bottom and upper Integral
        bottomInterval -= upperInterval;
    }
    cout << "The definite integral from " << bottomInterval << " to " << upperInterval << " is: " << Integral(bottomInterval, upperInterval); 

    return 0;
}
/* ABSTRACT

Calculus is regarded as one of the most difficult things in math to grasp and master, taught almost exclusively on College level

It's comprised of two things really: Integrals and derivatives
Derivative is the instantenous rate of change of a function

Integral is the surface area under the curve
And this program is about the latter

Rules of manually calculating integrals are pretty complex, however the principle to automate it is pretty simple


We can set a variable C (Constant, or integration error) as a small value like 0.000001;
Why?
We'll be dissecting the area under the curve into lots of rectangles, which area is trivial to calculate
So the smaller the C, the better, the rectangles will have the width of C and height of y = f(x)

And we sum those rectangles to calculate said integral

All the integrals here are definite integrals, and for testing purposes I've chosen the function to be f(x) = x^2


Feel free to change it if you feel like it




*/