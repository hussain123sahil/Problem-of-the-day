#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
         vector<int> in(mat.size(), 0);
        vector<int> out(mat.size(), 0);
        
        for(int i = 0; i < mat.size(); i++)
        {
            for(int j = 0; j < mat[0].size(); j++)
            {
                if(mat[i][j] == 1)
                {
                    out[i]++;
                    in[j]++;
                }
            }
        }
        
        for(int i = 0; i < mat.size(); i++)
        {
            if(in[i] == mat.size() - 1 && out[i] == 0)
                return i;
        }
        
        return -1;
    }
};