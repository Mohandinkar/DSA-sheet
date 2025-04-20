//Add 1 to a Linked List Number

// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
    public:
      Node* reverseList(Node* head){
          Node* prev = NULL;
          Node* curr = head;
          
          while(curr != NULL){
              Node* forward = curr->next;
              curr->next = prev;
              prev = curr;
              curr = forward;
          }
          
          return prev;
      }
      
      Node* addOne(Node* head) {
          // Your Code here
          // return head of list after adding one
          //1 reverse the LL
          head = reverseList(head);
          
          //2 addone
          Node* temp = head;
          int carry = 1;
          
          while(temp != NULL){
              int sum = carry + temp->data;
              
              int digit = sum % 10;
              carry = sum / 10;
              
              temp->data = digit;
              
              //handle the last node
              if(temp->next == NULL && carry != 0){
                  Node* newNode = new Node(carry);
                  temp->next = newNode;
                  temp = newNode;
              }
              temp = temp->next;
          }
          
          //3 reverse again LL
          head = reverseList(head);
          return head;
      }
  };