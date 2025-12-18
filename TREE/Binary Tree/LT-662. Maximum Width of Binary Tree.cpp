
//T.C = 0(N)
//S.C = 0(N)
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        // Queue stores: {node, index}
        // index represents the position of node if tree were a complete binary tree
        queue<pair<TreeNode*, unsigned long long>> q;

        // Push root with index 0
        q.push({root, 0});

        int maxWidth = 0;

        // Level-order traversal (BFS)
        while(q.size() > 0){

            // Number of nodes in current level
            int currlevelSize = q.size();

            // Index of first node in this level
            unsigned long long stIdx = q.front().second;

            // Index of last node in this level
            unsigned long long endIdx = q.back().second;

            // Width of current level = lastIndex - firstIndex + 1
            maxWidth = max(maxWidth, (int)(endIdx - stIdx + 1));

            // Process all nodes of current level
            for(int i = 0; i < currlevelSize; i++){
                auto curr = q.front();
                q.pop();

                // If left child exists:
                // left index = parentIndex * 2 + 1
                if(curr.first->left){
                    q.push({curr.first->left, curr.second * 2 + 1});
                }

                // If right child exists:
                // right index = parentIndex * 2 + 2
                if(curr.first->right){
                    q.push({curr.first->right, curr.second * 2 + 2});
                }
            }
        }

        // Return maximum width found among all levels
        return maxWidth;
    }
};
