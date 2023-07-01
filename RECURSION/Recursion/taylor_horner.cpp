#include<iostream>

using namespace std;

double a(int x, int n){
    static double s;
    if(n==0)
        return s;
    s=1+x*s/n;
    return a(x,n-1);
}
int main(){
    double e;
    e=a(1,10);
    cout<<e<<endl;

    return 0;
}