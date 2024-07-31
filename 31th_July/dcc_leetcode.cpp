#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int ans(vector<vector<int>>& books, int &w,int i,int &n,int &a,int cnt,vector<int>&dp)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i]!=INT_MAX)
        return dp[i];
        int val=0,maxi=0;
        for(int j=i;j<n;j++)
        {
            if(books[j][0]+val<=w)
            {
                val+=books[j][0];
                maxi=max(maxi,books[j][1]);
                dp[i]=min(dp[i],maxi+ans(books,w,j+1,n,a,cnt+maxi,dp));
            }
            else
            break;
        }
        return dp[i];
    }
    int minHeightShelves(vector<vector<int>>& books, int w) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);
        int n=books.size();
        int a=INT_MAX;
        vector<int>dp(n+1,INT_MAX);
        return ans(books,w,0,n,a,0,dp);
    }
};