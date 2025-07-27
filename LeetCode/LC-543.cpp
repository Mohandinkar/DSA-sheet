//543 --> Diameter of Binary Tree

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
    int getHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = getHeight(root->left);
        int right = getHeight(root->right);
        int maxHeight = max(left, right);

        int total = 1 + maxHeight;
        return total;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL)
         return 0;
        
        int opt1 = diameterOfBinaryTree(root->left);
        int opt2 = diameterOfBinaryTree(root->right);
        int opt3 = getHeight(root->left) + getHeight(root->right);

        int maxDiameter = max(opt1, max(opt2, opt3));

        return maxDiameter;
    }
};