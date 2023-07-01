#include<iostream>

using namespace std;

double a(int x,int n){
    double s=1;
    int i;
    double num=1;
    double den=1;

    for(int i=1;i<=n;i++){
        num*=x;
        den*=i;
        s+=num/den;
    }
    return s;
}
int main(){
    double n=a(1,10);
    cout<<n;
    
    
    return 0;
}