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
    void swap(int *x, int *y);
    void reversearray(class Array *ar);

     
};
void Array::swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void Array::reversearray(class Array *arr){
	// int start=0,end= length-1;
	// while(end>=length){
	// 	swap(A[start],A[end]);
	// 	start++;
	// 	end--;
	// }
    for(int i=0,j=(arr->length-1);i<j;i++,j--)
        swap(&arr->A[i],&arr->A[j]);
    }    


int main(){
    Array A(100);
    A.create();
    A.display();
    cout<<endl;
    A.reversearray(&A);
    A.display();

    return 0;
}