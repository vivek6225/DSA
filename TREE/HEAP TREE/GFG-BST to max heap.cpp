
//T.C = O(N)
//S.C = O(N)
class Solution {
  public:
    // Inorder traversal of BST
    // BST ka inorder traversal sorted order me elements deta hai
    void InOrder(Node *root, vector<int>& ans) {
        if(!root)
            return;
        
        InOrder(root->left, ans);      // left subtree
        ans.push_back(root->data);    // store current node value
        InOrder(root->right, ans);    // right subtree
    }

    // Postorder traversal to assign values back to tree
    // Postorder me pehle children process hote hain, phir root
    // Isse hum Max Heap ka property maintain kar pate hain
    void postOrder(Node *root, vector<int>& ans, int &index) {
        if(!root)
            return; 
        
        postOrder(root->left, ans, index);    // left child
        postOrder(root->right, ans, index);   // right child
        
        // Assign next largest value to current node
        // Because ans is sorted (inorder se aaya hai),
        // aur postorder root ko last me assign karta hai,
        // isliye parent nodes ko bigger values milti hain
        root->data = ans[index];
        index++;
    }

    // Main function to convert BST to Max Heap
    void convertToMaxHeapUtil(Node* root) {
        
        vector<int> ans;
        
        // Step 1: Store BST elements in sorted order (inorder traversal)
        InOrder(root, ans);
         
        int index = 0;
        
        // Step 2: Assign values back to tree using postorder traversal
        // Isse Max Heap ka structure ban jata hai
        postOrder(root, ans, index);
    }
};
