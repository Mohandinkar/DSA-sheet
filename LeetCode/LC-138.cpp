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

//------------------OR------------------

//optimimzed approach using O(1) space

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
    Node* copyRandomList(Node* head) {
         if(!head) return NULL;

        //clone 1->1->3->3
        Node* it = head;
        while(it){
            Node* clonedNode = new Node(it->val);
            clonedNode->next = it->next;
            it->next = clonedNode;

            it = it->next->next;
        }

        //Link to random pointer 
        it = head;
        while(it){
            Node*clonedNode = it->next;
            clonedNode->random = it->random ? it->random->next : nullptr;
            it = it->next->next;

        }

        //Detach the clone nodes from whole list
        it = head;
        Node* cloneHead = it->next;

        while(it){
            Node* temp = it->next;
            it->next = it->next->next;

            if(temp->next){
                temp->next = temp->next->next;

            }

            it = it->next;
        }

        return cloneHead;
    }
};