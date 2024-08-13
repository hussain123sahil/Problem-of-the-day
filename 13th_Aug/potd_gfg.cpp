#include<iostream>
using namespace std;

class Solution {
  public:
    long long int floorSqrt(long long int n) {
        // Your code goes here
        if(n==1) return 1;
        for(long long i = 1;i<=n/2;i++)
        {
            if(i*i<=n && (i+1) *(i+1)>n) return i;
        }
    }
};