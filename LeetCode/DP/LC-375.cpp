// 375 --. Guess Number Higher or Lower II


//***MERGE INTERVAL PATTERN*** */

class Solution {
public:

    //using DP (top-down)
    int solveMemo(int s, int e, vector<vector<int>>&dp){
        //base case
        if(s >= e){
            return 0;
        }

        if(dp[s][e] != -1){
            return dp[s][e];
        }

        int ans = INT_MAX;
        for(int i=s;i<e;i++){

            ans = min(ans, i + max(solveMemo(s, i-1, dp), solveMemo(i+1, e, dp)));
        }

        dp[s][e] = ans;
        return dp[s][e];
    }

    //using DP (bottom-up) Iterative 
    int solveUsingTab(int n){
        vector<vector<int>>dp(n+1, vector<int>(n+2, 0));

        for(int s = n;s>=1;s--){
            for(int e=1; e<=n;e++){
                
                if(s >= e){
                    continue;
                }
                else{
                    int ans = INT_MAX;
                    for(int i=s;i<e;i++){

                        ans = min(ans, i + max(dp[s][i-1], dp[i+1][e]));
                    }

                    dp[s][e] = ans;
                }
            }
        }

        return dp[1][n];

    }
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        return solveUsingTab(n);
    }
};

/*
    Approach (Memoization - Top-Down):
    - This approach uses recursion with memoization to solve the problem efficiently.
    - The idea is the same as the tabulation method — to find the minimum guaranteed 
      cost to win for any range [s, e].
    - For every guess 'i' in the range [s, e], the cost will be:
          cost = i + max(cost of left part, cost of right part)
    - We recursively calculate this for both subranges and store results in dp[s][e]
      to avoid redundant computations.

    Steps:
    1. Define a recursive function solveMemo(s, e, dp).
    2. Base Case: If s >= e, no cost is needed (return 0).
    3. Memoization Check: If dp[s][e] is already computed, return it.
    4. Try all guesses i in [s, e-1] and take the minimum of the maximum possible cost.
    5. Store and return dp[s][e].

    Time Complexity:  O(n^3)  
        -> For each range [s, e], we try all possible guesses 'i'.
    Space Complexity: O(n^2)  (for DP table) + O(n) (for recursion stack)
        -> Total: O(n^2)
    */