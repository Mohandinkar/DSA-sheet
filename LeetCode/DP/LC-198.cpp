//198 --> House Robber

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

//Top-down DP (Recursion + Memoization)
class Solution {
public: 
    int solveUsingDp(vector<int>&nums, int i, vector<int>&dp){

        //base case
        if(i >= nums.size())
            return 0;

        if(dp[i] != -1){
            return dp[i];
        }

        int include = nums[i] + solveUsingDp(nums, i+2, dp);
        int exclude = 0 + solveUsingDp(nums, i+1, dp);

        dp[i] = max(include, exclude);

        return dp[i];
    }
    int rob(vector<int>& nums) {
      vector<int>dp(nums.size()+1, -1);

      int i=0;
      return solveUsingDp(nums, i, dp);  
    }
};


// Approach:  
// - Use recursion + memoization (top-down DP).  
// - At each index, we have two choices:  
//    1. Include current house → add nums[i] + solve(i+2).  
//    2. Exclude current house → move to next house solve(i+1).  
// - Store results in dp[i] to avoid recomputation.  
// - Final answer is max money robbed starting from index 0.  
//
// Time Complexity: O(n) → each state i computed once.  
// Space Complexity: O(n) (dp array + recursion stack).  


//OR// Using Bottom-up DP
class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() < 2)
            return nums[0];

        vector<int>dp(nums.size());

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2;i<nums.size();i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }

        int ans = dp[dp.size() - 1];

        return ans;
    }
};