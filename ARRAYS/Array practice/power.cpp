#include <bits/stdc++.h>

using namespace std;

int PowerLimit(int A, int B) {
    int seconds = 0;

    while(A > 0 && B > 0){
        if(A < B){
            swap(A,B);
        }

        if (A <= 1) {
            break;  
        }
        A = A - 2;
        B = B + 1;
        seconds++;   
    }
    return seconds;
}

int main() {
    int A, B;
    cin >> A >> B;
    cout << PowerLimit(A, B) << endl;
    return 0;
}