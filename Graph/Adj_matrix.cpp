
//T.C = O(v²)
//S.C = O(v²)

#include <bits/stdc++.h>
using namespace std;

int main() {
    // Number of vertices (nodes) and edges in the graph
    int vertex, edges;
    cin >> vertex >> edges;

    // ---------------- Choose one ----------------
    // For UNWEIGHTED graph (use bool matrix)
    // vector<vector<bool>> adjmat(vertex, vector<bool>(vertex, false));

    // For WEIGHTED graph (use int matrix)
    vector<vector<int>> adjmat(vertex, vector<int>(vertex, 0));
    // -------------------------------------------

    int u, v, weight;

    // Input edges
    for (int i = 0; i < edges; i++) {

        // -------- Input format --------
        // For UNWEIGHTED graph:
        // cin >> u >> v;

        // For WEIGHTED graph:
        cin >> u >> v >> weight;
        // ------------------------------

        // Since graph is undirected,
        // mark both (u -> v) and (v -> u)
        
        // For UNWEIGHTED:
        // adjmat[u][v] = 1;
        // adjmat[v][u] = 1;

        // For WEIGHTED:
        adjmat[u][v] = weight;
        adjmat[v][u] = weight;
    }

    // Print the adjacency matrix
    for (int i = 0; i < vertex; i++) {
        for (int j = 0; j < vertex; j++) {
            cout << adjmat[i][j] << " ";
        }
        cout << endl;  // move to next row
    }

    return 0;
}
