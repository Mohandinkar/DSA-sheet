//83 --> Remove Duplicates from Sorted List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            
            if(head == NULL) return head;
            if(head->next == NULL) return head;
    
                ListNode* prev = head;
                ListNode* curr = prev->next;
    
                while(curr != NULL){
                    
                    if(curr->val == prev->val){
                        ListNode* temp = curr;
                        curr = curr->next;
                        prev->next = curr;
                        delete temp;
                    }
                    else{
                        prev = curr;
                        curr = curr->next;
                    }
                }
                return head;
            
        }
    };