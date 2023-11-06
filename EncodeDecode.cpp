#include <iostream>
using namespace std;

void encode(char *, int);
void decode(char *, int);

int main()
{
    char whichFunc[6], message[20];
    int shift;

    cout << "Type encode or decode to perform said function: ";
    cin >> whichFunc;
    cout << "Input the Message: ";
    cin >> message;
    cout << "Input the shift: ";
    cin >> shift;

    if (*whichFunc == 'e' || *whichFunc == 'E')
    {
        cout << "The Encoded message: ";
        encode(message, shift);
    }
    else if (*whichFunc == 'd' || *whichFunc == 'D')
    {
        cout << "The Decoded message: ";
        decode(message, shift);
    }
    else
    {
        cout << "Wrong Input!";
        return 0;
    }
    cout << message;
    return 0;
}

void encode(char *m, int s)
{
    while (*m != '\0')
    {
        for (int j = 0; j < s; j++)
        {
            (*m)++;
            if ((*m) > 'z')
                (*m) = 'a';
            else if ((*m) > 'Z' && (*m) < 'a')
                (*m) = 'A';
        }
        m++;
    }
}
void decode(char *m, int s)
{
    while (*m != '\0')
    {
        for (int j = 0; j < s; j++)
        {
            (*m)--;
            if ((*m) < 'A')
                (*m) = 'Z';
            else if ((*m) > 'Z' && (*m) < 'a')
                (*m) = 'z';
        }
        m++;
    }
}
