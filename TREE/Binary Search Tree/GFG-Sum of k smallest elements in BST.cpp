
//------------------------Optimal Approach------------------------------------------

 // T.C = O(H + k) best, O(N) worst
  // S.C = O(H)
 void ksum(Node* root, int &sum, int &k) {
    
    if(!root)
        return;                

    // Visit left subtree (smaller values first)
    ksum(root->left, sum, k);

    // Process current node
    k--;                        // one smallest element consumed
    if(k >= 0)
        sum += root->data;     // add value to sum

    // If k elements already taken, stop further traversal
    if(k <= 0)
        return;

    // Visit right subtree only if k is still left
    ksum(root->right, sum, k);
}

int sum(Node* root, int k) {

    int sum = 0;               // stores answer
    ksum(root, sum, k);        // start inorder traversal
    return sum;               // return sum of k smallest elements
}

//------------------------Better Approach---------------------------------------
//T.C = 0(N)
//S.C = 0(N)

void Inorder(Node* root, vector<int> &ans){
    if(!root) return;

    Inorder(root->left, ans);
    ans.push_back(root->data);        
    Inorder(root->right, ans);
}

int sum(Node* root, int k) {

    vector<int> ans;                 
    Inorder(root, ans);

    int s = 0;                       
    for(int i = 0; i < k; i++){      
        s += ans[i];
    }
    return s;
}
