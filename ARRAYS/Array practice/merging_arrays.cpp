#include<iostream>

using namespace std;

class Array{
private:
    int size;
    int lenght;
    int *A;

public:
    Array(int size){
        this->size=size;
        A = new int[size];
    }

    void create(){
        cout<<"ENTER LENGHT OF THE ARRAY: ";
        cin>>lenght;
        cout<<"ENTER ELEMENTS OF THE ARRAY: ";
        for(int i=0;i<lenght;i++){
            cin>>A[i];
        }
    }

    void display(){
        cout<<" ";
        for(int i=0;i<lenght;i++){
            cout<<A[i] <<" ";
        }
    }
    
    Array merge(Array x){  // as return type of the function is an Array 
        Array a(20);
        a.lenght = lenght + x.lenght;
        int i=0,j=0,k=0;  // i,j,k are increment variables of 2 comparable array and the merged array
        while(i<lenght && j<x.lenght){
            //COMPARING BOTH ELEMENTS IN THE ARRAY AND SMALLER ELEMENT GOING TO THE MERGED ARRAY AND THEN INCREMENTING
            if(A[i]<x.A[j]){
                a.A[k++] = A[i++];
            }  
            else{
                a.A[k++] = A[j++];
            }
        }

        // FOR REMAINING ELEMENTS: 
        for(;i<lenght;i++){ // ; this symbolises wherever the cuurent position of i is
            a.A[k++] = A[i];
        }
        for(;j<x.lenght;j++){
            a.A[k++] = x.A[j];
        }

        return a;
    }


};

int main(){
    Array a1(10);
    Array a2(10);

    Array a3(20);  //THE MERGED ARRAY

    a1.create();
    a2.create();
    cout<<"THE FIRST ARRAY IS: "<<endl;
    a1.display();
    cout<<endl;
    cout<<"THE SECOND ARRAY IS: "<<endl;
    a2.display();
    cout<<endl;
    
    a3 = a1.merge(a2);
    cout<<"AFTER MERGING ELEMENTS IN THE ARRAY ARE: "<<endl;
    a3.display();

    return 0;
    

    return 0;
}