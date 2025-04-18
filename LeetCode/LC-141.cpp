//141 --> Linked List Cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        bool hasCycle(ListNode *head) {
            unordered_map<ListNode*, bool>map;
    
            ListNode* temp = head;
    
            while(temp != NULL){
                //if any one of the node visited two times it forms a cycle
                if(map[temp] == true){
                    return true;
                }
                else{
                    map[temp] = true;
                }
                temp = temp->next;
            }
    
             return false;
        }
    };

//-----------------OR----------------
class Solution {
    public:
        bool hasCycle(ListNode *head) {
           ListNode* slow = head;
           ListNode* fast = head;
    
           while(fast != NULL){
    
                fast = fast->next;
                if(fast != NULL){
                    fast = fast->next;
                    slow = slow->next;
                    
                    if(fast == slow) return true;
                }
           }
    
           return false;
        }
    };