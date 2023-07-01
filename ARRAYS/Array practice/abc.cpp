#include<iostream>

using namespace std;

int main(){
    int n;
    cout<<"enter number: "<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Print the "<<arr[i-1]<<"th element: "<<endl;  
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        if(arr[0]<arr[i])
        arr[0]=arr[i];    
        
    }
    
    cout<<"Printed element is: "<<arr[0];
    return 0;
}
