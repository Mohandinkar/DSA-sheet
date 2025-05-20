//Get Node Value

void fun(SinglyLinkedListNode* head, int &positionFromTail, int &ans){
    if(head == nullptr)
        return;
    
    fun(head->next, positionFromTail, ans);
    
    if(positionFromTail == 0){
        ans = head->data;
    }
    
    positionFromTail--;
    
}
int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    
    
    int ans =-1;
    fun(llist, positionFromTail,ans);
    
    return ans;
}