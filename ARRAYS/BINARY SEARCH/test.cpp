
#include<iostream>

using namespace std;
void backwardArrayRotation(){

    int n;
    // cin>>n;
    int arr[n][n][n];
    
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                cin>>arr[i][j][k];
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=n-1;k>=0;k--){
                cout<<arr[k][i][j]<<" ";
            }
            cout<<endl;
        }
    }
}

void forwardArrayRotation(){
    
   
    int n;
    // cin>>n;
    
    int arr[n][n][n];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                cin>>arr[i][j][k];
            }
        }
    }
    
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                cout<<arr[k][j][i]<<" ";
            }
            cout<<endl;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int arr[n][n][n];
 backwardArrayRotation();
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                cout<<arr[i][j][k]<<" ";
            }
            cout<<endl;
        }
    }
    cout<<endl;

    forwardArrayRotation();
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                cout<<arr[i][j][k]<<" ";
            }
            cout<<endl;
        }
    }
}














