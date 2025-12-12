//------------Optimal Approach--------------------------------------------
//T.C = 0(N)
//S.C = (N)
class Solution {
public:
    int ans = 0;  
    // 'ans' will store the maximum diameter found so far.
    // Diameter = longest path between any two nodes (in edges).

    // Function to compute height of a node AND update diameter at the same time.
    int height(TreeNode* root) {
        if(root == NULL) {
            return 0;   // Height of empty subtree = 0
        }

        // Recursively compute height of left subtree
        int leftheight = height(root->left);

        // Recursively compute height of right subtree
        int rightheight = height(root->right);

        // The path passing through current node = leftheight + rightheight
        // Update global diameter 'ans' if this path is larger
        ans = max(ans, leftheight + rightheight);

        // Return height of current subtree:
        // 1 + max height of its children
        return max(leftheight, rightheight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // Calling height will recursively calculate heights
        // and update 'ans' with the maximum diameter found.
        height(root);

        // 'ans' now contains the final diameter of the tree
        return ans;  
    }
};

//------------Better Approach---------------------------------------------
// T.C = 0(N²)
//S.C = 0(N)
class Solution {
public:

    // Function to calculate the height of a binary tree
    // Height = longest path from this node to any leaf (in terms of nodes)
    int height(TreeNode* root) {
        if(root == NULL) {
            return 0;   // Height of empty tree is 0
        }

        // Recursively compute height of left and right subtree
        int leftheight = height(root->left);
        int rightheight = height(root->right);

        // Height of current node = 1 + maximum height of its children
        return max(leftheight, rightheight) + 1;
    }

    // Function to compute the diameter of a binary tree
    // Diameter = longest path between any two nodes in the tree
    // This path may or may not pass through the root
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL) {
            return 0;   // Diameter of empty tree is 0
        }

        // Diameter in the left subtree
        int leftDiam = diameterOfBinaryTree(root->left);

        // Diameter in the right subtree
        int rightDiam = diameterOfBinaryTree(root->right);

        // Diameter passing through the current node
        // = height of left subtree + height of right subtree
        // (This gives number of edges on the path)
        int currDiam = height(root->left) + height(root->right);

        // Final diameter = max of:
        // 1. diameter in left subtree
        // 2. diameter in right subtree
        // 3. diameter passing through current node
        return max(currDiam, max(leftDiam, rightDiam)); 
    }
};
