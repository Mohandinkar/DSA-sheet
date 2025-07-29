//236. Lowest Common Ancestor of a Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root == NULL)
            return NULL;
        
        if(root->val == p->val)
            return p;
        
        if(root->val == q->val)
            return q;
        
        //RE
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right =  lowestCommonAncestor(root->right, p, q);

        //4 cases
        if(left == NULL && right == NULL)
            return NULL;
        else if(left == NULL && right !=NULL)
            return right;
        else if(left != NULL && right == NULL)
            return left;
        else
            return root;
        //left != NULL && right != NULL
    }
};