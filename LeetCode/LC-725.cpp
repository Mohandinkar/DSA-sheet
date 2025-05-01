//725 --> Split Linked List in Parts

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
        vector<ListNode*> splitListToParts(ListNode* head, int k) {
            auto it = head;
            vector<ListNode*>ans(k, NULL);
            int len = 0;
            while(it != NULL){
                len++;
                it = it->next;
            }
    
            //each part size/bucket
            int partSize = len / k;
            //extra node size
            int extraNode = len % k;
    
            it = head;
            for(int i=0 ; i<k && it!=NULL ; i++){
                ans[i] = it;
                //if extra node then add one node to the first bucket
                int currSize = partSize + (extraNode-- > 0 ? 1 : 0);
    
                for(int j=0; j<currSize-1; j++){
                    it = it->next;
                }
    
                auto nextPart = it->next;
                it->next = NULL;
                it = nextPart;
            }
    
            return ans;
    
        }
    };