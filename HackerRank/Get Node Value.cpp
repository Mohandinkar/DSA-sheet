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


//--------------OR------------------

int getLength(SinglyLinkedListNode*&llist){
    SinglyLinkedListNode* temp = llist;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
        
    }
    return count;
}

int getNode(SinglyLinkedListNode* llist, int positionFromTail) {
    int len = getLength(llist);
    int fromStart = (len - positionFromTail);
    int count = 1;
    SinglyLinkedListNode* point = llist;
    while(count++ != fromStart){
        point = point->next;
    }
    
    return point->data;
