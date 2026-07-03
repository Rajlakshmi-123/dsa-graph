#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& visited,
             vector<int>& result) {

        visited[node] = 1;
        result.push_back(node);

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfs(neighbour, adj, visited, result);
            }
        }
    }

    vector<int> dfsTraversal(vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> visited(n, 0);
        vector<int> result;

        dfs(0, adj, visited, result);

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

    vector<int> result = obj.dfsTraversal(adj);

    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}