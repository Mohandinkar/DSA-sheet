//Tree Boundary Traversal

/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void LeftBoundary(Node* root, vector<int>&ans){
        if(root == NULL)
            return;
            
        if(root->left == NULL && root->right == NULL) //leaf node
            return;
            
        ans.push_back(root->data);
        
        if(root->left != NULL){
            LeftBoundary(root->left, ans);
        }
        else{
            LeftBoundary(root->right, ans);
        }
    }
    
    void LeafBoundary(Node* root, vector<int>&ans){
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL){
            //leaf node
            ans.push_back(root->data);
        }
        
        LeafBoundary(root->left, ans);
        LeafBoundary(root->right, ans);
    }
    
    void RightBoundary(Node* root, vector<int>&ans){
        if(root == NULL)
            return;
        
        if(root->left == NULL && root->right == NULL){
            return;
        }
        
        if(root->right != NULL){
            RightBoundary(root->right, ans);
        }
        else{
            RightBoundary(root->left, ans);
        }
        
        //stores in reverse order
        ans.push_back(root->data);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        if(root == NULL)
            return ans;
            
        //1 -> Root node
        ans.push_back(root->data);
        //2 -> left boundary
        LeftBoundary(root->left, ans);
        //3 ->left leaf boundary
        LeafBoundary(root->left, ans);
        //4 ->right leaf boundary
        LeafBoundary(root->right, ans);
        //5 ->reverse right boundary
        RightBoundary(root->right, ans);
        
        return ans;
        
    }
};