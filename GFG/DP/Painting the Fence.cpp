//Painting the Fence

class Solution {
  public:
    //only Recursion
    
    int solve(int n, int k){
        
        //base case
        if(n == 1)
            return k;
        if(n == 2){
            return (k + k*(k-1));
        }
        
        int ans = (k-1)*(solve(n-1, k) + solve(n-2, k));
        
        return ans;
    }
    
    //using 1d DP memoisation (top-down)
    int MOD = 1000000007; //10^9 + 7
    int solveMemo(int n, int k,vector<int>&dp){
        
        //base case
        if(n == 1)
            return k;
        if(n == 2){
            return (k + k*(k-1));
        }
        
        if(dp[n] != -1)
            return dp[n];
        
        dp[n] = ((k-1)*((solveMemo(n-1, k, dp)%MOD) + (solveMemo(n-2, k, dp))%MOD))%MOD;
        
        return dp[n];
    }
    
    int countWays(int n, int k) {
        
        // return solve(n, k);
        vector<int>dp(n+1, -1);
        return solveMemo(n, k, dp);
        
    }
};

/*
🎯 Function: solveMemo(int n, int k, vector<int>& dp)

🧩 Purpose:
- Uses Top-Down Dynamic Programming (Memoization) to find the number of ways 
  to paint 'n' fence posts using 'k' colours such that no more than 2 consecutive posts 
  have the same colour.

⚙️ Logic:
- Base Cases:
    if n == 1 → only one post ⇒ k ways
    if n == 2 → either both same or different ⇒ k + k*(k - 1)

- Memoization Check:
    If dp[n] already computed, return it to avoid recomputation.

- Recurrence Relation:
    dp[n] = (k - 1) * (dp[n - 1] + dp[n - 2])
    → (k - 1): because current post can be painted with any colour except the previous one.
    → (dp[n - 1] + dp[n - 2]): total ways considering last two posts.

- Apply %MOD to keep result within 32-bit integer range.

🕒 Time Complexity: O(n)
💾 Space Complexity: O(n) for dp array
*/
