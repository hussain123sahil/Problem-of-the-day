/*Remove Duplicates*/ 
#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        unordered_map<char,int> mp;
        string ans = "";
        for(int i=0;i<str.size();i++)
        {
            if(mp[str[i]] == 1)
            {
                continue;
            }
            else
            {
                mp[str[i]]++;
                ans += str[i];
            }
        }
        return ans;
    }
};