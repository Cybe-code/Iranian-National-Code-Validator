#include <iostream>
#include <string>
using namespace std;

int calcCheckDigit(string code)
{
    int sum = 0, remainder, checkDigit;

    for (int i = 0; i < 9; i++)
        sum += (code[i] - '0') * (10 - i);

    remainder = sum % 11;

    if (remainder < 2)
        checkDigit = remainder;
    else
        checkDigit = 11 - remainder;

    return checkDigit;
}

bool onlyDigits(string code)
{
    for (int i = 0; i < code.length(); i++)
    {
        if (code[i] < '0' || code[i] > '9')
            return false;
    }
    return true;
}

bool allSame(string code)
{
    for (int i = 1; i < code.length(); i++)
    {
        if (code[i] != code[0])
            return false;
    }
    return true;
}

int main()
{
    string code;
    int checkDigit, lastDigit;
    cout<< "enter your national code: ";
    cin>> code;

    if (code.length() != 10)
    {
        cout<< "national code must be 10 digits !!";
        return 0;
    }
    if (!onlyDigits(code))
    {
        cout<< "national code must contain only digits !!";
        return 0;
    }
    if (allSame(code))
    {
        cout<< "you entered fake national code !!";
        return 0;
    }

    lastDigit= code[9] - '0';
    checkDigit= calcCheckDigit(code);

    if (checkDigit== lastDigit)
        cout<< "your national code is correct";
    else
        cout<< "you entered fake national code !!";

    return 0;
}
