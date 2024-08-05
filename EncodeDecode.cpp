#include <iostream>
using namespace std;

void encode(string&, int);
void decode(string&, int);

int main() {
    string whichFunc, message;
    int shift;

    cout << "Type encode or decode to perform said function: ";
    cin >> whichFunc;
    cout << "Input the Message: ";
    cin >> message;
    cout << "Input the shift: ";
    cin >> shift;

    if (whichFunc[0] == 'e' || whichFunc[0] == 'E') {
        cout << "The Encoded message: ";
        encode(message, shift);
    } else if (whichFunc[0] == 'd' || whichFunc[0] == 'D') {
        cout << "The Decoded message: ";
        decode(message, shift);
    } else {
        cout << "Wrong Input!";
        return 0;
    }
    cout << message;
    return 0;
}

void encode(string& m, int s) {
    for (int i = 0; i < m.length(); i++) {
        if ('a' <= m[i] && m[i] <= 'z')
            m[i] = (m[i] - 'a' + s) % 26 + 'a';
        else if ('A' <= m[i] && m[i] <= 'Z')
            m[i] = (m[i] - 'A' + s) % 26 + 'A';
    }
}
void decode(string& m, int s) {
    for (int i = 0; i < m.length(); i++) {
        if ('a' <= m[i] && m[i] <= 'z')
            m[i] = (m[i] - 'a' - s + 26) % 26 + 'a';
        else if ('A' <= m[i] && m[i] <= 'Z')
            m[i] = (m[i] - 'A' - s + 26) % 26 + 'A';
    }
}
