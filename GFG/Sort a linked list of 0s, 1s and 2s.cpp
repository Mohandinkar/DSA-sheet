//Sort a linked list of 0s, 1s and 2s


class Solution {
    public:
      // Function to sort a linked list of 0s, 1s and 2s.
      
      void insertAtTail(Node* &head,Node* &tail, Node* &toMove){
          if(head == NULL && tail==NULL){
              head = toMove;
              tail = toMove;
          }
          else{
              tail->next = toMove;
              tail = toMove;
          }
      }
      
      Node* segregate(Node* head) {
  
          Node* zeroHead = NULL;
          Node* zeroTail = NULL;
          
          Node* oneHead = NULL;
          Node* oneTail = NULL;
          
          Node* twoHead = NULL;
          Node* twoTail = NULL;
          
          Node* temp = head;
          while(temp != NULL){
              //sequence is most imp
              Node* toMove = temp;
              temp = temp->next;
              toMove->next = NULL;
              
              
              if(toMove->data == 0){
                  insertAtTail(zeroHead, zeroTail, toMove);
              }
              else if(toMove->data == 1){
                  insertAtTail(oneHead, oneTail, toMove);
              }
              else if(toMove->data == 2){
                  insertAtTail(twoHead,twoTail, toMove);
              }
          }
          
          //Merge the zero,one,two head 
          if(zeroHead != NULL){
              //non empty
              if(oneHead != NULL){
                  zeroTail->next = oneHead;
                  //for two if empty it will point to NULL otherwise twohead 
                  //no need to check the condition
                  oneTail->next = twoHead;
              }
              else{
                  
                  zeroTail->next = twoHead;
              }
              return zeroHead;
          }
          else{
              //empty
              if(oneHead != NULL){
                  oneTail->next = twoHead;
                  return oneHead;
              }
              else{
                  return twoHead;
              }
          }
      }
  };