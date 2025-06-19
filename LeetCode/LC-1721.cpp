//1721 --> Swapping Nodes in a Linked List


class Solution {
public:
    int Len(ListNode*head){
        if (!head) return 0;

        return 1 + Len(head->next);
    }

    ListNode* swapNodes(ListNode* head, int k) {
        //case 1
        if(!head || !head->next)
        return head;

        int len = Len(head);
        int lpos = k;
        int rpos = len - k + 1;

        if(rpos < lpos )
        swap(lpos, rpos);

        //case 2
        if(lpos == rpos) return head;

        //case 3
        if(len == 2){
            ListNode*nextNode = head->next;
            nextNode->next = head;
            head->next = NULL;
            head = nextNode;
            return head;
        }

        //case 4
        if(lpos == 1){
            ListNode*rp = head;
            ListNode*ln = head;


            for(int i=0;i<rpos-2;i++)
                rp = rp->next;
            
            ListNode*rn =rp->next;
            ListNode* rsave = rn->next;
            rn->next = ln->next;
            rp->next = ln;
            ln->next = rsave;
            head = rn;

            return head;
        }

        //case 5 => rpos is next to lpos 
        int diffBetNodes = rpos - lpos - 1;
        if(diffBetNodes == 0){
            ListNode*lp = head;
            for(int i=0;i<lpos-2;++i)
                lp = lp->next;
            
            ListNode*ln = lp->next;
            
            ListNode*rp = head;
            for(int i=0;i<rpos-2;i++)
                rp = rp->next;
            ListNode*rn = rp->next;
            ListNode*rsave = rn->next;

            //swapping
            lp->next = rn;
            rn->next = rp;
            rp->next = rsave;

            return head;
        }
        else{
            //difference >=1 and k is not 1 and n and not the middle
            ListNode*lp = head;
            for(int i=0;i<lpos-2;++i)
                lp = lp->next;
            
            ListNode*ln = lp->next;
            
            ListNode*rp = head;
            for(int i=0;i<rpos-2;i++)
                rp = rp->next;
            ListNode*rn = rp->next;
            ListNode*rsave = rn->next;

            //swapping
            lp->next = rn;
            rn->next = ln->next;
            rp->next = ln;
            ln->next = rsave;

            return head;
        }
    }
};