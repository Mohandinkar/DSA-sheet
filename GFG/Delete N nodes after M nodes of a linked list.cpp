/*
delete n nodes after m nodes
  The input list will have at least one element
  Node is defined as

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
       
       
       if(!head) return NULL;
       
       Node* temp = head;
       
       for(int i=0;i<m-1;i++){
           if(!temp) return head;
           temp = temp->next;
       }
       
       if(!temp) return head;
       
       Node* prev = temp;
       temp = prev->next;
       
       for(int i=0;i<n;i++){
           if(!temp) break;
           Node* del = temp->next;
           delete temp;
           
           temp = del;
       }
       
       prev->next = temp;
       
       
       linkdelete(temp, n, m);
       
       return head;

    }
};