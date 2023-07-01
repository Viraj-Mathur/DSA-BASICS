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
        cout<<"ENTER LENGHT OF THE ARRAY: ";
        cin>>length;
        cout<<"ENTER ELEMENTS OF THE ARRAY: ";
        for(int i=0;i<length;i++){
            cin>>A[i];
        }
    }

    void display(){
        cout<<" ";int Delete(int index);
        for(int i=0;i<length;i++){
            cout<<A[i] <<" ";
        }
    }

    int swap(int *x,int *y);
    int LinearSearch(int key);

    ~Array(){
        delete []A;

    

    }
};  

int Array::swap(int *x,int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


int Array::LinearSearch(int key){
    for(int i=0;i<length;i++){
        if(key==A[i]){
            swap(&A[i], &A[0]); // MOVE TO FRONT/HEAD
            // swap(&A[i], &A[i-1]); TRANSPOSION
            cout<<"Linear Search Successsful at index: ";
            return i;
        }
        cout<<"Linear Search Unsuccessful!!";
        return -1;
    }
}
int main(){

    return 0;
}   

/* int search(int arr[], int N, int x)
{
    int i;
    for (i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
*/