

class Solution {
  public:
  
    bool isPossibleSolution(vector<int>&arr,int k, int sol){
        int pageSum = 0;
        int count  = 1;
        
        for(int i=0;i<arr.size();i++){
            
            if(arr[i] > sol){
                return false;
            }
            if(pageSum+arr[i] > sol){
                count++;
                pageSum = arr[i];
                
                if(count > k){
                    return false;
                }
            }
            else{
                pageSum += arr[i];
            }
        }
        return true;
    }
    
    int findPages(vector<int> &arr, int k) {
        // code here
        int start = 0;
        int end = accumulate(arr.begin(),arr.end(),0);
        int ans = -1;
        
        if(k > arr.size())
        return -1;
        
        while(start<=end){
            
            int mid = (start+end) >> 1;
            
            if(isPossibleSolution(arr,k,mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};