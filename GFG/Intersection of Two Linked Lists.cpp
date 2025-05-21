//Intersection of Two Linked Lists

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        // code here
        unordered_map<int, int>map;
        Node* curr = head2;
        
        
        //hashing
        while(curr){
            map[curr->data]++;
            curr = curr->next;
        }
        
        Node* ans = NULL;
        curr = head1;
        Node* it = 0;
        
        while(curr){
            
            if(map.find(curr->data) != map.end()){
                
                if(!ans){
                    ans = curr;
                    it = ans;
                    
                }
                else{
                    if(map[curr->data] > 0){
                        it->next = curr;
                        it = it->next;
                        map[curr->data]--;
                    }
                }
            }
            
            curr = curr->next;
        }
        
        if(it)
        it->next = NULL;
        
        return ans;
    }
};