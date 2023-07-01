#include<iostream>

using namespace std;
void fun(int n){
    if(n>0){
        cout<<n;
        fun(n-1);
        fun(n-1);
    }
}
int main(){
    fun(3);
    return 0;
}

/*RECURSION TREE

1                                               fun(3)
2               3                               fun(2)                                   fun(2)
4                       2                fun(1)            fun(1)             2          fun(!)         fun(1)
8                                   1 fun(0) fun(0)    1 fun(0) fun(0)             1 fun(0) fun(0)  1 fun(0) fun(0) 
therefore OUTPUT: 3211211
ORDER: 1+2+4+8=15 
FOR N : 2^(n+1)-1

*/
