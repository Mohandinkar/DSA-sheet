//2816 --> Double a Number Represented as a Linked List

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

    void doubleNum(ListNode*head, int&carry){
        //base case
        if(!head) return;
        
        //recursively go to last node
        doubleNum(head->next, carry);

        //start from last node => right to left

        int product = head->val * 2 + carry;
        int value = product % 10;
        carry = product / 10;
        head->val = value;
    }

    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        doubleNum(head, carry);
        if(carry){
            ListNode* newNode = new ListNode(carry);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};