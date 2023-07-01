#include<iostream>

using namespace std;
int fun(int n){
    static int x=0;
    if(n>0){
        x++;
        return fun(n-1)+x;
    }
    return 0;
}
int main(){
    int a=5;
    cout<<fun(a);
    return 0;
}

/*RECURSION TREE

AS STATIC VALUE OF X WILL HAVE ONLY SINGLE COPY
X=0->1->2->3->4->5
fun(5)=25
fun(4)+5=25
fun(3)+5=20
fun(2)+5=15
fun(1)+5=10
fun(0)+5=5
*/
