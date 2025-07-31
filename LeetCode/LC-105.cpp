//105 --> Construct Binary Tree from Preorder and Inorder Traversal

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

    int getInorderIndex(vector<int>&inorder, int element){

        for(int i=0;i<inorder.size();i++){
            if(inorder[i] == element)
                return i;
        }

        return -1;
    }

    TreeNode* constructTree(vector<int>preorder, vector<int>inorder, int &preOrderIndex, int inorderStart, int inorderEnd, int size){
        //base
        if(preOrderIndex >= size)
            return NULL;
        
        if(inorderStart > inorderEnd)
            return NULL;
        
        //1 case
        int element = preorder[preOrderIndex];
        preOrderIndex++;
        TreeNode* root = new TreeNode(element);

        //get the index of the element in the inorder array
        //divide it left and right
        int elementIndexIninorder = getInorderIndex(inorder, element);
        
        root->left = constructTree(preorder, inorder, preOrderIndex, inorderStart, elementIndexIninorder-1, size);
        root->right = constructTree(preorder, inorder, preOrderIndex, elementIndexIninorder+1, inorderEnd, size);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;
        int size = inorder.size();

        return constructTree(preorder, inorder, preOrderIndex, inorderStart, inorderEnd, size);
    }
};