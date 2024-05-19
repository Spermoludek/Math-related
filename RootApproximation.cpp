#include <iostream>
using namespace std; 

double f(double x) {
    return 2*x - 3; // f(x) 
}
double const epsilon = 0.001; // Our precision of the target root


double root(float bottom, float upper) {
    double midpoint = 0; 
    if (f(upper) * f(bottom) > 0 ) {
        cout << "Roots do not exist in this domain \n"; // Its a necessity in this case, quite primitive though.
        return 0;
    }
    while (upper - bottom > epsilon && f(upper) != 0 && f(bottom) != 0) // Until the approximation is sufficient or the value of f(x) = 0
    {
        midpoint = (bottom + upper) / 2; 
        if (f(bottom) * f(midpoint) < 0) {
            upper = midpoint; 
        }
        else {
            bottom = midpoint; 
        }
    }
   return f(bottom) == 0 ? bottom : (f(upper) == 0 ? upper : midpoint);
}



int main() {
    cout << "Program that calculates the approximate root of a function \n";
    float bottomInterval = 0;
    float upperInterval = 0;
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
    cout << "The root of a function is x = " << root(bottomInterval, upperInterval);
    
    return 0;
}
/* 
ABSTRACT 

While in math we rely on precision and tight logic, sometimes in CS we simply approximate till we get a sufficient answer 

One of many instances is calculating the root of a function in a given range

Suppose we have two boundaries, a and b, where a < b
And f(a) * f(b) < 0, otherwise the function has no roots (There has to be a transition from positive to negative)

We will return the first argument that makes f(x) = 0, or at least provides sufficient approximation 
if it's one of the boundaries, then job is done 
otherwise we will calculate the distance (midrange) to get closer to our root (which we will)

In steps
1. set boundaries A and B and the precision epsilon
2. if f(a) * f(b) > 0, then the function has no roots and we're done
3. if f(a) or f(b) is equal to 0, return the argument that achieves that goal 
4. if b - a <= epsilon, calculate the midpoint m = a + b / 2 and return it 
5. otherwise, if f(a) * f(m) < 0 then b = m, otherwise a = m 
6. repeat until condition 2,3 or 4 is met. 





*/

