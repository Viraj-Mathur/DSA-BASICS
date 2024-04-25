// https://leetcode.com/problems/simplify-path/
// Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
     stack<string> st;
        for(int i = 0; i < path.size(); ++i) {
            // for traversing  the relative paths like "../" or "/..
            if(path[i] == '/') continue; //It skips over leading slashes ('/')
            
            // if not a slash, it accumulates characters into a temporary string temp ntil it encounters another slash or reaches the end of the string 
            string temp;
            while(i < path.size() && path[i] != '/') {
                temp += path[i];
                ++i;
            }
            if(temp == ".") continue; //If temp is ".", it's ignored (skipped).
            else if(temp == "..") {
                if(!st.empty()) st.pop(); //If temp is "..", it signifies going up one level in the directory hierarchy. In this case, if the stack (st) is not empty, the top element (last added directory) is removed (st.pop()).
            }
            else st.push(temp); //Otherwise, temp represents a valid directory or filename, which is pushed onto the stack 
        }
        // reconstructing file name
        // Each component from the stack is prefixed with "/" to separate directories and files.

        path = "";
        while(!st.empty()) {
            path = "/" + st.top() + path;
            st.pop();
        }

// edge case: f the resultant path string is empty after processing, it means the original path was either empty or consisted solely of directory traversal (. or .. commands), so it returns "/" to represent the root directory.

        if(path.size() == 0) return "/";
        return path;}
};
 

int main(){
    
    return 0;
}