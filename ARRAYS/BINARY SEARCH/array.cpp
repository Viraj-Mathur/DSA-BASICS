#include<iostream>

using namespace std;

class Array{
private:
    int size;
    int length;
    int *A;

public:
    Array(int size){
        this->size=size;
        A = new int[size];
    }

    void create(){
        cout<<"Enter length of the Array: ";
        cin>>length;
        cout<<"Enter elements of the Array: ";
        for(int i=0;i<length;i++){
            cin>> A[i];
        }
    }

    void display(){
        cout<<" The elements in the array are: ";
        for(int i=0;i<length;i++){
            cout<< A[i] <<" ";
        }
    }



};

int main(){
    Array a(100);
    a.create();
    a.display();
    return 0;
}