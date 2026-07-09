#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


// DFS function
bool dfs(int node, int dest,
         vector<vector<int>>& adj,
         vector<int>& visited) {

    // Destination mil gaya
    if (node == dest) {
        return true;
    }

    // Current node ko visited mark karo
    visited[node] = 1;

    // Saare neighbours visit karo
    for (int i = 0; i < adj[node].size(); i++) {

        int neigh = adj[node][i];

        if (visited[neigh] == 0) {

            if (dfs(neigh, dest, adj, visited)) {
                return true;
            }
        }
    }

    return false;
}


int main() {

    int n = 4;

    vector<int> nums = {2, 5, 6, 8};

    int maxDiff = 2;

    vector<vector<int>> queries = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 3}
    };


   

    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            int diff = abs(nums[i] - nums[j]);

            if (diff <= maxDiff) {

                // Undirected graph
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }


    // ---------------------------
    //
    // ---------------------------

    cout << "Graph Adjacency List:" << endl;

    for (int i = 0; i < n; i++) {

        cout << i << " -> ";

        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }

        cout << endl;
    }


    // ---------------------------
    // STEP 3: Process Queries
    // ---------------------------

    vector<bool> ans;

    for (int i = 0; i < queries.size(); i++) {

        int u = queries[i][0];
        int v = queries[i][1];

        // New visited array for every query
        vector<int> visited(n, 0);

        // Check path using DFS
        bool path = dfs(u, v, adj, visited);

        ans.push_back(path);
    }


    // ---------------------------
    // STEP 4: Print Answer
    // ---------------------------

    cout << "\nOutput: [";

    for (int i = 0; i < ans.size(); i++) {

        if (ans[i] == true) {
            cout << "true";
        }
        else {
            cout << "false";
        }

        if (i != ans.size() - 1) {
            cout << ", ";
        }
    }

    cout << "]" << endl;

    return 0;
}