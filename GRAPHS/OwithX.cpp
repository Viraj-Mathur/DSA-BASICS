/* PROBLEM STATEMENT:

Given a matrix mat of size N x M where every element is either O or X.
Replace all O with X that are surrounded by X.
A O (or a set of O) is considered to be surrounded by X if there are X at locations just below, 
just above, just left and just right of it.


APPROACH: USE DFS ALGO -> ALL THE BOUNDRY Os CANNOT BE REPLACED BY Xs CHECK FOR THOSE FIRST THOSE Os IN MIDDLE(REMAINIG CHANGE THOSE TO Xs)
*/ 

// The time complexity of the solution is O(N * M), where N is the number of rows, and M is the number of columns in the matrix.


#include <bits/stdc++.h>

using namespace std;

class Solution{

private:
    // dfs algo
    void dfs(int row, int col, vector<vector<int>> &vis,
             vector<vector<char>> &mat, int delrow[], int delcol[]) {
                vis[row][col] = 1; //mark visited as 1
                int n = mat.size(); //size of row
                int m = mat[0].size(); //size of col

                // check for top left right and bottom neighbours
                for(int i=0;i<4;i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                if(nrow >=0 && nrow < n && ncol >=0 &&
                   ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O'){
                    dfs(nrow, ncol, vis, mat, delrow, delcol);
                   }
                }
                
             }
             
             

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // neighbouring traversals
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};

        vector<vector<int>> vis(n, vector<int>(m,0));

        // traverse first row and last row
        for(int i=0;i<m;i++){
            // first row
            if(!vis[0][i] && mat[0][i] == 'O'){
                dfs(0, i, vis, mat, delrow, delcol);
            }
            // last row
            if(!vis[n-1][i] && mat[n-1][i] == 'O'){
                dfs(n-1, i, vis, mat, delrow, delcol);
            }

        }

        // traverse first column and last column
        for(int j=0;j<n;j++){
            // first column
            if(!vis[j][0] && mat[j][0] == 'O'){
                dfs(j, 0, vis, mat, delrow, delcol);
            }
            // last column
            if(!vis[j][m-1] && mat[j][m-1] == 'O'){
                dfs(j, m-1, vis, mat, delrow, delcol);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j] == 'O'){
                    mat[i][j] = 'X';  // replace with X
                }
            }
        }

        return mat;




    }
};


    int main(){
    // int t;
    // cin>>t;
    // while(t--){
    //     int n, m;
    //     cin>>n>>m;
    //     vector<vector<char>> mat(n, vector<char>(m, '.'));
    //     for(int i = 0;i < n;i++)
    //         for(int j=0; j<m; j++)
    //             cin>>mat[i][j];
        
    //     Solution ob;
    //     vector<vector<char>> ans = ob.fill(n, m, mat);
    //     for(int i = 0;i < n;i++) {
    //         for(int j = 0;j < m;j++) {
    //             cout<<ans[i][j]<<" ";
    //         }
    //         cout<<"\n";
    //     }
    // }
    return 0;
    
  
}