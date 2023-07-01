#include<iostream>

using namespace std;

void fun(int n){
    if(n>0){
        cout<<n;
        
        fun(n-1);
        
        cout<<n;
    }
}
int main(){
    int x=4;
    fun(x);

    return 0;
}