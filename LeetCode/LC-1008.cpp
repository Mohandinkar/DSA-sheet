//1008 --> Construct Binary Search Tree from Preorder Traversal

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

    TreeNode* solve(int val, TreeNode* root){
        if(!root){
            TreeNode* root = new TreeNode(val);
            return root;
        }
        else{
            if(val < root->val){
                root->left = solve(val, root->left);

            }
            else{
                root->right = solve(val, root->right);
            }
        }

        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;

        for(int i=0;i<preorder.size();i++){
            root = solve(preorder[i], root);
        }

        return root;
    }
};

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

    TreeNode* solve(int val, TreeNode* root){
        if(!root){
            TreeNode* root = new TreeNode(val);
            return root;
        }
        else{
            if(val < root->val){
                root->left = solve(val, root->left);

            }
            else{
                root->right = solve(val, root->right);
            }
        }

        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;

        for(int i=0;i<preorder.size();i++){
            root = solve(preorder[i], root);
        }

        return root;
    }
};


//OR
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

    TreeNode* build(int&i, int min, int max,vector<int>& preorder){
        if(i >= preorder.size())
            return nullptr;
        
        TreeNode* root = NULL;

        if(preorder[i] > min && preorder[i] < max){
            root = new TreeNode(preorder[i++]);

            root->left = build(i, min, root->val, preorder);
            root->right = build(i, root->val, max, preorder);
        }

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
      int min = INT_MIN, max = INT_MAX;
      int i = 0;

      return build(i, min, max, preorder);  
    }
};

// Approach:  
// - Use preorder array with bounds (min, max) to build BST directly.  
// - Start with i = 0, and only create node if preorder[i] is within (min, max).  
// - Recursively build left subtree with range (min, root->val).  
// - Recursively build right subtree with range (root->val, max).  
// - i increments as we process each node → ensures preorder order is followed.  
//
// Time Complexity: O(n) → each node is processed exactly once.  
// Space Complexity: O(h) recursion stack (h = height of BST, worst O(n), best O(log n)).  


