//142 --> Linked List Cycle II

//Using the Hash Map

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
        ListNode *detectCycle(ListNode *head) {
            unordered_map<ListNode*, bool>map;
    
            ListNode* temp = head;
            while(temp != NULL){
                if(map[temp] == true){
                    return temp;
                }
    
                map[temp] = true;
                temp = temp->next;
            }
            return NULL;
        }
    };

//--------------OR-----------------
//By using the Slow and fast pointer

class Solution {
    public:
        ListNode* hasCycle(ListNode*&head){
            ListNode* fast = head;
            ListNode* slow = head;
    
            while(fast != NULL){
                fast = fast->next;
    
                if(fast != NULL){
                    fast = fast->next;
                    slow = slow->next;
    
                    if(slow == fast)
                    return fast;
                }
            }
            return nullptr;
        }
    
        ListNode *detectCycle(ListNode *head) {
            ListNode* fast = hasCycle(head);
            ListNode* slow = head;
    
            if(!fast) return nullptr;
    
            //if cycle exist then move slow & fast both by one step to get start point of the cycle
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
           }
    
           return slow;
        }
    };