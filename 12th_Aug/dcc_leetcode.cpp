#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class KthLargest {
    
public:
    
    priority_queue<int> minHeap;
    int key;
    KthLargest(int k, vector<int>& nums) {
       key=k;
        for(auto ele : nums)
        {
            minHeap.push(-ele);
        }
    }
    
    int add(int val) {
        minHeap.push(-val);
        while(minHeap.size()>key)
        {
            minHeap.pop();
        }
        return -minHeap.top();
    }
};