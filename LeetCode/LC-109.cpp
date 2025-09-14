//109 --> Convert Sorted List to Binary Search Tree

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* head){
        ListNode* temp = head;
        int c = 0;
        while(temp != NULL){
            temp = temp->next;
            c++;
        }

        return c;
    }

    TreeNode* solve(ListNode* &head, int n){
        if(!head || n <= 0)
            return NULL;
        
        //L-N-R
        //L
        TreeNode* leftSubTree = solve(head, n/2);
        //N
        TreeNode* root = new TreeNode(head->val);

        root->left = leftSubTree;

        head = head->next;
        //R
        TreeNode* rightSubTree = solve(head, n - n/2 -1);
        root->right = rightSubTree;
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {

        int n = getLength(head);
        return solve(head, n);
    }
};