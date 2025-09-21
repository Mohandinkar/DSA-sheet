//958 --> Check Completeness of a Binary Tree



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
    //check if the previous node is NULL (flag) and if next node is valid then it is not CBT
    //else CBT
    bool solve(TreeNode* root){

        //level wise trversal
        queue<TreeNode*>q;

        q.push(root);
        bool isNullFound = false;

        while(!q.empty()){

            TreeNode* front = q.front();
            q.pop();

            if(front == NULL){
                isNullFound = true;
            }
            else{
                //Node is valid
                if(isNullFound){
                    return false;
                }

                q.push(front->left);
                q.push(front->right);
            }
        }

        return true;
    }

    bool isCompleteTree(TreeNode* root) {
        bool ans = solve(root);

        return ans;
    }
};


/* A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled,

Steps:
1. Perform a level-order traversal (using a queue).
2. If we encounter a NULL node, mark a flag (isNullFound = true).
3. Once a NULL is seen, all further nodes must also be NULL for the tree to be complete.
   - If after a NULL we encounter a non-NULL node, it means there’s a "gap"
     in the tree → not a CBT.
4. If traversal finishes without such a violation, the tree is a CBT.

Time Complexity: O(N)  (every node is visited once)
Space Complexity: O(N) (queue used for level-order traversal) */