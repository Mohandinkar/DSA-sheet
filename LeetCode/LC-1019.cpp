//1019 --> Next Greater Node In Linked List

//using stack

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>arr;

        ListNode*temp = head;
        
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        //init with 0
        vector<int>ans(arr.size());

        stack<int>st;

        for(int i=0;i<arr.size();i++){

                while(!st.empty() && arr[i] > arr[st.top()]){
                    ans[st.top()] = arr[i];
                    st.pop();
                }

                st.push(i);
            
           
        }

        
        return ans;

    }
};