/*
Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.

 Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
Output: 190
Explanation:
Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
Cuboid 0 is placed next with the 45x20 side facing down with height 50.
Cuboid 2 is placed next with the 23x12 side facing down with height 45.
The total height is 95 + 50 + 45 = 190.

Example 2:

Input: cuboids = [[38,25,45],[76,35,3]]
Output: 76
Explanation:
You can't place any of the cuboids on the other.
We choose cuboid 1 and rotate it so that the 35x3 side is facing down and its height is 76.


*/


class Solution {
private:

    int solve(vector<vector<int>>& cuboid,int prev,int pos){
        if(pos == cuboid.size()){ //checks if the current position pos has reached the end of the cuboid f it has, it means there are no more blocks to consider, so the function returns  0
            return 0;
        }

        int skip = solve(cuboid,prev,pos+1); // case where he current block at pos is skipped or not included in the tower.

        int take = 0;
        if(prev==-1 ||( cuboid[prev][0] <= cuboid[pos][0] && cuboid[prev][1] <= cuboid[pos][1] && cuboid[prev][2] <= cuboid[pos][2])){
            take = cuboid[pos][2] + solve(cuboid,pos,pos+1);
        }
        /*
        This condition checks if either it is the first block (prev == -1) or if the current block 
        at pos has dimensions greater than or equal to the previously placed block (cuboid[prev]). 
        This condition ensures that the blocks are placed in a valid way, with each new block being 
        larger than or equal to the previous one in all dimensions.
        */

        return max(skip,take);


    }

    // compare function
    static bool comp(vector<int>& d1, vector<int>& d2){
        if(d1[0] == d2[0]){
            if(d1[1] == d2[1]){
                return d1[2]<d2[2];
            }
            return d1[1] < d2[1];
        }
        return d1[0] < d2[0];
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        // sorting according to max height
        for(int i=0;i<cuboids.size();i++){
            sort(cuboids[i].begin(), cuboids[i].end());
        }

        sort(cuboids.begin(),cuboids.end(),comp);
        return solve(cuboids,-1,0);
    }
};
