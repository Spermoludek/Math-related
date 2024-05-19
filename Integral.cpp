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
long double IntegralT(double bottom, double upper) { // The same method, but we use trapezoids instead of rectangles
    double function = f(bottom);
    double area = 0; 
    while (bottom < upper) {
        function = (f(bottom) + (f(bottom+C))) * C;
        area += function;
        bottom += C;
    }
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
    cout << "The definite integral from " << bottomInterval << " to " << upperInterval << " is: " << Integral(bottomInterval, upperInterval) << "\n"; 
    cout << "The definite integral from " << bottomInterval << " to " << upperInterval << " is: " << IntegralT(bottomInterval, upperInterval); 
    return 0;
}
