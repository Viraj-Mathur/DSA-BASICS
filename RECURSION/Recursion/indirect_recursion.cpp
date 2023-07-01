// INDIRECT OR MUTUAL RECURSION: If the function f1 calls another function f2 and f2 calls f1 then it is indirect recursion.

#include<iostream>

using namespace std;
void fun2(int n);  //Declaring the function
void fun1(int n){
    if(n>0){
        cout<<n<<" ";
        fun2(n-1);
    }
}

void fun2(int n){
    if(n>1){
        cout<<n<<" ";
        fun1(n/2);
    }
}
int main(){
    
    fun1(20);
    return 0;
}

/* RECURSION TREE
      fun1(20)
    20     fun2(19)
         19      fun1(9)
               9    fun2(8)
                  8      fun1(4)
                      4        fun2(3)
                            3    fun1(1)
                                1    fun2(0)
                                        0  
*/
