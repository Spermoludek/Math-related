#include <iostream>
#include <vector>
using namespace std;

void changeBase(int num, unsigned int base) {
    vector<int> target;
    while (num > 1)  {
        target.push_back(num % base);
        num /= base;
    }
    for (int i = 0; i < target.size(); i++ ) {
        cout << target[i] << "\t"; 
    }

}

int main() {
  
    cout << "Program converting a number in base 10 to any given base \n";
    int num = 0, base = 0;
    cout << "Enter a number in base 10: ";
    cin >> num;
    cout << "Enter the new base of your number: ";
    cin >> base;
    if (!cin || num < 0 || base <= 0) {
        cout << "What the fuck are you smoking brother";
        return 1; 
    }
    changeBase(num, base);
    return 0;
}
/* ABSTRACT
    The formula to convert a number from base A to base B is to repeatedly divide it by the number base and save the remainder
    And this is basically what the program does. 
*/