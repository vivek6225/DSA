// T.C.: O(V + E)
// S.C.: O(V)
class Solution {
  public:
    
    // Recursive DFS helper function
    void DFS(int node, vector<vector<int>>& adj, 
             vector<bool>& visited, vector<int>& ans) {
        
        // Mark current node as visited
        visited[node] = true;
        
        // Add node to DFS traversal result
        ans.push_back(node);
        
        // Traverse all adjacent nodes
        for (int j = 0; j < adj[node].size(); j++) {
            int neigh = adj[node][j];
            
            // If not visited, recursively call DFS
            if (!visited[neigh]) {
                DFS(neigh, adj, visited, ans);
            }
        }
    }
        
    vector<int> dfs(vector<vector<int>>& adj) {
        
        int V = adj.size();  // total vertices
        
        vector<bool> visited(V, false);
        vector<int> ans;
        
        // Start DFS from node 0
        DFS(0, adj, visited, ans);
        
        return ans;
    }
};
