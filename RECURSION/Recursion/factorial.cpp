#include<iostream>

using namespace std;

int fact(int n){
    if (n==0){
        return 1;
    }
        else{
        return fact(n-1)*n;
        }
}
int main(){
    int a,b;
    cout<<"Enter Number : ";
    cin>>a;
    b=fact(a);
    cout<<"The factorial of the given number is: "<<b<<endl;
    return 0;
}