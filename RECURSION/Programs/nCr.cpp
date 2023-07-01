#include <iostream>

using namespace std;

int fact(int n)  //SIMPLE FUNCTION
{
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}


int nCr(int n, int r) //RECURSIVE FUNCTION
{
    int num, den;
    num = fact(n);
    den = fact(r) * fact(n - r);
    return num / den;
}

int nCr(int n, int r) // RECURSIVE FUNCTION USING ADDITION
{ 
    if (n == r || r == 0)
    {
        return 1;
    }
    else
    {
        return nCr(n - 1, r - 1) + nCr(n - 1, r);
    }
}
int main()
{
    int a, b, c;
    cout << "Enter the value of n: " << endl;
    cin >> a;
    cout << "Enter the value of r: " << endl;
    cin >> b;
    c = nCr(a, b);
    cout << "The value of nCr is: " << c << endl;
    return 0;
}