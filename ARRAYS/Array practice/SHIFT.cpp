#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n],b[n+1],c[n];
    b[0]=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i+1]=a[i];
    }
    b[0]=b[n];
    for(int i=0;i<n;i++){
        c[i]=b[i];
        cout<<c[i]<<" ";
    }
    return 0;
}