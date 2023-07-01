#include<iostream>
 
using namespace std;
 
struct Array 
{
    int A[20];
    int size;
    int length;
 
    void display()
    {
        for(int i=0; i<length; i++)
            cout<<A[i]<<" ";
        cout<<endl;
    } 
};
 
void lShift(Array *arr)
{
    for(int i=0; i<arr->length-1; i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = 0;
}
 
void rShift(Array *arr)
{
    for(int i=arr->length-1; i>0; i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = 0;
}
 
void lRotation(Array *arr)
{
    int first_elem = arr->A[0];
    for(int i=0; i<arr->length-1; i++)
    {
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = first_elem;
}
 
void rRotation(Array *arr)
{
    int last_elem = arr->A[arr->length-1];
    for(int i=arr->length-1; i>0; i--)
    {
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = last_elem;
}
 
int main(){
 
    Array arr = {{2, 3, 5 ,6, 7, 9}, 20, 6};
 
    arr.display();
    lShift(&arr);
    arr.display();
    rShift(&arr);
    arr.display();
 
    arr.display();
    lRotation(&arr);
    rRotation(&arr);
    arr.display();
    return 0;
}