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


    //using tabulation (Bottom-Up)
     int solveTab(int n, int k){
         
        vector<int>dp(n+1, -1);
        //base case analysis
        dp[1] = k;
        dp[2] = (k + k*(k-1));
        
        for(int i=3;i<=n; i++){
            dp[i] = ((k-1)*((dp[i-1])%MOD + (dp[i-2])%MOD))%MOD;

        }
        
        return dp[n];
    }


        /*
    🎯 Approach (Bottom-Up Tabulation):
    - Build the solution iteratively using a DP array.
    - Base cases:
        dp[1] = k
        dp[2] = k + k * (k - 1)
    - Relation:
        dp[i] = (k - 1) * (dp[i - 1] + dp[i - 2])
    - Fill dp[] from 3 to n using the relation.
    - Return dp[n] as the final answer.
    - TC: O(n), SC: O(n)
    */

     //Space optimization 
     int solveSO(int n, int k){
         
       int prev2 = k;
       int prev1 = (k + k*(k-1));
       
       if(n == 1)
         return prev2;
        if(n==2)
            return prev1;
        
        
        for(int i=3;i<=n; i++){
            int curr = ((k-1)*( (prev2) % MOD + (prev1) % MOD))%MOD;
            
            prev2 = prev1;
            prev1 = curr;

        }
        return prev1; 
    }

        /*
    🎯 Approach (Space Optimized):
    - Instead of using a full DP array, keep only the last two computed values.
    - Base cases:
        prev2 = dp[1] = k
        prev1 = dp[2] = k + k * (k - 1)
    - For i = 3 to n:
        curr = (k - 1) * (prev1 + prev2) % MOD
        Update prev2 = prev1, prev1 = curr
    - Return prev1 as the final answer.
    - TC: O(n), SC: O(1)
    */


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
