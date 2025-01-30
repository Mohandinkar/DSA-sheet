//The Painter's Partition Problem-II

// Dilpreet wants to paint his dog's home that has n boards with different lengths. 
// The length of ith board is given by arr[i] where arr[] is an array of n integers. 
// He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board.

class Solution {
  public:
  
    bool isPossibleSolution(vector<int>&arr, int k, int mid){
        //count is a var that stores the painters number
        int count = 1;
        int timeSum = 0;
        
        for(int i=0;i<arr.size();i++){
            
            if(arr[i] > mid)
            return false;
            
            if(arr[i]+timeSum > mid){
                count++;
                timeSum = arr[i];
                
                if(count > k){
                    return false;
                }
            }
            else{
                timeSum += arr[i];
            }
        }
        return true;
    }
    
    int minTime(vector<int>& arr, int k) {
        // code here
        long long start = 0;
        
        //max board allocated => sum of array element
        long long end = accumulate(arr.begin(),arr.end(), 0);
        long long ans = -1;
        
        while(start <= end){
            
            long long mid = start +(end-start)/2;
            if(isPossibleSolution(arr,k,mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }

        }
        return ans;
        // return minimum time
        
    }
};