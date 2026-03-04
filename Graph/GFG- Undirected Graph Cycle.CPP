//T.C =O(V+E)
//S.C = O(V+E)
class Solution {
  public:
  
   // DFS function to detect cycle
   // node   -> current node
   // parent -> the node from which we came (important in undirected graph)
   bool cycleDetect(int node, int parent, 
                    vector<vector<int>>& adj,  
                    vector<bool>& visited){
        
        // Mark current node as visited
        visited[node] = true;
           
        // Traverse all neighbours of current node
        for(int j = 0; j < adj[node].size(); j++){
            int neigh = adj[node][j];

            // If neighbour is not visited → continue DFS
            if(!visited[neigh]) {
                if(cycleDetect(neigh, node, adj, visited))
                    return true;   // cycle found in deeper recursion
            }
            // If neighbour already visited and not parent → cycle exists
            else if(neigh != parent) {
                return true;
            }
        }

        // No cycle found from this node
        return false;
   }

    bool isCycle(int V, vector<vector<int>>& adj) {

        //  Step 1: Convert edge list to adjacency list
        // Because input is given as list of edges
        vector<vector<int>> newAdj(V);

        for(int i = 0; i < adj.size(); i++){
            int u = adj[i][0];
            int v = adj[i][1];

            // Since graph is undirected, add both directions
            newAdj[u].push_back(v);
            newAdj[v].push_back(u);
        }

        // Visited array to track visited vertices
        vector<bool> visited(V, false);

        // Graph may have multiple components
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                // Start DFS from unvisited node
                if(cycleDetect(i, -1, newAdj, visited))
                    return true;   // cycle found
            }
        }

        // If no cycle found in any component
        return false;
    }
};