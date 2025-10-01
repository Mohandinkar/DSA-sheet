//300 --> Longest Increasing Subsequence

class Solution {
public:

    int solve(vector<int>&nums, int lastIndex, int i, vector<vector<int>>&dp){

        //base case
        if(i >= nums.size()){
            return 0;
        }

        //step3 check if already present
        if(dp[lastIndex+1][i] != -1){
            return dp[lastIndex+1][i];
        }

        int curr = nums[i];
        int inc = 0;
        if(lastIndex == -1 || curr > nums[lastIndex]){
            inc = 1 + solve(nums, i, i+1, dp);
        }

        int exc = 0 + solve(nums, lastIndex, i+1, dp);

        //step 2 stored in the 2D dp array
        dp[lastIndex+1][i] = max(inc, exc);

        return dp[lastIndex+1][i];
    }

    int lengthOfLIS(vector<int>& nums) {
        int lastIndex = -1;
        int i = 0;

        int n = nums.size();
        //step 1 :create the dp array 
        vector<vector<int>>dp(n+2, vector<int>(n+1, -1));

        return solve(nums, lastIndex, i, dp);
    }
};


// Approach: Top-Down DP (Memoization)
// - We try all possibilities of including or excluding each element
// - State is defined by (lastIndex, i):
//      lastIndex = index of previously picked element (or -1 if none picked)
//      i = current index in nums
// - For each element at index i:
//      1) If nums[i] > nums[lastIndex], we can include it → inc = 1 + solve(i, i+1)
//      2) Or exclude it → exc = solve(lastIndex, i+1)
// - Answer is max(inc, exc)
// - DP table dp[lastIndex+1][i] stores results to avoid recomputation
// - Base case: if i >= n, return 0
//
// Time Complexity: O(n^2)  (each state (lastIndex, i) computed once)
// Space Complexity: O(n^2) for dp + O(n) recursion stack
