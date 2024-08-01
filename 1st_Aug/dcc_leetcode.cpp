#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(int i=0;i<details.size();i++)
        {
            string det = details[i];
            string val = "";
            for(int i=11;i<det.length()-2;i++)
            {
                val += det[i];
            }
            
            int comp = stoi(val);
            if(comp > 60) ans++;
        }
        return ans;
    }
};