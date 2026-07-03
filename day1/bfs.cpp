#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> bfsTraversal(vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> visited(n, 0);
        vector<int> result;
        queue<int> q;

        q.push(0);
        visited[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            result.push_back(node);

            for (int i = 0; i < adj[node].size(); i++) {
                int neighbour = adj[node][i];

                if (!visited[neighbour]) {
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }

        return result;
    }
};

int main() {
    vector<vector<int>> adj = {
        {1, 2},
        {0, 3, 4},
        {0},
        {1},
        {1}
    };

    Solution obj;

    vector<int> result = obj.bfsTraversal(adj);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}