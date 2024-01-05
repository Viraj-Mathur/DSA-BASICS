#include<iostream>

using namespace std;

class Array{
private:
    int size;
    int length;
    int *A;
    void swap(int *x,int *y);

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

    ~Array(){
        delete []A;
    }

    void Append(int x);
    void Insert(int index,int x);
    void Set(int index,int x);
    void Reverse(class Array *arr);
    void InsertSort(int x);
    void Rearrange();
    int Delete(int index);
    int LinearSearch(int key);
    int BinarySearch(int key);
    int Get(int index);
    int Max();
    int Min();
    int Sum();
    int isSort();
    float Avg();
    
    Array * Merge(Array arr2);
    Array * Union(Array arr2);
    Array * Difference(Array arr2);
    Array * Intersection(Array arr2);


};

void Array::
Append(int x){
    if(length<size){
        A[length++] = x;
    }
}

void Array::Insert(int index,int x){
    int i;
    if(index>=0 && index <=length){
        for(i=length;i>index;i--){
            A[i] = A[i-1];
            A[index] = x;
            length++;   
        }
    }
}

int Array::Delete(int index){
    int x = 0;
    int i;

    if(index>=0 && index<length){
        x = A[index];
        for(i=index;i<length-1;i++){
            A[i] = A[i+1];
            length-- ;
            return x;
        }
        return 0;
    }
}

void Array::swap(int *x,int *y){
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

int Array::BinarySearch(int key){
    int l,mid,h;
    l=0;
    h=length-1;

    while(l<=h){
        mid =(l+h)/2;
        if (key==A[mid])
            return mid;
        else if(key<A[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

int Array::Get(int index){
    if(index>=0 && index<length){
         return A[index];
    }
    return -1;
}

void Array::Set(int index,int x){
    if(index>=0 && index<length){
        A[index] = x;
    }
}

int Array::Max(){
    int max=A[0];
    for(int i=1;i<length;i++){
        if(A[i]>max)
        max=A[i];
    }
    return max;
}

int Array::Min(){
    int min = A[0];
    for(int i=0;i<length;i++){
        if(A[i]<min){
            min=A[i];
        }
    }
    return min;
}

int Array::Sum(){
    int sum=0;
    for(int i=0;i<length;i++){
        sum=sum+A[i];
    }
    return sum;
}

float Array::Avg(){
    return (float)Sum()/length;
}

void Array::Reverse(class Array *arr){
    int i,j;
    for(i=0,j= length-1;i<j;i++,j--){
        swap(& A[i],& A[j]);
    }
}

void Array::InsertSort(int x){
    int i = length-1;
    cout<<"ENTER VALUE YOU WANT TO INSERT IN AN  ARRAY : ";
    if(length==size)
       return;
    while(i>=0 && A[i]>x){
        A[i+1] = A[i];
        i--; 
    }
    A[i+1] = x;
    length++;   
}

int Array::isSort(){
    int i;
    for(i=0;i<length-1;i++){
        if(A[i]>A[i+1]){
            return 0;
        }
    }
    return 1;
}

void Array::Rearrange(){
    int i,j;
    i=0;
    j=length-1;
    while(i<j){
        while(A[i]<0) i++;
        while(A[i]>=0) j--;
        if(i<j)swap(&A[i], &A[j]);
    }
}

Array* Array::Merge(Array arr2){
    int i,j,k;
    Array *arr3 = new Array(length+arr2.length);
    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j]){
            arr3->A[k++] = A[i++];
        }
        else if(arr2.A[j]<A[i]){
            arr3->A[k++] = arr2.A[j++];  
        }
        else{
            arr3->A[k++] = A[i++];
        }
    }
    for(;i<length;i++){
        arr3->A[k++] = A[i];
    }
    for(;j<arr2.length;j++){
        arr3->A[k++] = arr2.A[j];
    }

    arr3->length = k;
    return arr3;
}

Array* Array::Intersection(Array arr2){
    int i,j,k;
    i=j=k=0;
    Array *arr3=new Array(length+arr2.length);
    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j]){
            i++;
        }
    else if(arr2.A[j]<A[i]){
        j++;
        }    
    else if(A[i]==arr2.A[j]){
        arr3->A[k++] = A[i++];
        j++;
        }
    }
    arr3->length=k;
    return arr3;
}

Array* Array::Difference(Array arr2){
    int i,j,k;
    i=j=k=0;

    Array *arr3=new Array(length+arr2.length);

    while(i<length && j<arr2.length){
        if(A[i]<arr2.A[j]){
            arr3->A[k++] = A[i++];
        }
        else if(arr2.A[j]<A[i]){
            j++;
        }
        else{
            j++;
            i++;
        }
    }
    for(;i<length;i++)
        arr3->A[k++]=A[i];arr3->length=k;
    
    return arr3;
}

int main(){
    cout<<"### THIS IS A PROGRAM WHICH CONTAINS VARIOUS ARRAY OPERATIONS!!"<<endl;
    cout<<" ";
    
    Array *arr1;
    Array *arr2;
    Array *arr3;
    int ch,size;
    int x,index;
    cout<<"### LET US START!!!!!!!!!!"<<endl;

    arr1 = new Array(20);
    arr1->create();
    // arr2 = new Array(20);
    // arr3 = new Array(60);

    do{
        cout<<"### CHOOSE YOUR DESIRED OPTION FROM THE LIST BELOW: "<<endl;
        cout<<" "<<endl;
        cout<<"\n\nMenu\n";
        cout<<"1. DISPLAY YOUR ARRAY \n";
        cout<<"2. INSERT AN ELEMENT IN THE ARRAY \n";
        cout<<"3. DELETE AN ELEMENT IN THE ARRAY \n";
        cout<<"4. LINEARLY SEARCH THE ELEMENT IN THE ARRAY\n";
        cout<<"5. BINARY SEARCH THE ELEMENT IN THE ARRAY\n";
        cout<<"6. SUM OF THE ELEMENTS IN THE ARRAY\n";
        cout<<"7. AVERAGE OF THE ELEMENTS IN THE ARRAY\n";
        cout<<"8. APPEND AN ELEMENT IN THE ARRAY\n";
        cout<<"9. REVERSE YOUR ARRAY\n";
        cout<<"10. MAXIMUM ELEMENT IN THE ARRAY\n";
        cout<<"11.MINIMUM ELEMENT IN THE ARRAY\n";
        cout<<"12.GET THE ELEMENT BY INDEX\n";
        cout<<"13.MERGING WITH ANOTHER ARRAY\n";
        cout<<"14.UNION OF TWO ARRAYS \n";
        cout<<"15.DIFFERENCE OF TWO ARRAYS \n";
        cout<<"16.INTERSECTION OF TWO ARRAYS \n";
        
        cout<<"17.Exit\n";
        cin>>ch;

        switch(ch){
            case 1:cout<<"YOUR INSERTED ARRAY IS: "<<endl;
            arr1->display();
            break;
            case 2: cout<<"ENTER ELEMENT AND INDEX RESPECTIVELY :  ";
            cin>>x>>index;
            arr1->Insert(index,x);
            break;
            case 3: cout<<"ENTER INDEX OF THE ELEMENT YOU WANT TO DELETE: ";
            cin>>index;
            x=arr1->Delete(index);cout<<"DELETED ELEMENT IS : "<<x;
            cout<<"AFTER DELETION YOUR ARRAY IS :"<<endl;
            arr1->display();
            break;
            case 4:cout<<"ENTER AN ELEMENT YOU WANT TO SEARCH";
            cin>>x;
            index=arr1->LinearSearch(x);
            cout<<"ELEMENT INDEX "<<index;
            break;
            case 5:cout<<"ENTER AN ELEMENT YOU WANT TO SEARCH: ";
            cin>>x;
            index=arr1->BinarySearch(x);
            cout<<"ELEMENT INDEX "<<index;
            break;
            case 6:cout<<"SUM OF THE GIVEN ARRAY IS:  "<<arr1->Sum();
            break;
            case 7:cout<<"AVERAGE OF THE GIVEN ARRAY IS:  "<<arr1->Avg();
            break;
            case 8:cout<<"ENTER ELEMENT YOU WANT TO APPEND IN THE ARRAY: ";
            cin>>x;
            arr1->Append(x);
            cout<<"AFTER APPENDING YOUR GIVEN ARRAY IS: ";
            arr1->display();
            break;
            case 9:cout<<"AFTER REVERSING, YOUR ARRAY IS:  ";
            arr1->Reverse(arr1);
            break;
            case 10:cout<<"MAXIMUM ELEMENT OF THE GIVEN ARRAY IS:  "<<arr1->Max();
            break;
            case 11:cout<<"MINIMUM ELEMENT OF THE GIVEN ARRAY IS:  "<<arr1->Min();
            break;
            case 12:cout<<"ENTER INDEX OF THE ELEMENT YOU WANT TO PRINT: "<<endl;
            cin>>index;
            x=arr1->Get(index);cout<<"YOUR ELEMENT IS : "<<x;
            break;
            case 13:arr2 = new Array(20);
                    arr3 = new Array(60);
                    cout<<"INSERT YOUR SECOND ARRAY: "<<endl;
                    arr2->create();
                    cout<<"YOUR ENTERED ARRAY IS: "<<endl;
                    arr2->display();
                    cout<<endl;
                    arr3= arr1->Merge(*arr2);
                    cout<<"AFTER MERGING ELEMENTS IN THE ARRAY,YOUR REQUIRED ARRAY IS: "<<endl;
                    arr3->display();
            break;
            case 14:arr2 = new Array(20);
                    arr3 = new Array(60);
                    cout<<"INSERT YOUR SECOND ARRAY: "<<endl;
                    arr2->create();
                    cout<<"YOUR ENTERED ARRAY IS: "<<endl;
                    arr2->display();
                    cout<<endl;
                    arr3= arr1->Union(*arr2);
                    cout<<"AFTER MERGING ELEMENTS IN THE ARRAY,YOUR REQUIRED ARRAY IS: "<<endl;
                    arr3->display();
                    break;

            


    }
    }while(ch<17);

    return 0;
}