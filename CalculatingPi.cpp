#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

int main() {
 cout << fixed;
 cout << setprecision(8);
 random_device rd;
 mt19937 sex(rd());
 uniform_real_distribution<>doctor(0,1);
 unsigned long long i, totalHits = 0;
 unsigned long long hits = 0;
 cout << "Program calculating π \n";
 cout << "Please enter the number of iterations: ";
 cin >> totalHits;



 double x = 0;
 double y = 0;

 while(i < totalHits) {
 x = doctor(sex); // Random numbers 
 y = doctor(sex);
 if (x*x + y*y >= 1) { // Note that this checks all hits outside of the circle for performance reasons (Less condition statements to be considered)
  hits++;
 }
 i++;
}

double pi = (double)((totalHits - hits)*4)/ totalHits; // Substracting all hits outside the circle leaves us with the hits INSIDE the circle, which is what we want
cout << "π ~ " << (double)pi;
return 0;
}
/* ABSTRACT

    Suppose we draw a 2x2 square in the Cartesian plane, we can treat it as 4 smaller ones with side length 1 each
    Then we draw a circle using the x^2 + y^2 = 1 equation
    Area of a circle can be expressed as A = πr^2, where r is the radius of the circle
    Since the r = 1, the square (consisting of 4 smaller ones) has the area of (2r)^2, or 4r^2
    As such the ratio of circle's area to square area is exactly π / 4

    Suppose we shoot darts into the same circle and square
    The probability of hitting the circle happens to be that same ratio (circle area / square area or π / 4)
    The more throws we perform, the better the estimate

    So we have an equation of 

    π / 4 =  Circle hits / Total number of hits
    Which translates to
    π = 4 * Circle hits / Total number of hits

    And so we will be using RNG and a ton of iterations to calculate π 


*/