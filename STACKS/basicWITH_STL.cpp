#include<iostream>
#include<stack>

using namespace std;


int main(){
    // creating stack
    stack<int> s;
    // push operation
    s.push(2);
    s.push(3);
    cout<<"Top Element is: "<<s.top()<<endl;

    // for determining size
    cout<<"Size of stack is: "<<s.size()<<endl;
    // pop operation
    s.pop();
    cout<<"Top Element is: "<<s.top()<<endl;

    if(s.empty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    s.pop();

    if(s.empty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }

    return 0;
}