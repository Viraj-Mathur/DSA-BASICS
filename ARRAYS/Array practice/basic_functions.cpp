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

    void append(class Array *ar, int element)
    {

        if (ar->length < ar->size)
        {
            ar->A[ar->length] = element;
            ar->length++;
        }
    }

    void insert(class Array *ar, int index, int element)
    {

        if (index >= 0 && index <= ar->length)
        {

            for (int i = ar->length - 1; i >= index; i--)
            {

                ar->A[i + 1] = ar->A[i];
            }

            ar->A[index] = element;
            ar->length++;
        }
    }

    void del(class Array *ar, int index)
    {
        int x;
        if (index >= 0 && index <= ar->length)
        {
            x = ar->A[index];

            for (int i = index; i < length; i++)
            {
                ar->A[i] = ar->A[i + 1];
            }

            ar->length--;
            
            cout << "AFTER DELETING THE 6TH INDEXED ELEMENT"<<endl<<"ELEMENT EJECTED IS : " << x <<endl;;
        }
    }
};


int main()
{

    Array a(10);
    a.create();

     a.append(&a,6);
    //	a.insert(&a,0,8);
    // a.del(&a, 6);
    a.display();
}






