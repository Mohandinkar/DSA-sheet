//148 --> Sort List

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
    //using merge sort

    ListNode*findMid(ListNode*head){
        ListNode*slow = head;
        ListNode*fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(-1); //dummy node intialize
        if(!list1 && !list2) return NULL;
        ListNode* it = ans;
        ListNode* temp = list1;
        ListNode* temp1 = list2;

        while(temp != NULL && temp1 != NULL){

            if(temp->val <= temp1->val){
                it->next = temp;
                temp = temp->next;
            }
            else{
                it->next = temp1;
                temp1 = temp1->next;
            }

            it = it->next;
        }

        if(temp != NULL){
            it->next = temp;
        }
        else{
            it->next = temp1;
        }
        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
        return head;

        ListNode*mid = findMid(head);

        ListNode*left = head;
        ListNode*right = mid->next;
        mid->next = 0;

        //recursive call 
        left = sortList(left);
        right = sortList(right);

        //merge the two linked list
        ListNode*mergeLL =  mergeTwoLists(left, right);

        return mergeLL;
    }
};