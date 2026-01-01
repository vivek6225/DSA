
// T.C= wrost=0(n),best=0(log N)
// S.C= wrost=0(n),best=0(log N)

class Solution {
public:

    // Insert a value into BST
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // If tree is empty, create new node
        if(!root){
            TreeNode* temp = new TreeNode(val);
            return temp;
        }

        // If value is smaller, go to left subtree
        if(root->val > val){
            root->left = insertIntoBST(root->left, val);
        }
        // If value is greater, go to right subtree
        else{
            root->right = insertIntoBST(root->right, val);
        }

        // Return unchanged root pointer
        return root;
    }

    // Inorder traversal of BST
    void Inorder(TreeNode* root){

        // Base case
        if(!root)
            return;

        // Traverse left subtree
        Inorder(root->left);

        // Visit current node
        cout << root->val << " ";

        // Traverse right subtree
        Inorder(root->right);
    }
};
