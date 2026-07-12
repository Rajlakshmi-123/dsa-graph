#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSameGraph(int V, vector<vector<int>> &adj1, vector<vector<int>> &adj2) {

    if (adj1.size() != adj2.size())
        return false;

    for (int i = 0; i < V; i++) {

        if (adj1[i].size() != adj2[i].size())
            return false;

        vector<int> a = adj1[i];
        vector<int> b = adj2[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (a != b)
            return false;
    }

    return true;
}

int main() {

    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj1(V), adj2(V);

    cout << "Enter edges of Graph 1:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }

    cout << "Enter edges of Graph 2:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

    if (isSameGraph(V, adj1, adj2))
        cout << "Graphs are Same\n";
    else
        cout << "Graphs are Different\n";

    return 0;
}