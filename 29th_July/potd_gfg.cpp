#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        // code here
        int ans = 0;
        int n = arr.size();
        int m = arr[0].size();
        
        int cnt = 0;
        int res = -1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j] == 1)
                {
                    cnt = m-j;
                    break;
                }
            }
            if(ans < cnt)
            {
                ans = cnt;
                res = i;
            }
            cnt = 0;
        }
        
        return res;
    }
};