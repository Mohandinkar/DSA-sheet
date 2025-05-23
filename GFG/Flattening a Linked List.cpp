// Flattening a Linked List


class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    
    Node* mergeLL(Node*a, Node*b){
        if(!a) return b;
        if(!b) return a;
        
        Node* ans = NULL;
        if(a->data < b->data){
            ans =  a;
            ans->bottom = mergeLL(a->bottom, b);
            // or a->bottom
        }
        else{
            ans = b;
            ans->bottom = mergeLL(a, b->bottom);
            //or b->bottom 
        }
        
        return ans;
    }
    
    
    Node *flatten(Node *root) {
        // Your code here
        
        if(!root) return NULL;
        
        Node* flattenLL = mergeLL(root, flatten(root->next));
        
        
        return flattenLL;
    }
};