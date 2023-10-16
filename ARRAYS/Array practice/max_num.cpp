#include<iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: " << endl;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter the " << i + 1 << "th element: " << endl;
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        if (arr[0] < arr[i])
            arr[0] = arr[i];
    }

    cout << "The largest element is: " << arr[0] << endl;
    return 0;
}
