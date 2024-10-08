#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class Solution {
  public:
  int dp[101][101];
  int solve(int i,int j,string s1,string s2){
     if(j>=s2.size()){
         if(i>=s1.size()){
             return 0;
         }
         return s1.size()-i;
     }
      if(i>=s1.size()){
          if(j>=s2.size())return 0;
          return s2.size()-j;
      }
      if(dp[i][j]!=-1)return dp[i][j];
    
      int ans=INT_MAX;
      if(s1[i]==s2[j])ans=solve(i+1,j+1,s1,s2);
      else{
        // case 1 insert a character 
        ans=solve(i,j+1,s1,s2)+1;
        // remove a character 
        ans=min(ans,solve(i+1,j,s1,s2)+1);
        // Replace any character from the string with any other character.
        ans=min(ans,solve(i+1,j+1,s1,s2)+1);
      }  
      
      return dp[i][j]=ans;
    
      
  }
    int editDistance(string str1, string str2) {
        memset(dp,-1,sizeof(dp));
       return solve(0,0,str1,str2);
    }
};