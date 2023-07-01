// CODE FOR LEFT SHIFT , RIGHT SHIFT AND ROTATION OF ARRAY
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
    
    void lshift(Array *ar);
    void rshift(Array *ar);
    void lRotate(Array *ar);
    void rRotate(Array *ar);

    ~Array();

     
};

void Array::lshift(Array *ar){
    for(int i=0;i<ar->length-1;i++){
        ar->A[i] = ar->A[i+1];  //shifting the array to left
    }
    ar->A[ar->length-1] = 0;  //MAKING THE LAST ELEMENT 0
}

void Array::rshift(Array *ar){
    for(int i=ar->length-1; i>0; i--){  //RIGHT TRAVERSING
        ar->A[i] = ar->A[i-1]; 
    }
    ar->A[0] = 0;  //MAKING THE FIRST ELEMENT 0
}

// void Array::lRotate(Array *ar){
//     int first_element = ar->A[0];  
//     for(int i=0;i<ar->length-1;i++){
//         ar->A[i] = ar->A[i+1];
//     }
//     ar->A[ar->length-1] = first_element;
// }

void Array::lRotate(Array *ar){
    int first = ar->A[0];
    for(int i=0;i<length-1;i++){
        ar->A[i] = ar->A[i+1]; // Moving each array element to its left
    }

    ar->A[length -1] = first; // Copying the first element of array to last

}

void Array::rRotate(Array *ar){
    int last_element = ar->A[ar->length -1];
    for(int i=ar->length-1; i>0; i--){
        ar->A[i] = ar->A[i-1];
    }
    ar->A[0] = last_element;
}

Array::~ Array(){
    delete [] A;
}

int main(){
    int i, num;
    cout<<"Enter number of times to left rotate: ";
    cin>>num;
 
    // Actual rotation
    num = num % size;
    
    Array A(100);
    A.create();
    A.display();
    cout<<endl;
    cout<<endl;
    
    cout<<"ELEMENTS IN THE ARRAY AFTER LEFT SHIFT ARE: "<<endl;
    A.lshift(&A);
    A.display();
    cout<<endl;
    cout<<endl;

    cout<<"ELEMENTS IN THE ARRAY AFTER RIGHT SHIFT ARE: "<<endl;
    A.rshift(&A);
    A.display();
    cout<<endl;
    cout<<endl;

    cout<<"ELEMENTS IN THE ARRAY AFTER LEFT ROTATION ARE: "<<endl;
    A.lRotate(&A);
    A.display();
    cout<<endl;
    cout<<endl;

    cout<<"ELEMENTS IN THE ARRAY AFTER RIGHT ROTATION ARE: "<<endl;
    A.rRotate(&A);
    A.display();
    cout<<endl;
    cout<<endl;



    //A.~Array();


    return 0;
}