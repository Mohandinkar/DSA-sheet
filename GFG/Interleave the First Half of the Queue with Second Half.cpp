//Interleave the First Half of the Queue with Second Half

class Solution {
  public:
    queue<int> rearrangeQueue(queue<int> q1) {
        // code here
        queue<int>q2;
        
        int n = q1.size();
        int half = n/2;
        
        while(half--){
            int ele = q1.front();
            q1.pop();
            
            q2.push(ele);
        }
        
        //first half -> q2
        //second half -> q1
        
        
        while(!q2.empty()){
            int ele = q2.front();
            q2.pop();
            
            q1.push(ele);
            
            ele = q1.front();
            q1.pop();
            
            q1.push(ele);
        }
        
        return q1;
    }
};