// power(a,n-1)*a

#include<iostream>

using namespace std;

int power(int a,int n){
    if(n==0)
        return 1;
    return power(a,n-1)*a;
}

int main(){
    int r=power(2,9);
    cout<<r;    
    return 0;
}