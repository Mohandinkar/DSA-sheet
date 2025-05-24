//138 --> Copy List with Random Pointer


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* solve(unordered_map<Node*, Node*>&mp, Node* head){
        if(!head) return NULL;

        Node* newHead = new Node(head->val);

        mp[head] = newHead;
        newHead->next = solve(mp, head->next);

        if(head->random){
            newHead->random = mp[head->random];
        }

        return newHead;
    }
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>mp;

        return solve(mp, head);
    }
};

// Time Complexity: O(N), where N is the number of nodes in the linked list.
// Space Complexity: O(N), for the unordered_map to store the mapping of original nodes to their copies.