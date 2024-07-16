#include <bits/stdc++.h> 
bool isSafe(vector<vector<int>> &board, int row, int col, int val) {
    //check for row and column    
    for(int i=0; i<board.size(); i++) {        
        if(board[row][i] == val || board[i][col] == val) 
            return false;        
        //check for 3*3 matrix        
        if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val) 
            return false;    
            }    
            return true; }

bool solve(vector<vector<int> > &board){    
    int n = board[0].size();        
    for(int row=0; row<n; row++){        
        for(int col=0; col<n; col++) {            
            if(board[row][col] == 0) {                
                for(int val=1; val<=9; val++) {                    
                    if(isSafe(board, row, col, val) ) {                        
                        board[row][col] = val;                                                
                        //apply recursion for further checking                        
                        bool furtherPossible = solve(board);                        
                        if(furtherPossible) {                            
                            return true;                        
                            }                        
                            else {                            
                                board[row][col] = 0;                        
                                }                    
                                }                
                                }                
                                return false;            
                                }        
                                }    
                                }    
                                return true; 
                                }

void solveSudoku(vector<vector<int>>& sudoku){    
    solve(sudoku); 
    }