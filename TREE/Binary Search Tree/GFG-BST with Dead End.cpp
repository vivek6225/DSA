

class Solution {
  public:
  
    // This function checks if there exists any dead end in BST
    // 'lower' and 'upper' define valid range for current node
    bool Dead(Node* root, int lower, int upper){
        
        if(!root)
            return 0;        // no dead end in empty tree
        
        // If leaf node
        if(!root->left && !root->right){
            
            // Check if no integer can be inserted at this position
            if(root->data - lower == 1 && upper - root->data == 1)
                return 1;    // dead end found
            else 
                return 0;
           
        // Check left and right subtrees
        return Dead(root->left, lower, root->data) ||  
               Dead(root->right, root->data, upper);
    }

    bool isDeadEnd(Node *root) {
        
        return Dead(root, 0, INT_MAX);   // start with full range
    }
};
