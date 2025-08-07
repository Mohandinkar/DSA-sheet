//101 --> Symmetric Tree


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
    bool checkMirror(TreeNode* p, TreeNode* q){
        if(!p && !q)
            return true;
        
        if(p && q){
           bool val = p->val == q->val;
           bool leftTree = checkMirror(p->left, q->right);
           bool rightTree = checkMirror(p->right, q->left);

           if(val && leftTree && rightTree)
            return true;
        }

        return false;

    }
    bool isSymmetric(TreeNode* root) {
       
       TreeNode* p = root->left;
       TreeNode* q = root->right;

       return checkMirror(p, q);
    }
};