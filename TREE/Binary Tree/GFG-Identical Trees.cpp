
//T.C = 0(N)
//S.C = 0(N)

class Solution {
  public:
    bool isIdentical(Node* r1, Node* r2) {

        // Case 1: BOTH nodes are NULL → identical
        if(!r1 && !r2)
            return true;

        // Case 2: One is NULL, the other is not → NOT identical
        if((!r1 && r2) || (r1 && !r2))
            return false;

        // Case 3: Data mismatch → NOT identical
        if(r1->data != r2->data)
            return false;

        // Check left & right subtrees
        return isIdentical(r1->left, r2->left) &&
               isIdentical(r1->right, r2->right);
    }
};
