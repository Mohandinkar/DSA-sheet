//2181 --> Merge Nodes in Between Zeros

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
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return NULL;

        ListNode*slow = head;
        ListNode*fast = head->next;

        int sum = 0;

        while(fast){
            if(fast->val != 0){
                sum += fast->val;
            }
            else{
                slow->val = sum;
                if(fast->next)
                slow = slow->next;
                sum = 0;
            }

            fast = fast->next;
        }

        ListNode*temp = slow->next;
        slow->next = nullptr;

        //deleting the remaining list to avoid the memory leakage
        while(temp) {
            ListNode*nxt = temp->next;
            delete temp;
            temp = nxt;
        }

        return head;

    }
};