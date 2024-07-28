/* 2045. Second Minimum Time to Reach Destination */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // Create adjacency list
        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // BFS setup
        queue<pair<int, int>> q; // {time, node}
        vector<int> first(n + 1, INT_MAX);
        vector<int> second(n + 1, INT_MAX);

        q.push({0, 1});
        first[1] = 0;

        while (!q.empty()) {
            auto [currentTime, node] = q.front();
            q.pop();

            int newTime = currentTime;
            // Handle the traffic signal
            if ((currentTime / change) % 2 == 1) { // If red signal
                newTime += change - (currentTime % change);
            }
            newTime += time; // Time to travel to the next node

            for (int neighbor : adj[node]) {
                if (newTime < first[neighbor]) {
                    second[neighbor] = first[neighbor];
                    first[neighbor] = newTime;
                    q.push({newTime, neighbor});
                } else if (newTime > first[neighbor] && newTime < second[neighbor]) {
                    second[neighbor] = newTime;
                    q.push({newTime, neighbor});
                }
            }
        }

        return second[n] == INT_MAX ? -1 : second[n];
    }
};

