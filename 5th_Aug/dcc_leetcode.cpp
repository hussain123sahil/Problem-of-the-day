#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
        for(auto &it : arr)
        {
            mp[it]++;
        }
        
        vector<string> str;
        for(int i=0;i<arr.size();i++)
        {
            if(mp[arr[i]] == 1)
            {
                str.push_back(arr[i]);
            }
        }
        
        if (k > str.size()) {
            return ""; 
        }
        
        return str[k-1];
    }
};