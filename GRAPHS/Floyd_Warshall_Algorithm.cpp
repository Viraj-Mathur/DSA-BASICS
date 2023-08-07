
// Floyd Warshall Algorithm: USE TO FIND SHORTEST PATH
// INTUITION: MAKE ADJECENCY "VIA MATRICES" TILL YOU FIND THE SHORTEDT PATHS
// FORMULA: 
// matrix[i][j] =min(matrix[i][j], matrix[i ][k]+matrix[k][j]), 
// where i = source node, j = destination node, and k = the node via which we are reaching from i to j.

// IF NODE TO NODE IS LESS THAN ZERO NEGATIVE CYCLE EXISTS


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void shortest_distance(vector<vector<int>>& matrix){
        // validate the nodes for matrix
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == -1){
                    // if distance cannot be reached
                    matrix[i][j] = 1e9;
                }
                if (i == j) matrix[i][j] = 0; //distance is possible 
            }
        }

        // MAIN ALGO
        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }

        // For detecting negative cycles
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1e9) {
                    matrix[i][j] = -1;
                }
            }
        }
    }
};

int main(){

    int V = 4;
	vector<vector<int>> matrix(V, vector<int>(V, -1));
	matrix[0][1] = 2;
	matrix[1][0] = 1;
	matrix[1][2] = 3;
	matrix[3][0] = 3;
	matrix[3][1] = 5;
	matrix[3][2] = 4;

	Solution obj;
	obj.shortest_distance(matrix);
    
    cout<<"The final shortest distance matrix is: "<<endl;
	for (auto row : matrix) {
		for (auto cell : row) {
			cout << cell << " ";
		}
		cout << endl;
	}
    
    return 0;
}
