

class Solution {
public:
    /**
     * This function handles the "Upward" infection logic.
     * It uses negative numbers to signal that the target (start node) 
     * has been found in a specific subtree.
     */
    int Infected(TreeNode* root, int &timer, int target) {
        if (!root) return 0;

        // If we find the target, return -1. 
        // The negative sign is a "flag" telling parent nodes the target is below them.
        if (root->val == target) return -1;

        int left = Infected(root->left, timer, target);
        int right = Infected(root->right, timer, target);

        // Case: Target was found in the LEFT subtree
        if (left < 0) {
            // abs(left) is the distance from current node to target.
            // right is the height of the healthy right subtree.
            // Total distance = distance to target + height of other side.
            timer = max(timer, abs(left) + right);
            return left - 1; // Increment distance from target (e.g., -1 becomes -2)
        }
        
        // Case: Target was found in the RIGHT subtree
        if (right < 0) { 
            timer = max(timer, abs(right) + left);
            return right - 1; // Increment distance from target
        }

        // Standard Case: Target not found yet, just return the height of this subtree
        return 1 + max(left, right);
    }

    // Helper to locate the actual pointer to the node where infection starts
    void find(TreeNode* root, int start, TreeNode* &InfectedNode) {
        if (!root) return;
        if (root->val == start) { 
            InfectedNode = root;
            return;
        }
        find(root->left, start, InfectedNode);
        find(root->right, start, InfectedNode);
    }

    // Helper to find the deepest point starting FROM the infected node downwards
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    int amountOfTime(TreeNode* root, int start) {
        int timer = 0;
        
        // Step 1: Calculate time to infect nodes reachable via the PARENT (up and over)
        Infected(root, timer, start);

        // Step 2: Calculate time to infect nodes reachable via the target's own SUBTREES (down)
        TreeNode *InfectedNode = NULL;
        find(root, start, InfectedNode); 
        
        // getHeight returns node count, so we subtract 1 for the number of edges/minutes
        int h = getHeight(InfectedNode) - 1;
        
        // The answer is the maximum of the "upward/across" path and the "downward" path
        return max(timer, h);
    }
};