 //-----------------------optimal Approach---------------------------------------
 // T.C = O(N + M)
 // S.C = O(H1 + H2)

class Solution {
  public:
    // Function to find common nodes in two BSTs using iterative inorder traversal
    vector<int> findCommon(Node *r1, Node *r2) {

        vector<int> ans;                // store common elements
        stack<Node*> s1, s2;            // stacks for both BSTs

        // Push left chain of first BST
        while(r1){
            s1.push(r1);
            r1 = r1->left;
        }

        // Push left chain of second BST
        while(r2){
            s2.push(r2);
            r2 = r2->left;
        }

        // Traverse both BSTs like merging two sorted arrays
        while(!s1.empty() && !s2.empty()){

            // If both top values are equal → common node found
            if(s1.top()->data == s2.top()->data){
                ans.push_back(s1.top()->data);

                // move to right subtree of both nodes
                r1 = s1.top()->right;
                s1.pop();

                r2 = s2.top()->right;
                s2.pop();
            }
            // If first value is greater, second one is smaller → move second BST
            else if(s1.top()->data > s2.top()->data){
                r2 = s2.top()->right;
                s2.pop();
            }
            // Else first value is smaller → move first BST
            else{
                r1 = s1.top()->right;
                s1.pop();
            }

            // Again push left chain of updated r1
            while(r1){
                s1.push(r1);
                r1 = r1->left;
            }

            // Again push left chain of updated r2
            while(r2){
                s2.push(r2);
                r2 = r2->left;
            }
        }

        return ans;
    }
};

//----------------Better Approach---------------------------------------------
// T.C = O(N + M)
// S.C = O(N + M)
class Solution {
  public:

    // Inorder traversal of first BST
    // BST ka inorder hamesha sorted array deta hai
    void inarr1(Node* root, vector<int>& ans){
        if(!root) return;

        inarr1(root->left, ans);      // left subtree
        ans.push_back(root->data);    // current node
        inarr1(root->right, ans);     // right subtree
    }

    // Inorder traversal of second BST
    void inarr2(Node* root, vector<int>& val){
        if(!root) return;

        inarr2(root->left, val);      // left subtree
        val.push_back(root->data);    // current node
        inarr2(root->right, val);     // right subtree
    }

    vector<int> findCommon(Node *r1, Node *r2) {

        vector<int> ans, val, res;

        // Convert both BSTs into sorted arrays
        inarr1(r1, ans);
        inarr2(r2, val);

        int i = 0, j = 0;

        // Two pointer technique on sorted arrays
        while(i < ans.size() && j < val.size()){

            if(ans[i] == val[j]){        // common element found
                res.push_back(ans[i]);
                i++;
                j++;
            }
            else if(ans[i] < val[j])     // move pointer of smaller element
                i++;
            else
                j++;
        }

        return res;   // list of common nodes
    }
};
