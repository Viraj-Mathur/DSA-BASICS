#include<iostream>

using namespace std;

class Array{
    private:
    int *A;
    int size;
    int length;

    public:
    Array(){
        size=0;
        length=0;
    }

    void create_Array(){
        cout<<"Enter size = ";
        cin>>size;
        cout<<"Enter lenght = ";
        cin>>length;

        if(length<= size){
            A = new int[size];
        }
        else{
            size=0; length=0;
            cout<<"Limit of Array exceeded!! "<<endl;
        }
    }

    void set_array(){
        cout<<"Enter element of the array "<<endl;
        for(int i=0;i<length;i++){
            cin>>A[i];
        }
    }

    void display_array(){
        cout<<"The entered array is: ";
        for(int i=0;i<length;i++){
            cout<<A[i]<<" ";
        }
            cout<<endl;
        
        
        }
};


int main(){
    Array A;
    A.create_Array();
    A.set_array();
    A.display_array();

    return 0;
}