
//T.C = O(n*m)
//S.C = O(n*m)

class Solution {
public:
    
    // Directions: up, down, left, right
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    
    int r, c;
    
    // Check if cell is inside grid
    bool valid(int i, int j){
        return i >= 0 && i < r && j >= 0 && j < c;
    }

    int helpaterp(vector<vector<int>> hospital) {
        
        // Step 1: Get grid size
        r = hospital.size();
        c = hospital[0].size();
        
        queue<pair<int,int>> q;
        
        // Step 2: Push all infected patients (2) into queue
        // These are MULTIPLE SOURCES for BFS
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(hospital[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        
        int timer = 0;   // tracks time (levels of BFS)
        
        // Step 3: BFS traversal
        while(!q.empty()){
            
            int size = q.size();   // number of nodes in current level
            bool spread = false;   // check if infection spread in this round
            
            // Process current level
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                // Try all 4 directions
                for(int k = 0; k < 4; k++){
                    int ni = i + row[k];   // next row
                    int nj = j + col[k];   // next col
                    
                    // Step 4: If valid cell AND uninfected (1)
                    if(valid(ni, nj) && hospital[ni][nj] == 1){
                        
                        hospital[ni][nj] = 2;   // infect it
                        q.push({ni, nj});      // add to queue for next level
                        spread = true;         // infection happened
                    }
                }
            }
            
            // Step 5: Increase time only if infection spread
            if(spread) timer++;
        }
        
        // Step 6: Final check - if any uninfected left → return -1
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(hospital[i][j] == 1){
                    return -1;
                }
            }
        }
        
        // Step 7: Return total time
        return timer;
    }
};