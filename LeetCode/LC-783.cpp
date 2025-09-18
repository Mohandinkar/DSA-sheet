//783 --> Minimum Distance Between BST Nodes

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
    void solve(TreeNode* root, TreeNode* &prev, int &ans){
        if(!root)
            return;
        
        solve(root->left, prev, ans);

        if(prev){
            ans = min(ans, root->val - prev->val);
        }

        prev = root;

        solve(root->right, prev, ans);
    }

    int minDiffInBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        int ans = INT_MAX;
        solve(root, prev, ans);

        return ans;
    }
};


//-----OR------
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
    void inorderTraversal(vector<int>&inorder, TreeNode*root){
        if(!root){
            return;
        }

        inorderTraversal(inorder, root->left);

        inorder.push_back(root->val);

        inorderTraversal(inorder, root->right);
    }

    int minDiffInBST(TreeNode* root) {
        vector<int>inorder;
        
        inorderTraversal(inorder, root);

        int minDiff = INT_MAX;

        for(auto i=1;i<inorder.size();i++){
            int currDiff = inorder[i] - inorder[i-1];

            if(currDiff < minDiff){
                minDiff = currDiff;
            }
        }

        return minDiff;
    }
};