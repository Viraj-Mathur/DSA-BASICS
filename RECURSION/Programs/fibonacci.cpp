/* program to generate series of fibonacci series upto n terms!!
     fib(n-1)+fib(n-2);
*/ 
    
#include<iostream>

using namespace std;

int fib(int n){
    if(n==0){
        return 0;
        }
        else if(n==1){
            return 1;
      
        }
        else 
        return fib(n-1)+fib(n-2);
    }

int main(){
    int num;
    cout<<"Enter the number: ";
    cin>>num;
    for(int i=0;i<=num;i++){
        cout<<fib(i)<<" ";
    }
    cout<<endl;
    return 0;
}