#include<iostream>

struct digitData
{
    int desiredDigits,printedDigits=0;
}alphas,nums,symbo;  //This structure exists only because I felt fancy, and didn't want to use "_" in variable names

int totalDigits;
char alphaKeySet[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
     numKeySet[]="0123456789",
     symboKeySet[]="!@#$%^&*()+-*/",
     password[32];

int main()
{
    srand(time(NULL));
    std::cout<<"Input the no. of letters in your password: "; std::cin>> alphas.desiredDigits;
    std::cout<<"Input the no. of numbers in your password: "; std::cin>> nums.desiredDigits;
    std::cout<<"Input the no. of symbols in your password: "; std::cin>> symbo.desiredDigits;
    totalDigits=alphas.desiredDigits+nums.desiredDigits+symbo.desiredDigits; //To calculate how long the desired password is

    std::cout<<"Your password of "<<totalDigits<<" digits, sire!: \n";

    int i=0;
    labelWhichType:   //A label to allow me to loop the program according to how I intended. Trust me, for and while didn't work
        switch (rand()%3 +1)
        {
        case 1:
            if(alphas.printedDigits>=alphas.desiredDigits) goto labelWhichType;
            password[i]=alphaKeySet[rand()%53];
            alphas.printedDigits++;
            std::cout<<password[i];
            break;
        case 2:
            if(nums.printedDigits>=nums.desiredDigits) goto labelWhichType;
            password[i]=numKeySet[rand()%11];
            nums.printedDigits++;
            std::cout<<password[i];
            break;
        case 3:
            if(symbo.printedDigits>=symbo.desiredDigits) goto labelWhichType;
            password[i]=symboKeySet[rand()%15];
            symbo.printedDigits++;
            std::cout<<password[i];
            break;
        default: std::cout<<"[Debug for Dev]Wrong rand value in loop"<<i<<std::endl; //This statement came in most handy when for and while loops were giving me trouble
        }
        i=alphas.printedDigits+nums.printedDigits+symbo.printedDigits;
    if(i<totalDigits) goto labelWhichType;
    
    return 0;
}
