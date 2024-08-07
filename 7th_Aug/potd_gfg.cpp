#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
          int i=0,j=0;
          int n=arr1.size();
          int l=arr2.size();
          vector<int> ans;
          while(i<n && j<l)
          {
            if(arr1[i]<=arr2[j])
            {
             ans.push_back(arr1[i]);
             i++;
            }
            else{
              ans.push_back(arr2[j]);
              j++;
            }
          }
          while(i<n)
          {
            ans.push_back(arr1[i]);
             i++;
          }
          while(j<l)
          {
            ans.push_back(arr2[j]);
              j++;
          }
          return ans[k-1];
    }
};