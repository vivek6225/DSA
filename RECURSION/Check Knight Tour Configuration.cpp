//1. grid → The chessboard with knight's move sequence
// 2. r, c → Current position of the knight.
//3. n → Size of the grid (n x n).
//4. expvalue → Expected value at the current position.
//If expvalue is the final number n*n - 1, the full tour is complete → return true.
// T.C = 0(8n^2)
// S.C=0(n*n)

class Solution {
  public:
  bool isvalid(vector<vector<int>>&grid,int r,int c,int n ,int expvalue){
      if(r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != expvalue){
          return false;
      }
      if(expvalue == n*n-1){ //the tour is complete
          return true;
      }
      //8 possible moves
      int ans1 = isvalid(grid,r-2,c+1,n,expvalue+1);
      int ans2 = isvalid(grid,r-1,c+2,n ,expvalue+1);
      int ans3 = isvalid(grid,r+1,c+2,n,expvalue+1);
      int ans4 = isvalid(grid,r+2,c+1,n,expvalue+1);
      int ans5 = isvalid(grid,r+2,c-1,n,expvalue+1);
      int ans6 = isvalid(grid,r+1,c-2,n,expvalue+1);
      int ans7 = isvalid(grid,r-1,c-2,n,expvalue+1);
      int ans8 = isvalid(grid,r-2,c-1,n,expvalue+1);
  
      return ans1 ||ans2||ans3||ans4||ans5||ans6||ans7||ans8;
  
  }
      bool checkValidGrid(vector<vector<int>>& grid) {
          return isvalid(grid ,0,0 ,grid.size(),0);
          
      }
  };