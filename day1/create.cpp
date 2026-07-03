#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 4; // Number of vertices (0 to 3)

    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {2, 3}
    };
   vector<vector<int>> adj(n) ;
   for (auto &edge : edges) {
      int src= edge[0] ;
      int dest = edge[1] ;

      adj[src].push_back(dest) ;
      adj[dest].push_back(src) ;
   }

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (int neighbour : adj[i]) {
            cout << neighbour << " ";
        }
        cout << endl;
    }

    return 0;
}