//53 --> Maximum Subarray

//Kadane's Algorithm 

class Solution {
public:

    int kadaneAlgo(vector<int>nums){
        int ans= INT_MIN;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            sum = sum + num;
            ans = max(ans,sum);
            if(sum<0){
                sum = 0;
            }
        }
        return ans;
    }
    int maxSubArray(vector<int>& nums) {
      return  kadaneAlgo(nums);
    }
};