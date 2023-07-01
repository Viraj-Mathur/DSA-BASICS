/* FASTER WAY
WHEN EVEN POWER : pow(a*a,n/2);
   WHEN ODD POWER : a*pow(a*a,(n-1)/2);
*/    
#include<iostream>

using namespace std;

int power(int a,int n){
    if(n==0)
    return 1;
    if(n%2==0)
    return power(a*a,n/2);
    else
    return a* power(a*a,(n-1)/2);
}
int main(){
    int r=power(2,9);
    cout<<r;
    return 0;
}