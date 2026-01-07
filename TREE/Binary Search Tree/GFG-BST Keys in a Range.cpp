
// T.C = O(N)
// T.C = O(H)
int n1, n2;   // global variables for range limits

class Solution {
  public:
  
      // Traverses BST and collects nodes lying in [n1, n2]
      void find(Node* root, vector<int>& ans){
          
          if(!root)
              return;                 // base case
         
          // If both n1 and n2 are smaller than root value,
          // then valid nodes can only be in left subtree
          if(root->data > n1 && root->data > n2)
              find(root->left, ans);
          
          // If both n1 and n2 are greater than root value,
          // then valid nodes can only be in right subtree
          else if(root->data < n1 && root->data < n2)
              find(root->right, ans);
           
          // Otherwise current node lies in the range
          else{
              find(root->left, ans);        // explore left subtree
              ans.push_back(root->data);    // store valid node
              find(root->right, ans);       // explore right subtree
          }
      }

    vector<int> printNearNodes(Node *root, int low, int high) {
        
        vector<int> ans;              // stores all nodes in range
        n1 = low;                     // set global lower bound
        n2 = high;                    // set global upper bound
        find(root, ans);              // start traversal
        return ans;                   // return result
    }
};
