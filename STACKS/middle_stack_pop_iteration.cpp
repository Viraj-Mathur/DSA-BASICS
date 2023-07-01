#include <iostream>
#include <stack>
using namespace std;

void deleteMiddle(stack<int> &st, int n) {
    int mid = n / 2 + 1; //finding middle element
    stack<int> temp; //creating a temporary stack to store upper half popped element

    for (int i = 1; i <= mid - 2; i++) { //popping element excluding middle element
        temp.push(st.top());
        st.pop();
    }

    st.pop(); // now deleting the middle one

    while (!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }
}

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

   

    deleteMiddle(st, st.size());

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
