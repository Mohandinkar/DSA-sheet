//Is Binary Tree Heap


// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    
    bool checkCompleteness(Node* root){
        //level wise trversal
        queue<Node*>q;

        q.push(root);
        bool isNullFound = false;

        while(!q.empty()){

            Node* front = q.front();
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
    
    bool checkMaxHeap(Node* root){
        
        if(!root)
            return true;
            
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        
        bool leftAns = checkMaxHeap(root->left);
        bool rightAns = checkMaxHeap(root->right);
        
        bool option1 = true;
        if(root->left && root->data < root->left->data)
            option1 = false;
            
        bool option2 = true;
        if(root->right && root->data < root->right->data)
            option2 = false;
        
        bool curr = option1 && option2;
        
        if(curr && leftAns && rightAns)
            return true;
        else
            return false;
        
    }
    
    bool isHeap(Node* tree) {
        bool completeness = checkCompleteness(tree);
        bool maxHeap = checkMaxHeap(tree);
        
        if(completeness && maxHeap) 
            return true;
        else
            return false;
    }
};

/*
Approach Explanation:

To check if a binary tree is a Heap, we need to satisfy two conditions:

1. **Completeness Check**  
   - A heap must be a Complete Binary Tree (CBT).  
   - We perform level-order traversal (BFS) using a queue.  
   - Once a NULL child is found, all nodes after that must also be NULL.  
   - If a non-NULL node appears after a NULL → not complete → return false.  

2. **Max-Heap Property Check**  
   - For every node, its value should be greater than or equal to its children.  
   - Recursively check left and right subtrees.  
   - If any node violates the property (i.e., node < child), return false.  

3. **Final Result**  
   - If both completeness and max-heap properties hold true → the binary tree is a heap.  

**Time Complexity:** O(N)  
   - Each node is visited once in both completeness and heap property check.  

**Space Complexity:** O(N)  
   - Queue used for level-order traversal in completeness check.  
*/