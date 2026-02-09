
//T.C = O(N)
//S.C = O(N)
class Solution {
  public:

    // Count total number of nodes in the binary tree
    int count(Node *root){
        if(!root)
            return 0;

        // 1 (current node) + left subtree + right subtree
        return 1 + count(root->left) + count(root->right);
    }

    // Check if tree is Complete Binary Tree (CBT)
    // index  -> current node index (as per array representation)
    // total_nodes -> total number of nodes in tree
    bool CBT(Node* root, int index, int total_nodes){

        // If node is NULL, it's valid for CBT
        if(!root)
            return true;

        // If index exceeds total nodes, CBT property is violated
        if(index >= total_nodes)
            return false;

        // Recursively check left and right subtree
        return CBT(root->left, 2*index + 1, total_nodes) &&
               CBT(root->right, 2*index + 2, total_nodes);
    }

    // Check Max-Heap property: parent >= children
    bool maxHeap(Node *root){

        // If left child exists, compare with parent
        if(root->left){
            if(root->data < root->left->data)
                return false;

            // Recursively check left subtree
            if(!maxHeap(root->left))
                return false;
        }

        // If right child exists, compare with parent
        if(root->right){
            if(root->data < root->right->data)
                return false;

            // Recursively check right subtree
            return maxHeap(root->right);
        }

        // Leaf node or valid heap till this point
        return true;
    }

    // Main function to check if a binary tree is a Heap
    bool isHeap(Node* tree) {

        // Step-1: Count total nodes in the tree
        int num = count(tree);

        // Step-2: Check if tree is Complete Binary Tree (CBT)
        if(!CBT(tree, 0, num))
            return false;

        // Step-3: Check Max-Heap property (parent >= children)
        return maxHeap(tree);
    }
};
