// Finding the square root of the given numer using Binary Search by searching from 0 to n(the given number), finding the mid and then sqaring it and comparing it with the given number.

#include<iostream>

using namespace std;

long long int sqrtInteger(int n) {
        
        int s = 0;
        int e = n;
        long long int mid = s + (e-s)/2;
        
        long long int ans = -1;
        while(s<=e) {
            
            long long int square = mid*mid;
            
            if(square == n)
                return mid;
            
            if(square < n ){
                ans = mid;
                s = mid+1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }

double morePrecision(int n, int precision, int tempSol){
    double decimal = 1;  //intitalizing the decimal to 1 first
    double ans = tempSol;

    for(int i=0;i<precision;i++){
        decimal = decimal/10;
        /* 1
           0.1
           0.01 etc....
        */
        //then adding it to the previosly acquired answer and then comparing the sqaure of the it to the given number

        for(double j=0;j*j<n;j=j+decimal){
            ans = j; //updating the answer
        }   
    }
    return ans;
}    


int main(){
    int n,p;
    cout<<" Enter the number: "<<endl;
    cin>>n;
    cout<<"Enter precision point "<<endl;
    cin>>p;
    int tempSol = sqrtInteger(n);
    cout<<"The answer is "<<morePrecision(n,p,tempSol)<<endl;
    return 0;
}