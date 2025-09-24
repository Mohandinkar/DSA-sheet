//99 --> Recover Binary Search Tree




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
    //first violation, second violation
    TreeNode* FV = 0, *SV = 0, *prev = 0;

    void solve(TreeNode* curr){
        if(!curr)
            return;
        
        solve(curr->left);

        if(prev && prev->val > curr->val){

            if(FV == NULL){
                FV = prev;
            }

            SV = curr;
        }

        prev = curr;
    
        solve(curr->right);
    }

    void recoverTree(TreeNode* root) {
        solve(root);

        //swap FV & SV
        if(FV && SV)    
            swap(FV->val, SV->val);
    }
};


/*
Approach:
Inorder traversal of a BST should give values in sorted order.  
While traversing, track the previous node (`prev`).  
- First violation → store `prev` as FV (first wrong node).  
- Second violation → store current node as SV (second wrong node).  
After traversal, swap FV and SV to restore the BST.

Time Complexity: O(N)  
Space Complexity: O(H)   (recursion stack, H = height of tree)
*/

