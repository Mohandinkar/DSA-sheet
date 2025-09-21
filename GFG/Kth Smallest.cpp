//Kth Smallest


// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        
        //max heap 
        priority_queue<int>pq;
        
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        
        //comapre with remaining 
        // smallest than top ele then push into queue
        for(int i=k;i<arr.size();i++){
            
            int element = arr[i];
            if(element < pq.top()){
                pq.pop();
                pq.push(element);
            }
        }
        //top will be kth smallest 
       return pq.top();
    }
};