//1171 --> Remove Zero Sum Consecutive Nodes from Linked List

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
    void sanitize(ListNode*curr, unordered_map<int, ListNode*>&mp, int currsum){
        int temp = currsum;

        while(true){
            temp += curr->val;

            if(temp == currsum) break;

            mp.erase(temp);

            curr = curr->next;
        }
    }

    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head ||!head->next && head->val == 0) return 0;

        auto it = head;
        int currsum = 0;

        unordered_map<int, ListNode*>mp;

        while(it){
            currsum += it->val;

            if(currsum == 0){
                head = it->next;
                mp.clear();
            }
            else if(mp.find(currsum) != mp.end()){
                sanitize(mp[currsum]->next, mp, currsum);
                mp[currsum]->next = it->next;

            }
            else{
                mp[currsum] = it;
            }
            it = it->next;
        }

        return head;

    }
};