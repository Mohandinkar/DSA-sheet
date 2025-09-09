//1038 --> Binary Search Tree to Greater Sum Tree

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
    void inorderStored(TreeNode* root, vector<int>&inorder){
        if(!root){
            return ;
        }

        //L-N-R
        inorderStored(root->left, inorder);

        inorder.push_back(root->val);

        inorderStored(root->right, inorder);
    }

    void updateTree(TreeNode* root, vector<int>inorder, int &index){
        if(!root)
            return;
        
        //L-N-R
        updateTree(root->left, inorder, index);
        root->val = inorder[index];
        index++;

        updateTree(root->right, inorder, index);
    }

    TreeNode* bstToGst(TreeNode* root) {
        if(!root)
            return NULL;
        
        if(root->left == NULL && root->right == NULL)
            return root;

        vector<int>inorder;
        inorderStored(root, inorder);

        int n = inorder.size();
        for(int i = n-1; i>=0 ;i--){
            int nextVal = 0;
            int currVal = inorder[i];
            
            if(i+1 < n){
                nextVal = inorder[i+1];
            }

            int sum = currVal + nextVal;

            inorder[i] = sum;
        }

        int index = 0;
        updateTree(root, inorder, index);

        return root;
    }
};