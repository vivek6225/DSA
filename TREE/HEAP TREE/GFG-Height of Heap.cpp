
//T.C = O(log N)
//T.C = O(1)

class Solution {
  public:
    int heapHeight(int N, int arr[]) {
       
        // If heap has only 1 node, height is 1
        if(N == 1)
            return 1;
       
        int height = 0;  // to store height of heap
        
        // Divide N by 2 until only root remains
        // Each division represents moving one level up in heap
        while(N > 1){
            height++;   // one level counted
            N /= 2;     // go to parent level
        }

        // Return total number of levels
        return height;
    }
};
