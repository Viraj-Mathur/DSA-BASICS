#include <iostream>

using namespace std;

class Array
{
private:
    int size;
    int length;
    int *A;

public:
    // Constructor
    Array(int size)
    {
        this->size = size;
        A = new int[size];
    }

    // Function to create an array
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

    // Function to display the array elements
    void display()
    {
        cout << "THE ELEMENTS IN THE ARRAY ARE : ";
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << "  ";
        }
        cout << endl;
    }

    // Function to perform left shift
    void lshift();
    
    // Function to perform right shift
    void rshift();
    
    // Function to perform left rotation
    void lRotate();
    
    // Function to perform right rotation
    void rRotate();

    // Function to get the length of the array
    int getLength() const;

    // Destructor
    ~Array();
};

int Array::getLength() const {
    return length;
}

void Array::lshift(){
    for(int i = 0; i < length - 1; i++){
        A[i] = A[i+1];
    }
    A[length - 1] = 0;
}

void Array::rshift(){
    for(int i = length - 1; i > 0; i--){
        A[i] = A[i-1];
    }
    A[0] = 0;
}

void Array::lRotate(){
    int first = A[0];
    for(int i = 0; i < length - 1; i++){
        A[i] = A[i+1];
    }
    A[length - 1] = first;
}

void Array::rRotate(){
    int last_element = A[length - 1];
    for(int i = length - 1; i > 0; i--){
        A[i] = A[i-1];
    }
    A[0] = last_element;
}

Array::~Array(){
    delete[] A;
}

int main(){
    int num;
    
    cout << "Enter number of times to left rotate: ";
    cin >> num;

    Array A(100);
    A.create();
    
    cout << "ELEMENTS IN THE ARRAY BEFORE OPERATIONS:" << endl;
    A.display();
    cout << endl;

    // Actual rotation
    num = num % A.getLength();
    
    cout << "ELEMENTS IN THE ARRAY AFTER LEFT SHIFT:" << endl;
    A.lshift();
    A.display();
    cout << endl;

    cout << "ELEMENTS IN THE ARRAY AFTER RIGHT SHIFT:" << endl;
    A.rshift();
    A.display();
    cout << endl;

    cout << "ELEMENTS IN THE ARRAY AFTER LEFT ROTATION:" << endl;
    A.lRotate();
    A.display();
    cout << endl;

    cout << "ELEMENTS IN THE ARRAY AFTER RIGHT ROTATION:" << endl;
    A.rRotate();
    A.display();
    cout << endl;

    return 0;
}
