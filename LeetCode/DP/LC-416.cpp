//416 --> Partition Equal Subset Sum
class Solution {
public:
    
    //2 variables are changing in the rec so used the 2D DP
    bool solveMemo(vector<int>& nums, int targetSum, int i, vector<vector<int>>&dp){
        //base case
        if(i >= nums.size())
            return false;
        if(targetSum < 0)
            return false;
        if(targetSum == 0)
            return true;
        
        if(dp[targetSum][i] != -1)
            return dp[targetSum][i];
        
        bool include = solveMemo(nums, targetSum - nums[i], i+1, dp);
        bool exclude = solveMemo(nums, targetSum, i+1, dp);

        dp[targetSum][i] = include || exclude;

        return  dp[targetSum][i];
    }

    bool solveUsingTab(vector<int>& nums, int targetSum){
        
        int n = nums.size();
        vector<vector<bool>>dp(targetSum+1, vector<bool>(n+1, 0));

        //base case analysis
        for(int col=0;col<=n;col++){
            dp[0][col] = true;
        }

        for(int t=1;t<=targetSum;t++){
            for(int i = n-1;i>=0; i--){
            
            bool include = false;
            if(t - nums[i] >= 0){
                include = dp[t - nums[i]] [i+1];
            }
           
            bool exclude = dp[t] [i+1];

            dp[t] [i] = include || exclude;
 
            }
        }

        //analysis from initilzation function
        return dp[targetSum][0];
    }

    bool canPartition(vector<int>& nums) {

        int n =nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum % 2 != 0)
            return false;
    
        int targetSum = sum / 2;
        int i = 0;

        vector<vector<int>>dp(targetSum+1, vector<int>(n+1, -1));

        // return solveMemo(nums, targetSum, i, dp);
        return solveUsingTab(nums, targetSum);
    }
};

// Approach: Top-Down DP (Memoization)
// - Problem: Check if array can be partitioned into two subsets with equal sum
// - Compute total sum, target = sum/2
// - Use recursion with 2 choices for each element:
//      1) Include nums[i] → reduce targetSum by nums[i]
//      2) Exclude nums[i] → keep targetSum same
// - State: dp[targetSum][i] stores whether targetSum can be formed using elements from index i
// - Base cases:
//      targetSum == 0 → true (subset found)
//      targetSum < 0 or i >= n → false
//
// Time Complexity: O(n * targetSum)  (each state computed once)
// Space Complexity: O(n * targetSum) for dp + O(n) recursion stack
