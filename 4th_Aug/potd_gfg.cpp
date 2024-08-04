#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
         vector<pair<int,int>> p;
        for(int i =0;i< n;i++){
            int a =start[i],b =end[i];
            p.push_back({b,a});
        }
        sort(p.begin(),p.end());
        int cnt =1;
        int cur =p[0].first;
        for(int i =1;i< n;i++){
            if(p[i].second > cur){
                cnt++;
                cur =p[i].first;
            }
        }
        return cnt;
    }
};