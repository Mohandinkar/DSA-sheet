//173 --> Binary Search Tree Iterator


/*
Approach Explanation:

Key Idea: Use a stack to perform controlled inorder traversal.
- Inorder traversal of BST → gives elements in sorted order.

Steps:
1. Maintain a stack to store nodes.
2. In the constructor, push all the left nodes from root down to the leftmost leaf.
   (helper function: pushedLeftNodes)
3. For `next()`:
   - Pop the top element from the stack (this is the next smallest element).
   - If the popped node has a right child, push that right child and all of its 
     left descendants into the stack.
   - Return the value of the popped node.
4. For `hasNext()`:
   - Simply check if the stack is non-empty.

This way, we only store necessary nodes in the stack instead of traversing 
the whole tree upfront.

Time Complexity:
- `next()` and `hasNext()` operations are amortized O(1).
- Each node is pushed and popped from the stack exactly once → O(N) over all calls.

Space Complexity:
- O(h), where h = height of the tree (stack holds nodes along one path).
*/



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
class BSTIterator {
public:
    //using stack doing the inorder traversal
    stack<TreeNode*>st;
    

    //pushing only left nodes 
    void pushedLeftNodes(TreeNode*root){

        while(root){
            st.push(root);
            root = root->left;
        }
    }

    BSTIterator(TreeNode* root) {
        pushedLeftNodes(root);
    }
    
    int next() {
        auto top = st.top();
        st.pop();

        //if right exist of that top node then push left nodes in stack
        if(top->right){
            pushedLeftNodes(top->right);
        }

        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

