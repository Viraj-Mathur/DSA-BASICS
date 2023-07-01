#include <iostream>
using namespace std;
void backword_forward(){
    int n,k,i,j,x;
    int arr[n][n][n];
    int temp= 0;
        i=j=x=0;
        while(j<n)
        {
            for(i=0;i<n;i++)
            {
                temp+=arr[i][j][i];
                arr[i][j][i]=temp-arr[i][j][i];
                temp-=arr[i][j][i];
            }
            j++;
            if(j<n)
            {
                for(i=n-1;i>=0;i--)
                {
                    temp+=arr[i][j][i];
                    arr[i][j][i]=temp-arr[i][j][i];
                    temp-=arr[i][j][i];
                }
            }
            j++;
        }
}

int main() 
{
    int n,k,i,j,x;
    cin>>n;
    cin>>k;
    int arr[n][n][n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(x=0;x<n;x++)
                cin>>arr[i][j][x];
    
    while(k--)
    {
        int temp= 0;
        i=j=x=0;
        // while(j<n)
        // {
        //     for(i=0;i<n;i++)
        //     {
        //         temp+=arr[i][j][i];
        //         arr[i][j][i]=temp-arr[i][j][i];
        //         temp-=arr[i][j][i];
        //     }
        //     j++;
        //     if(j<n)
        //     {
        //         for(i=n-1;i>=0;i--)
        //         {
        //             temp+=arr[i][j][i];
        //             arr[i][j][i]=temp-arr[i][j][i];
        //             temp-=arr[i][j][i];
        //         }
        //     }
        //     j++;
        // }
        backword_forward();

        arr[0][0][0]=temp;
        i=j=x=0;
        while(j<n)
        {
            for(i=0;i<n;i++)
            {
                temp+=arr[n-i-1][j][i];
                arr[n-1-i][j][i]=temp-arr[n-1-i][j][i];
                temp-=arr[n-1-i][j][i];
            }
            j++;
            if(j<n)
            {
                for(i=n-1;i>=0;i--)
                {
                temp+=arr[n-1-i][j][i];
                arr[n-1-i][j][i]=temp-arr[n-1-i][j][i];
                temp-=arr[n-1-i][j][i];
                }
            }
            j++;
        }
        arr[n-1][0][0]=temp;
    }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            for(x=0;x<n;x++)
                cout<<arr[i][j][x]<<" ";
	
	return 0;
}