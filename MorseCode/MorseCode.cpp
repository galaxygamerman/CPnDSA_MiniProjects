#include <iostream>
#include <map>
#include <string>
#include <bits/stdc++.h>
// #include <sstream>
using namespace std;

class conversions
{
private:
    map<char, string> TtoM;
    map<string, char> MtoT;

public:
    conversions();
    ~conversions();
    void textToMorse(string query);
    void morseToText(string query);
    void print_hash()
    {
        for (const auto &[key, value] : TtoM)
        {
            std::cout << key << " : " << value << '\n';
        }
        std::cout << "-------------------------------\n";
        for (const auto &[key, value] : MtoT)
        {
            std::cout << key << " : " << value << '\n';
        }
    }
    void print_title()
    {
        std::cout << " .      ____  ....  ____  .....   ___   ...  ____  ..... \n"
             << "/ \\__/|/  - \\/  __\\/ ___\\/  __/  /  _\\ /   \\/ __ \\/  __/ \n"
             << "| |\\/||| / \\||  \\/||    \\|  \\   |  /  | / \\|| | \\||  \\ \n"
             << "| |  ||| \\_/||    /\\___ ||  /_  |  \\__| \\_/|| |_/||  /_ \n"
             << "\\_/  \\|\\____/\\_/\\_\\\\____/\\____\\ \\____/\\____/\\____/\\____\\ \n";
    }
};

conversions::conversions()
{
    TtoM['a'] = ".-";
    TtoM['b'] = "-...";
    TtoM['c'] = "-.-.";
    TtoM['d'] = "-..";
    TtoM['e'] = ".";
    TtoM['f'] = "..-.";
    TtoM['g'] = "--.";
    TtoM['h'] = "....";
    TtoM['i'] = "..";
    TtoM['j'] = ".---";
    TtoM['k'] = "-.-";
    TtoM['l'] = ".-..";
    TtoM['m'] = "--";
    TtoM['n'] = "-.";
    TtoM['o'] = "---";
    TtoM['p'] = ".--.";
    TtoM['q'] = "--.-";
    TtoM['r'] = ".-.";
    TtoM['s'] = "...";
    TtoM['t'] = "-";
    TtoM['u'] = "..-";
    TtoM['v'] = "...-";
    TtoM['w'] = ".--";
    TtoM['x'] = "-..-";
    TtoM['y'] = "-.--";
    TtoM['z'] = "--..";
    TtoM[' '] = " ";
    TtoM['0'] = "-----";
    TtoM['1'] = ".----";
    TtoM['2'] = "..---";
    TtoM['3'] = "...--";
    TtoM['4'] = "....-";
    TtoM['5'] = ".....";
    TtoM['6'] = "-....";
    TtoM['7'] = "--...";
    TtoM['8'] = "---..";
    TtoM['9'] = "----.";

    for (const auto &[key, value] : TtoM) // To automatically set the MtoT map
    {
        MtoT[value] = key;
    }
}

conversions::~conversions()
{
    TtoM.clear();
    MtoT.clear();
}

void conversions::textToMorse(string query)
{
    std::cout << query << " in Morse Code is: ";
    for (int i = 0; query[i] != '\0'; i++)
    {
        std::cout << TtoM[query[i]] << " ";
    }
}

void conversions::morseToText(string query)
{
    std::cout << query << " in text is: ";
    string subquery;
    stringstream querystream(query);

    while (getline(querystream, subquery, ' '))
    {
        std::cout << MtoT[subquery];
        // std::cout<<' ';
    }
}

int main()
{
    int choice;
    string query;
    conversions conv;
    conv.print_title();
    // conv.print_hash(); //Used during testing to check whether hashtable is initialised properly
    do
    {
        std::cout << "MENU" << endl
             << "Type 1 to convert Text to Morse Code" << endl
             << "Type 2 to convert Morse Code to Text" << endl
             << "Type 3 to exit" << endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter the Text you want to convert: ";
            cin.ignore(1, '\n'); // To get rid of the stray '\n' in buffer due to cin
            getline(cin, query);
            conv.textToMorse(query);
            break;
        case 2:
            std::cout << "Enter the Morse Code you want to convert: ";
            cin.ignore(1, '\n'); // To get rid of the stray '\n' in buffer due to cin
            getline(cin, query);
            conv.morseToText(query);
            break;
        case 3:
            std::cout << "\nExiting...";
            exit(0);
        default:
            std::cout << "Invalid Input!";
            break;
        }
        std::cout << endl
             << endl;
    } while (choice != 3);

    return 0;
}
