
#include <iostream>
#include <cmath>
using namespace std;

int n, sum, num = 0;
int getPower(int num) { // Number's length
    if (num == 0) {
        return n; 	
    }
    n++;
    return getPower(num / 10);
}
int calculateSum(int num, int n) {
        if (num == 0) {
        return sum; 
    }
    sum += pow((num % 10), n); 		// We are summing up each digit raised to the length's power
    return calculateSum(num / 10, n);
}


int main() {
    cout << "Please enter a number: ";
    cin >> num;
    if (calculateSum(num, getPower(num)) == num) {
        cout << "Number you entered is an Armstrong number";
    }
    else {
        cout << "Number you entered is not an Armstrong number";
    }
    return 0;
}
/*
ABSTRACT:
An Armstrong number is a number that's equal to sum of its digits raised to the power of number's length

For instance 153 = 1^3 + 5^3 + 3^3

Here are some Armstrong numbers:
153, 370, 407, 8208, 1634, 9474. 548834


Please note that this is a terrible way of doing this and there probably is an algorithmically faster method, but we all start somewhere
*/
