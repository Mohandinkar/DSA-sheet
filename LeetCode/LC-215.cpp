//215 --> Kth Largest Element in an Array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        //min heap
        priority_queue<int, vector<int>, greater<int>>pq;

        //build heap with size k
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }

        //compare with remaining element 
        //element larger than top inserted in heap
        for(int i=k;i<nums.size();i++){
            
            int element = nums[i];
            if(element > pq.top()){
                pq.pop();
                pq.push(element);
            }
        }


        return pq.top();
    }
};