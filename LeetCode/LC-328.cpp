//328 --> Odd Even Linked List

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode*odd = head; //make the odd list
        ListNode*even = head->next;// for even list
        ListNode*evenHead = even;

        while(even && even->next){
            odd->next = even->next;
            even->next =  even->next->next;
            odd = odd->next;
            even = even->next;

        }

        //join the two list oddlist->evenlist
        odd->next = evenHead;

        return head;
    }
};

// Time Complexity: O(n) where n is the number of nodes in the linked list.
// Space Complexity: O(1) since we are not using any extra space except for a few pointers.