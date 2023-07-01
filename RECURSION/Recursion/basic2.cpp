#include<iostream>

using namespace std;
int fun(int n){
    if(n>0){
        return fun(n-1)+n;
    }
    return 0;
}
int main(){
    int a;
    a=fun(5);
    cout<<a;
    return 0;
}

// RECURSION TREE:
// fun(5)=15
// fun(4)+5=15
// fun(3)+4=10
// fun(2)+3=6
// fun(1)+2=3
// fun(0)+1=1
// fun(0)=0
