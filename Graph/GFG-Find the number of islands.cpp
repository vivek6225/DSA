
// Time Complexity  = O(n × m)
// Space Complexity = O(n × m)

class Solution {
public:
    
    int r, c;
      
    // Step 0: 8-direction arrays (row = vertical, col = horizontal)
    int row[8] = {-1,-1,-1,0,0,1,1,1};
    int col[8] = {-1,0,1,-1,1,-1,0,1};

    // Step 1: check valid cell inside grid
    bool valid(int i, int j){
        return (i >= 0 && i < r && j >= 0 && j < c);
    }

    int countIslands(vector<vector<char>>& grid) {
        
        // Step 2: grid size
        r = grid.size();
        c = grid[0].size();

        int count = 0; // total islands

        // Step 3: traverse grid
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                
                // Step 4: if land found → new island
                if(grid[i][j] == 'L'){
                    
                    count++;  // new island
                    
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    
                    grid[i][j] = 'W'; // mark visited
                    
                    // Step 5: BFS to cover full island
                    while(!q.empty()){
                        
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        
                        // Step 6: check all 8 neighbors
                        for(int k = 0; k < 8; k++){
                            
                            int ni = x + row[k];
                            int nj = y + col[k];
                            
                            // Step 7: if valid + land → visit
                            if(valid(ni, nj) && grid[ni][nj] == 'L'){
                                grid[ni][nj] = 'W';   // mark visited
                                q.push({ni, nj});    // explore next
                            }
                        }
                    }
                }
            }
        }

        // Step 8: return total islands
        return count;
    }
};