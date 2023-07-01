#include<iostream>

using namespace std;
int swap(int a,int b){
   int temp;
   temp=a;
   a=b;
   b=temp;
}
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    else if(a<b)
    return swap(a,b);
    else 
    return gcd(b,b%a);
}
int main(){
   int a;
   int b;
   cout<<"Enter the numbers: "<<endl;
   cin>>a>>b;
   cout<<gcd(a,b);
   
    return 0;
}