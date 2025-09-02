// Maximum sum of Non-adjacent nodes

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
  
    pair<int, int>solve(Node* root){
        
        if(!root) return {0, 0};
        
        auto left = solve(root->left);
        auto right = solve(root->right);
        
        
        //sum including with the node
        int a = root->data + left.second + right.second;
        
        //sum excluding with node
        
        int b = max(left.first, left.second) + max(right.first, right.second);
        
        
        return {a, b};
        }
        
    int getMaxSum(Node *root) {
        // code here
        auto ans = solve(root);
        
        return max(ans.first, ans.second);
    }
};