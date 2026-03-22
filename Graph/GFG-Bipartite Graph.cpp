// -----------------------Using BFS----------------------------------
// Time Complexity: O(V + E)
// Space Complexity: O(V)
class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        
        // STEP 1: create adjacency list of size V
        vector<vector<int>> adj(V);
        
        // STEP 2: convert edge list → adjacency list (undirected graph)
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // STEP 3: initialize color array (-1 = uncolored)
        vector<int> color(V, -1);
        
        // STEP 4: check all components (important if graph is disconnected)
        for(int i = 0; i < V; i++){
            if(color[i] != -1) continue;
            
            // STEP 5: start BFS
            queue<int> q;
            q.push(i);
            color[i] = 0; // assign first color
         
            while(!q.empty()){
                int node = q.front();
                q.pop();
             
                // STEP 6: check all neighbours
                for(int j = 0; j < adj[node].size(); j++){
                    int neigh = adj[node][j];
                 
                    // STEP 7: if neighbour not colored → assign opposite color
                    if(color[neigh] == -1){
                        color[neigh] = (color[node] + 1) % 2;
                        q.push(neigh);
                    }
                    
                    // STEP 8: if same color → not bipartite
                    else{
                        if(color[node] == color[neigh])
                            return 0;
                    }
                }
            }
        }
        
        // STEP 9: graph is bipartite
        return 1;
    }
};
// ---------using DFS----------------------------------------------
class Solution {
  public:
  
    bool checkBip(int node, vector<vector<int>>& adj, vector<int>& color){
        
         // STEP 1: traverse all neighbours of current node
         for(int j = 0; j < adj[node].size(); j++){
             int neigh = adj[node][j];
             
             // STEP 2: if neighbour is not colored yet
             if(color[neigh] == -1){
                 
                 // STEP 3: assign opposite color
                 color[neigh] = (color[node] + 1) % 2;
                 
                 // STEP 4: DFS call for neighbour
                 if(!checkBip(neigh, adj, color))
                     return 0; // cycle / same color conflict found
             }
             
             // STEP 5: if already colored → check for conflict
             else{
                  if(color[node] == color[neigh]){
                      return 0; // same color → not bipartite
                  }
             }
         }
         
         // STEP 6: no conflict found
         return 1;
    }

    bool isBipartite(int V, vector<vector<int>> &edges) {
        
        // STEP 1: create adjacency list
        vector<vector<int>> adj(V);
        
        // STEP 2: convert edge list → adjacency list (undirected)
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
             
        // STEP 3: initialize color array (-1 = uncolored)
        vector<int> color(V, -1);
             
        // STEP 4: check all components (important for disconnected graph)
        for(int i = 0; i < V; i++){
            
            // STEP 5: if node not colored → start DFS
            if(color[i] == -1){
                color[i] = 0; // assign first color
                
                // STEP 6: run DFS
                if(!checkBip(i, adj, color))
                    return 0;
            }
        }
        
        // STEP 7: graph is bipartite
        return 1;
    }
};