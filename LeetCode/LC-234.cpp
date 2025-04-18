//234 --> Palindrome Linked List

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
        ListNode* reverseList(ListNode* &prev, ListNode* &curr){
    
            while(curr != NULL){
                ListNode* forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
            }
    
            return prev;
        }
    
        ListNode* getMiddle(ListNode*&head, ListNode*&prevofmiddle){
            ListNode* fast = head;
            ListNode* slow = head;
            while(fast != NULL){
                fast = fast->next;
    
                if(fast != NULL){
                    fast = fast->next;
                    prevofmiddle = slow;
                    slow = slow->next;
                }
            }
    
            return slow;
        }
        bool isPalindrome(ListNode* head) {
    
            //single item
            if(head->next == NULL){
                return true;
            }
    
            //break the ll into two 
            ListNode* prevofmiddle = NULL;
            ListNode* middleNode = getMiddle(head, prevofmiddle);
            //break LL
            prevofmiddle->next = NULL;
    
            //reverse second half
            ListNode* prev = NULL;
            ListNode* curr = middleNode;
            ListNode* secondHalfHead = reverseList(prev, curr);
    
            //compare each element 
            ListNode* temphead1 = head;
            ListNode* temphead2 = secondHalfHead;
    
            while(temphead1 != NULL){
    
                if(temphead1->val != temphead2->val){
                    return false;
                }
                else{
                    temphead1 = temphead1->next;
                    temphead2 = temphead2->next;
                }
            }
            return true;
        }
    };