//106 --> Construct Binary Tree from Inorder and Postorder Traversal


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
    void createMapping(vector<int>&inorder, unordered_map<int,int>&mp){
        for(int i=0;i<inorder.size();i++){
            int element = inorder[i];
            mp[element] = i;
        }

        return;
    }

    TreeNode* contructTree(unordered_map<int,int>&mp,vector<int>& inorder, vector<int>& postorder, int &postIndex, int inorderSt, int inorderEnd){

        //base case
        if(postIndex < 0){
            return NULL;
        }

        if(inorderSt > inorderEnd)
            return NULL;

        //solve 1 case
        int element = postorder[postIndex];
        TreeNode* root = new TreeNode(element);
        postIndex--;

        int elementIndexInInorder = mp[element];

        //N-R-L its opposite to L-R-N i.e. postorder
        root->right = contructTree(mp, inorder, postorder, postIndex,elementIndexInInorder+1 , inorderEnd);
        root->left = contructTree(mp, inorder, postorder, postIndex,inorderSt , elementIndexInInorder - 1);


        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size()-1;
        int inorderSt = 0;
        int inorderEnd = inorder.size()-1;
        unordered_map<int, int>mp;

        createMapping(inorder, mp);

       return contructTree(mp, inorder, postorder, postIndex, inorderSt, inorderEnd);

    }
};

//TC: O(N)
//SC: O(N) 

