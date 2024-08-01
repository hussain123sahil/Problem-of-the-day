#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int m = mat.size(), n = mat[0].size();
        int up = 0, down = m - 1, left = 0, right = n - 1;
        vector<int>spiral;
        while(up <= down && left <= right){
            //Pushing of the elements from left to right
            for(int col = left; col <= right; col++)
                spiral.push_back(mat[up][col]);
            if(++up > down) //up must be less than down in order to be in matrix
                break;
            //Pushing of the elements from top to bottom
            for(int row = up; row <= down; row++)
                spiral.push_back(mat[row][right]);
            if(--right < left) //left must be less than left in order to be in matrix
                break;
            //Pushing of the elements from right to left
            for(int col = right;col >= left; col--)
                spiral.push_back(mat[down][col]);
            if(--down < up) //up must be less than down in order to be in matrix
                break;
            //Pushing of the elements from bottom to top
            for(int row = down;row >= up; row--)
                spiral.push_back(mat[row][left]);
            if(++left > right) //left must be less than left in order to be in matrix
                break;
        }
        return spiral;
    }
};