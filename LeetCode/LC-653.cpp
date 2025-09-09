//653 --> Two Sum IV - Input is a BST

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

    bool TwoSum(vector<int>inorder, int k){
        int n = inorder.size();
        int s = 0;
        int e = n - 1;

        while(s < e){
            int sum = inorder[s] + inorder[e];
            if(sum == k){
                return true;
            }
            if(sum > k){
                e--;
            }
            if(sum < k){
                s++;
            }
        }

        return false;

    }

    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;

        inorderStored(root, inorder);

        return TwoSum(inorder, k);
    }
};