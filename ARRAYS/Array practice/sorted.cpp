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
        cout<<"ENTER LENGTH OF THE ARRAY: ";
        cin>>length;
        cout<<"ENTER ELEMENTS OF THE ARRAY: ";
        for(int i=0;i<length;i++){
            cin>> A[i];
        }
    }

    void display(){
        cout<<" THE ELEMENT IN THE ARRAY ARE : ";
        for(int i=0;i<length;i++){
            cout<< A[i] <<" ";
        }
    }

    void insert(Array *arr);
    int isSort(Array *arr);
    void REarrange(Array *arr);
    void swap(int *x, int *y);



};

void Array::insert(Array *arr){
    int x;
    cout<<"ENTER VALUE YOU WANT TO INSERT IN AN  ARRAY : ";
    cin>>x;
    if(arr->length==arr->size){
        return;      //CHECKING FOR FREE SPACE IN AN ARRAY
    }
    int i = arr-> length-1;
    while(i>=0 && arr->A[i]>x){  //i>=0 BECAUSE CHECKING THE CONDITION THAT ELEMENTS WHILE CHECKING SHOULD NOT GO BELOW ZERO.(SMALLEST ELEMENT SHOULD BE AT THE ZEROTH INDEX)
        arr->A[i+1] = arr->A[i];  //SHIFTING THE  LAST ELEMENTS ONE BY ONE UNTIL UNTIL THE GIVEN NUMBER IS GREATER THAN THE ELEMENT AND INSERTING 
        i--;
    }
    arr->A[i+1] = x;
    arr->length++ ;//AS WE INSERT ANOTHER ELEMENT SO LENGTH OF ARRAY SHOULD ALSO BE INCREMENTED

}

// TO CHECK IF THE ARRAY IS SORTED i.e THE ARRAY IS IN ASCENDING ORDER

int Array::isSort(Array *arr){
    int i;
    for(i=0;i<arr->length-1;i++){
        if(arr->A[i]>arr->A[i+1]){
            return 0;
            //cout<<"Array is not sorted";
        }
    }
    return 1;
    //cout<<"Array is sorted";
}

// TO REARRANGE NEGATIVE AND POSITVE ELEMENTS IN AN ARRAY
// swap function
void Array::swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void Array::REarrange(Array *arr){
    int i, j;
    i=0; 
    j=arr->length-1;  
    // i will check for positive no. from the start and j from the end they will swap it.
    while(i<j){
        while(arr->A[i]<0) i++;
        while(arr->A[i]>=0) j--;
        if(i<j)swap(&arr->A[i],&arr->A[j]);
    }
}

int main(){
    Array a(100);
    a.create();
    a.display();
    cout<<endl;
    cout<<endl;
    // a.insert(&a);
    // a.display();
    //cout<<a.isSort(&a)<<endl;

    a.REarrange(&a);
    cout<<"AFTER REARRANGING POSITIVE AND NEGATIVE ELEMENTS !!";
    a.display();
    return 0;
}