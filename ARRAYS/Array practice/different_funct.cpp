// c++ source code for get(), set(), min(), max(), sum(), avg()
#include <iostream>

using namespace std;

class Array
{
private:
    int size;
    int length;
    int *A;

public:
    Array(int size)
    {
        this->size = size;
        A = new int[size];
    }

    void create()
    {
        cout << "ENTER THE LENGTH OF ARRAY : ";
        cin >> length;
        cout << "ENTER THE ELEMENTS : ";
        for (int i = 0; i < length; i++)
        {
            cin >> A[i];
        }
    }

    void display()
    {
        cout << "THE ELEMENTS IN THE ARRAY ARE : ";
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << "  ";
        }
    }
    
    int max();
    int min();
    int sum();
    int avg();
    ~Array();

     
};

int Array:: max(){
    int max;
    max = A[0];
    for(int i=0;i<length;i++){
        if(A[i]>max){
            max = A[i];
        }
    } 
    return max;
}

int Array::min(){
    int min;
    min = A[0];
    for(int i=0;i<length;i++){
        if(A[i]<min){
            min = A[i];
        }
    }
    return min;
}

int Array::sum(){
    int sum = 0;
    for(int i=0;i<length;i++){
        sum = sum + A[i];
    }
    return sum;
}

int Array::avg(){
    int sum = 0;
    for(int i=0;i<length;i++){
        sum = sum + A[i];
    } 
    return sum/length;
}

Array::~ Array(){
    delete [] A;
}

int main(){
    Array A(100);
    A.create();
    A.display();
    cout<<endl;

    cout<<"Maximum Element in the Array is: "<<endl;
    cout<<A.max()<<endl;

    cout<<"Minimum Element in the Array is: "<<endl;
    cout<<A.min()<<endl;

    cout<<"Sum of the given Array is: "<<endl;
    cout<<A.sum()<<endl;

    cout<<"Average of the given Array is: "<<endl;
    cout<<A.avg()<<endl;

    //A.~Array();


    return 0;
}