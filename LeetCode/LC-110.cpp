//110 --> Balanced Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //when tree is balanced
    //left subtree height - right subtree height <= 1 for each node

    int getHeight(TreeNode* root){
        if(root == NULL)
            return 0;

        int left = 1 + getHeight(root->left);
        int right = 1 + getHeight(root->right);
        int maxHeight = max(left, right);

        return maxHeight;
    }
    
    bool isBalanced(TreeNode* root) {
      if(root == NULL)
        return true;

      //solve 1 case
      int lh = getHeight(root->left);
      int rh = getHeight(root->right);
      int diff = abs(lh - rh);

      //balanced cond for each node
      bool status = (diff <= 1);

      //RE
      bool leftAns = isBalanced(root->left);
      bool rightAns = isBalanced(root->right);

      //if current node + left Subtree + right tree = balanced then whole tree is balanced

      if(status && leftAns && rightAns){
        return true;
      }
      else
        return false; 
    }
};