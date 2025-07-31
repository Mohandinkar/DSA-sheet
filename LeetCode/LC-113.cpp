//113 --> Path Sum II

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
    void solve(TreeNode* root, int targetSum, int sum, vector<int>&track, vector<vector<int>>&ans){

        //base case
        if(root == NULL)
            return;
        
        sum += root->val;

        track.push_back(root->val);
        //if curr is leaf node
        if(root->left == NULL && root->right==NULL){

            if(sum == targetSum){
                ans.push_back(track);
            }
            //backtrack
            track.pop_back();
            return;
        }

        solve(root->left, targetSum, sum, track, ans);
        solve(root->right, targetSum, sum, track, ans);

        //backtrack
        track.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       int sum = 0;
       vector<int>track;
       vector<vector<int>>ans;

       solve(root, targetSum, sum, track, ans); 

       return ans;
    }
};