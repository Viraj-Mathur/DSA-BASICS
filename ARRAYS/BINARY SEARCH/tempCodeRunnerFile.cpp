int main()
{
    int n;
    cin>>n;
    
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