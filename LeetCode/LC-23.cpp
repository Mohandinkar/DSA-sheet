//23 --> Merge k Sorted Lists

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


//custom comparator for the min heap 
class compare{

    public:
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        //min heap
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;

        ListNode* head = NULL;
        ListNode* tail = NULL;

        for(int row = 0;row<lists.size();row++){

            ListNode* temp = lists[row];
            if(temp != NULL)
                pq.push(temp);
        }


        while(!pq.empty()){
            ListNode* front = pq.top();
            pq.pop();

            if(head == NULL && tail == NULL){
                head = front;
                tail = front;
            }
            else{
               tail->next = front;
               tail = front;
                
            }
            
            if(tail->next != NULL)
                pq.push(tail->next); 
        }

        return head;
    }
};


/*
Approach:
We need to merge K sorted linked lists into one sorted linked list.  
The idea is to use a Min-Heap (priority_queue with custom comparator).  

Steps:
1. Push the head node of each non-empty linked list into the Min-Heap.  
   - Heap stores nodes based on their values (smallest value at the top).  
2. Repeatedly extract the smallest node from the heap:  
   - Add it to the result list (maintain head and tail pointers).  
   - If this node has a `next`, push that next node into the heap.  
3. Continue until the heap is empty → the merged list is fully built.  

Why it works:
- At every step, the heap gives us the smallest available node.  
- By always pushing the `next` of the extracted node, we maintain sorted order across all lists.  

Time Complexity: O(N log K)  
- N = total number of nodes across all lists.  
- Each insertion/extraction in heap costs log K.  

Space Complexity: O(K)  
- Heap stores at most one node from each list at a time.  
*/