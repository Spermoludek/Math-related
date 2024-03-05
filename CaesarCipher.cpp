#include <iostream>
#include <cctype>
#include <string> 
using namespace std;

string encode(int key,  string text) {
    int i = 0;
    key %= 26; // Letter shift
    while (text[i] != '\0') {
        text[i] = tolower(text[i]); // Uppercase letters are a real pain in the ass
        text[i] = (int)text[i] > 122 - key // Prevents going out of range
        ?  (char)((int)text[i]+ key - 26)
        : (char)((int)text[i]+key); 
        i++;
    }
    return text; 
}
string decode(int key, string text) {
    int i = 0; 
    key %= 26; // Letter shift
    
    while (text[i] != '\0') // Until we don't reach the end of a string
    {
        text[i] = tolower(text[i]);
        text[i] = (int)text[i] - key < 97 
        ? (char)((int)text[i] - key + 26) // We simply go back to the prev char
        : (char)((int)text[i] - key);
        i++;
    }
    return text;
}



int main() {

string text;
int key;

cout << "Enter the key (press 3 for Caesar's cipher): ";
cin >> key;
if (!cin || key <= 0) {
    cout << "Invalid input!\n";
    return 1;
}


cout << "Text to encode: ";
cin >> text;
string enctext = encode(key, text);
cout << "Encoded text:\t" << enctext << "\n";
string dectext = decode(key, enctext);
cout << "Decoded text:\t" << dectext;


return 0;
}

/* ABSTRACT
Caesar's Cipher is a simple encryption algorithm that replaces all letters in a text with chars N letters ahead. For instance A ==> D
is a 3 letter Caesar's Cipher 

It's been quite a while since I dropped anything, but yeah here's something to warm back up 

*/