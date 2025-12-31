
//T.C = 0(N)
//T.C = 0(N)
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        // Base case: tree empty
        if(!root)
            return NULL;

        // Key chhota hai, left subtree me search karo
        if(root->val > key){
            root->left = deleteNode(root->left, key);
            return root;
        }

        // Key bada hai, right subtree me search karo
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
            return root;
        }

        // root->val == key  → node mil gaya
        else{

            // Case 1: Leaf node (no children)
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }

            // Case 2: Only left child exists
            else if(!root->right){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Only right child exists
            else if(!root->left){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 4: Two children exist
            else{
                // Inorder predecessor find karo
                // Left subtree ka rightmost node
                TreeNode* child = root->left;
                TreeNode* parent = root;

                while(child->right){
                    parent = child;
                    child = child->right;
                }

                // Agar predecessor root ka direct left child nahi hai
                if(parent != root){
                    parent->right = child->left;
                    child->left = root->left;
                }

                // Right subtree attach karo
                child->right = root->right;

                // Current root delete karo
                delete root;
                return child;
            }
        }
    }
};
