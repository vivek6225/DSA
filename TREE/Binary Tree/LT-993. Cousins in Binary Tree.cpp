
// t.c = 0(n)
//s.c = 0(n)
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {

        if (!root) return false;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int size = q.size();
            bool l1 = false, l2 = false;

            while (size--) {

                TreeNode* curr = q.front();
                q.pop();

                // check current node
                if (curr->val == x) l1 = true;
                if (curr->val == y) l2 = true;

                // check if x and y are siblings (same parent)
                if (curr->left && curr->right) {
                    int L = curr->left->val;
                    int R = curr->right->val;

                    if ((L == x && R == y) || (L == y && R == x)) {
                        // same parent → NOT cousins
                        return false;
                    }
                }

                // push children
                if (curr->left)  q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            // after finishing this level:

            // both found in same level and not siblings → cousins
            if (l1 && l2) return true;

            // only one found at this level → not cousins
            if (l1 || l2) return false;
        }

        return false;
    }
};