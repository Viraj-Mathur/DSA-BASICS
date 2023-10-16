/*

*/
#include <bits/stdc++.h>

using namespace std;

/* Approach 1: we can use two separate arrays one for rows (rowsArray) and one for columns (colsArray) and initialize them to 1
while traversing the given matrix whenever we encounter 0 at (i,j), we will set rowsArray[i]=0 and colsArray[j]=0
After completion of step 2, again iterate through the matrix and for any (i,j), if rowsArray[i] or colsArray[j] is 0 then update matrix[i][j] to 0.
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Use vectors for dynamic sizing
        vector<int> col(m, 0);
        vector<int> row(n, 0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i] || col[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// but this method uses extra space: Time: O(mn)O(mn)O(mn), Space: O(m+n)O(m+n)O(m+n)

/* APPROACH 2: we can use the 0th row and 0th column of the given matrix itself instead of using two separate arrays
    First we will traverse the 0th row and 0th column of the given matrix and if we encounter any 0 
    then we will set the isRow0/isCol0 variable to true which indicates that the 0th row/0th column of the given matrix will become 0

    Next we will traverse the remaining matrix except 0th row and 0th column and if we encounter any 0, we will make 
    the corresponding row no. and column no. equal to 0 in the 0th column and 0th row respectively.

    Now we will update the values of the matrix except first row and first column to 0 if matrix[i][0]=0 or matrix[0][j]=0 for any (i,j).
    finally we will traverse the 0th row and 0th column and if we find any 0, we will make the whole row and whole column equal to 0

    -Time: O(mn)O(mn)O(mn), Space: O(1)O(1)O(1)

*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        bool isRow0 = false, isCol0 = false;

        // Check if the first row should be zeroed
        for(int j = 0; j < m; j++) {
            if(matrix[0][j] == 0)
                isRow0 = true;
        }

        // Check if the first column should be zeroed
        for(int i = 0; i < n; i++) {
            if(matrix[i][0] == 0)
                isCol0 = true;
        }

        // Use the first row and column to mark zeros
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set zeros based on markings in the first row and column
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero out the first row if needed
        if(isRow0) {
            for(int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Zero out the first column if needed
        if(isCol0) {
            for(int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};


int main(){
    
    return 0;
}