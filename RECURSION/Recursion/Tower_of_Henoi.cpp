/* Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules: 
    Only one disk can be moved at a time.
    Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
    No disk may be placed on top of a smaller disk.

Time complexity: O(2^n)
Space complexity: O(n)
*/

#include<iostream>
using namespace std;

void TOH(int n,char A,char B,char C){   //n is the number of discs, A is the initial tower, B is the auxiliary tower and C is the destination tower.
    if(n>0){
        TOH(n-1,A,C,B);
        cout << "Move disk " << n << " from rod " << A <<" to rod " << C << endl; 
        TOH(n-1,B,A,C);
    }
}
int main(){
    int n;
    cout<<"Enter how many disk do you want: "<<endl;
    cin>>n;
    TOH(n,'A','B','C');
    return 0;
}