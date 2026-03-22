
// Time Complexity: O(V + E)
// Space Complexity: O(V)
class Solution {
  public:
  
   bool DetectCycle(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& path){
       
       // STEP 1: mark current node as visited
       vis[node] = 1;
       
       // STEP 2: mark node in current DFS path
       path[node] = 1;
       
       // STEP 3: explore all neighbours
       for(int i = 0; i < adj[node].size(); i++){
           int neigh = adj[node][i];
           
           // STEP 4: if neighbour not visited → go deeper (DFS)
           if(!vis[neigh]) {
               if(DetectCycle(neigh, adj, vis, path))
                   return 1; // cycle found in deeper call
           }
           
           // STEP 5: if neighbour already in current path → cycle
           else if(path[neigh]) {
               return 1;
           }
       }
       
       // STEP 6: remove node from current path (backtracking)
       path[node] = 0;
       
       // STEP 7: no cycle found from this node
       return 0;
   }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        // STEP 1: create adjacency list
        vector<vector<int>> adj(V);
        
        // STEP 2: convert edge list → adjacency list
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        // STEP 3: create visited + path arrays
        vector<bool> vis(V, 0), path(V, 0);
        
        // STEP 4: check all components (important for disconnected graph)
        for(int i = 0; i < V; i++){
            if(!vis[i]) {
                
                // STEP 5: run DFS for cycle detection
                if(DetectCycle(i, adj, vis, path))
                    return true;
            }
        }
        
        // STEP 6: no cycle in any component
        return false;
    }
};