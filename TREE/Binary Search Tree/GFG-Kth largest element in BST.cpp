//------------------------Optimal Approach------------------------------------------
// T.C = O(H + k) best, O(N) worst
  // S.C = O(H)
  
class Solution {
  public:
        
      // Reverse inorder traversal (Right → Root → Left)
      // 'k' tracks how many nodes are still left to skip
      // When k becomes 0, current node is the k-th largest
      void klargest(Node* root, int &ans, int &k){
          
          if(!root  || k <= 0)
              return;                   // base case
          
          klargest(root->right, ans, k); // visit larger values first
          
          k--;                          // one node processed
          
          if(k == 0)
              ans = root->data;         // store k-th largest value
          
         // If k-th largest already found, stop further traversal
          if(k <= 0)
          return;
            // if k is still not finished, go to left subtree
              
           klargest(root->left, ans, k);
      }
     
    int kthLargest(Node *root, int k) {
        
        int ans;                        // stores final answer
        
        klargest(root, ans, k);         // start reverse inorder
        return ans;                     // return k-th largest value
    }
};

//------------------------Better Approach---------------------------------------
//T.C = 0(N)
//S.C = 0(N)
 class Solution {
  public:
  
  // Inorder traversal of BST gives values in sorted (ascending) order
  void Inorder(Node* root, vector<int>& ans){
      if(!root) return;                 // base case

      Inorder(root->left, ans);         // visit left subtree
      ans.push_back(root->data);        // store current node value
      Inorder(root->right, ans);        // visit right subtree
  }

  int kthLargest(Node *root, int k) {

      vector<int> ans;                 // stores inorder traversal result
      Inorder(root, ans);              // fill vector in sorted order

      int n = ans.size();            // total number of nodes

      // k-th largest element is at index (n - k) because array is 0-indexed
      return ans[n - k];               
  }
};