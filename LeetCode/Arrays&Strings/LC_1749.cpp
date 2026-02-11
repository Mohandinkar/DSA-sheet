
// 1749 --> Maximum Absolute Sum of Any Subarray

//Kadane's Algorithm

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int n = nums.size();

        int sum = nums[0];
        int maxSubSum = nums[0];
        //maxsubarray sum
        for(int i=1;i<n;i++){
            
            sum = max(nums[i], sum+nums[i]);

            maxSubSum = max(maxSubSum, sum);
        }

        //minsubarray sum
        sum = nums[0];
        int minSubSum = nums[0];

        for(int i=1;i<n;i++){
            
            sum = min(nums[i], sum+nums[i]);

            minSubSum = min(minSubSum, sum);
        }

        return max(maxSubSum, abs(minSubSum));
    }
};