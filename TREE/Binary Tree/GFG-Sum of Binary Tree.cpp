
//T.C = 0(N)
//S.C = 0(N)

class Solution {
  public:
    int sumBT(Node* root) {
        if(!root)
        return 0;
        
        return(root->data +sumBT(root->left)+sumBT(root->right));
    }
};

//--------------------------OR----------------------------------------------------
class Solution {
  public:
  void Total(Node *root,int &sum){
      if(root == NULL)
      return;
      sum += root->data;
      Total(root->left,sum);
      Total(root->right,sum);
      
  }
    int sumBT(Node* root) {
        // code here
        int sum = 0;
        Total(root,sum);
        return sum;
        
        
    }
};