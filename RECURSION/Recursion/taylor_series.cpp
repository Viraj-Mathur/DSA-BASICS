#include<iostream>

using namespace std;

double e(int x,int n){ //as result will be float
    static double p=1,f=1; //taking static variables
    double r;

    if(n==0)
    return 1;
    r=e(x,n-1);
    p=p*x;
    f=f*n;
    return r+p/f;
}

int main(){
    double a=e(1,10);
    cout<<a<<endl;
    return 0;
}