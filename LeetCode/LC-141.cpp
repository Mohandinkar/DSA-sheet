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