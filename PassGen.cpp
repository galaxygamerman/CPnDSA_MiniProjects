#include<iostream>
using std::cout;
using std::cin;
using std::endl;

//This structure exists only because I felt fancy, and didn't want to use "_" in variable names
struct digitData
{
    int desiredDigits,printedDigits=0;
}alphas,nums,symbo;

int totalDigits;
char alphaKeySet[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
     numKeySet[]="0123456789",
     symboKeySet[]="!@#$%^&*()+-*/",
     password[32];

int main()
{
    srand(time(NULL));
    cout<<"Input the no. of letters in your password: "; cin>> alphas.desiredDigits;
    cout<<"Input the no. of numbers in your password: "; cin>> nums.desiredDigits;
    cout<<"Input the no. of symbols in your password: "; cin>> symbo.desiredDigits;

    totalDigits=alphas.desiredDigits+nums.desiredDigits+symbo.desiredDigits; //To calculate how long the desired password is


    cout<<"Your password of "<<totalDigits<<" digits, sire!: \n";

    int i=0;
    labelWhichType:  //A label to allow me to loop the program according to how I intended. Trust me, for and while didn't work well
        switch (rand()%3 +1)
        {
            //Aphabets
        case 1:
            if(alphas.printedDigits>=alphas.desiredDigits) goto labelWhichType;
            password[i]=alphaKeySet[rand()%53];
            alphas.printedDigits++;
            cout<<password[i];
            break;

            //Numbers
        case 2:
            if(nums.printedDigits>=nums.desiredDigits) goto labelWhichType;
            password[i]=numKeySet[rand()%11];
            nums.printedDigits++;
            cout<<password[i];
            break;

            //Symbols
        case 3:
            if(symbo.printedDigits>=symbo.desiredDigits) goto labelWhichType;
            password[i]=symboKeySet[rand()%15];
            symbo.printedDigits++;
            cout<<password[i];
            break;

            //Incase anything went wrong
        default: cout<<"[Debug for Dev]Wrong rand value in loop"<<i<<endl;
        }
        i=alphas.printedDigits+nums.printedDigits+symbo.printedDigits;

    if(i<totalDigits) goto labelWhichType; //To loop back
    
    return 0;
}