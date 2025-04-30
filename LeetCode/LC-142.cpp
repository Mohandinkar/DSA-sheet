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