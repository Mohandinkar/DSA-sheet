//3105 --> Longest Strictly Increasing or Strictly Decreasing Subarray

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int inCount = 1;
        int decCount = 1;
        int ans = 1;
        
        if(nums.empty())
        return 0;
        
        for(int i=0;i<nums.size() && i<nums.size()-1;i++){
            if(nums[i] < nums[i+1]){
                inCount++;
                decCount = 1;
            }
            else if(nums[i] > nums[i+1]){
                decCount++;
                inCount = 1;
            }
            else{
                inCount = decCount = 1;  
            }
            ans = max(ans,max(inCount, decCount));
        }
        return ans;
    }
};