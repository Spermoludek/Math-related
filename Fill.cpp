#include <iostream>
using namespace std;

unsigned int power = 0;
unsigned int getPower(unsigned int n) { // Length of a number
    if (n == 0) {
        return power;
    }
    power++;
    return getPower(n / 10);
}
unsigned int decimator = 1;
unsigned int exponentialNotation(unsigned int i) { // 10^i 
    if (i == 0) {
        return decimator;
    }
    decimator *= 10;
    return exponentialNotation(i-1);
}




unsigned int getFill(unsigned int n, unsigned int length) {
    return exponentialNotation(length)-1 - n; // 10^(n-1) - 1   -  n 
};
int main() {
    unsigned int n = 0;
    cout << "Please enter a number: ";
    cin >> n;
    !cin || n < 0 ? cout << "Invalid" : (n == 0 ? cout << "The fill of " << n << " is " << getFill(0,1) : cout << "The fill of a number " << n << " is " << getFill(n, getPower(n)) );
     return 0;
}

/* ABSTRACT

    The fill of a number x  can be expressed as 
    x + fill = 10^(n+1) - 1 
    For instance
    fill for 2137
    fill = 9999 - 2137 = 7862
    Basically, we aim to fill the number's length with nines

*/