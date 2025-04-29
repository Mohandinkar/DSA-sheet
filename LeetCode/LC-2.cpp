//2 --> Add Two Numbers

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
        ListNode* iterative(ListNode* l1, ListNode* l2){
            ListNode* ans = new ListNode(-1); //dummy node
            ListNode* it = ans;
    
            int carry = 0;
            while(l1 || l2 || carry){
                int a = l1 ? l1->val : 0;
                int b = l2 ? l2->val : 0;
    
                int sum = a + b + carry;
    
                int digit = sum%10;
                carry = sum/10;
    
                it->next = new ListNode(digit);
                it = it->next;
    
                l1 = l1 ? l1->next : nullptr;
                l2 = l2 ? l2->next : nullptr;
    
            }
            
                ListNode* final = ans->next;
                delete ans;
                return final;
        }
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
           return iterative(l1, l2);
        }
    };

//---------OR----------
//BY USING RECURSION

class Solution {
    public:
        ListNode* recursive(ListNode* l1, ListNode* l2, int carry = 0){
    
            //base case
            if(!l1 && !l2 && !carry) return 0;
    
            //solve case1
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int sum = a+b+carry;
    
            int digit = sum%10;
            carry = sum/10;
    
            ListNode* ans = new ListNode(digit);
            //recursive call
            ans->next = recursive(l1 ? l1->next :l1, l2 ? l2->next : l2, carry);
    
            return ans;
    
           
        }
    
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
           return recursive(l1, l2);
        }
    };