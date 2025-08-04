// Left View of Binary Tree

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    
    void solve(Node* root, int level, vector<int>&ans){
        if(!root)
            return;
        
        if(level == ans.size()){
            ans.push_back(root->data);
        }
        
        solve(root->left, level+1, ans);
        solve(root->right, level+1, ans);
    }
    
    vector<int> leftView(Node *root) {
        // code here
        vector<int>ans;
        solve(root, 0, ans);
        
        return ans;
        
    }
};