
// T.C.: O(V + E)
// S.C.: O(V)
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {   
        
        // Total number of vertices in the graph
        int V = adj.size();  

        // Queue for BFS traversal (FIFO)
        queue<int> q;
        q.push(0);   // Start BFS from vertex 0
        
        // Visited array to avoid visiting same node again
        vector<bool> visited(V, 0);
        visited[0] = 1;   // Mark source node as visited
        
        // Vector to store BFS traversal order
        vector<int> ans;

        // BFS loop
        while (!q.empty()) {
            // Take the front node from queue
            int Node = q.front();
            q.pop();

            // Add current node to BFS result
            ans.push_back(Node);
            
            // Traverse all adjacent (neighbor) nodes of current node
            for (int j = 0; j < adj[Node].size(); j++) {
                int neigh = adj[Node][j];

                // If neighbor is not visited, mark and push to queue
                if (!visited[neigh]) {
                    visited[neigh] = 1;
                    q.push(neigh);
                }
            }
        }
        
        // Return BFS traversal starting from node 0
        return ans;
    }
};
