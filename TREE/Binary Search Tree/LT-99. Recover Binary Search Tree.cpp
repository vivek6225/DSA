
//T.C = O(N)
//S.C = O(N)
class Solution {
public:
     TreeNode* prev = NULL;     // previous node in inorder
     TreeNode* first = NULL;    // first wrong node
     TreeNode* second = NULL;   // second wrong node
     
     // inorder traversal to find wrong nodes
     void inorder(TreeNode * root){
        
        if(!root)
            return;

        inorder(root->left);

        // if current value is smaller than previous, BST rule broken
        if(!prev || prev->val > root->val){

            // first time mistake, save previous node
            if(first == NULL)
                first = prev;

            // always save current node as second
            second = root;
        }

        prev = root;        // move to next node
        inorder(root->right);
     }

    void recoverTree(TreeNode* root) {
        
        inorder(root);     // find wrong nodes

        // swap values to fix tree
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};

//-------------------------------------------------------------------------------
//T.C = O(N)
//T.C = O(1)

class Solution {
public:
    void recoverTree(TreeNode* root) {

        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* prev = NULL;
        TreeNode* cur = root;

        while(cur) {

            // Case 1: No left child
            if(!cur->left) {

                // check BST violation
                if(!prev || prev->val > cur->val) {
                    if(!first) first = prev;
                    second = cur;
                }

                prev = cur;
                cur = cur->right;
            }
            else {
                TreeNode* temp = cur->left;

                // find rightmost node of left subtree
                while(temp->right && temp->right != cur)
                    temp = temp->right;

                // create thread
                if(!temp->right) {
                    temp->right = cur;
                    cur = cur->left;
                }
                // remove thread
                else {
                    temp->right = NULL;

                    // check BST violation
                    if(prev && prev->val > cur->val) {
                        if(!first) first = prev;
                        second = cur;
                    }

                    prev = cur;
                    cur = cur->right;
                }
            }
        }

        // swap the two wrong nodes
        int t = first->val;
        first->val = second->val;
        second->val = t;
    }
};
