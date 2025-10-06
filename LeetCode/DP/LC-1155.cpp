//1155 --> Number of Dice Rolls With Target Sum

class Solution {
public:
    long long int MOD = 1000000007;
    int solveMemo(int n, int k, int target, vector<vector<long long int>>&dp){

        //base cases
        if(n < 0 || target < 0)
            return 0;
        if(n == 0 && target == 0)   
            return 1;
        if(n == 0 && target != 0)
            return 0;
        if(n != 0 && target == 0)
            return 0; 

        if(dp[n][target] != -1)
            return dp[n][target];
        
        long long int ans = 0;

        for(int i=1;i<=k;i++){
            ans += solveMemo(n-1, k, target - i, dp);
        }

        dp[n][target] = ans % MOD;
        return dp[n][target];
    }

     /*
    Approach (Top-Down Memoization):
    1. Define dp[n][target] → number of ways to get 'target' using 'n' dice.
    2. Base: 
       - If n == 0 && target == 0 → 1 (valid way)
       - If n == 0 or target < 0 → 0 (invalid)
    3. Transition: 
       dp[n][target] = Σ dp[n-1][target - i] for i in [1..k]
    4. Return dp[n][target].
    Time: O(n * k * target)
    Space: O(n * target) + recursion stack
    */


    //using bottom-up (iterative)
     int solveUsingTab(int n, int k, int target){
        vector<vector<long long int>>dp(n+1 ,vector<long long int>(target+1, 0));

        dp[0][0] = 1;

        for(int N = 1;N<=n;N++){

            for(int t = 1;t<=target;t++){
                long long int ans = 0;

                for(int i=1;i<=k;i++){

                    if(t - i >= 0){
                        ans += dp[N-1] [t - i];
                    }
                }
                dp[N][t] = ans % MOD;  
            }
        }
        return dp[n][target];
    }


      /*
    Approach (Bottom-Up Tabulation):
    1. dp[N][t] = number of ways to reach sum 't' using 'N' dice.
    2. Base: dp[0][0] = 1 → one way to make sum 0 using 0 dice.
    3. Transition:
       dp[N][t] = Σ dp[N-1][t - i] for each face value i (1 ≤ i ≤ k, and t - i ≥ 0)
    4. Build iteratively from smaller subproblems.
    Time: O(n * k * target)
    Space: O(n * target)
    */


    //space optimization 
     int solveUsingTabSO(int n, int k, int target){
        
        vector<int>prev(target+1, 0);
        vector<int>curr(target+1, 0);

        prev[0] = 1;

        for(int N = 1;N<=n;N++){

            for(int t = 1;t<=target;t++){
                long long int ans = 0;

                for(int i=1;i<=k;i++){

                    if(t - i >= 0){
                        ans += prev[t - i];
                    }
                }
             curr[t] = ans % MOD;  
            }
            //shifting
            prev = curr;
        }
        return curr[target];
    }

      /*
    Approach (Space Optimized Tabulation):
    1. Observe that dp[N][t] depends only on dp[N-1][*].
    2. Replace 2D array with two 1D arrays: `prev` and `curr`.
    3. For each dice roll, compute curr[t] using prev[t - i].
    4. Shift prev = curr after each iteration.
    Time: O(n * k * target)
    Space: O(target)
    */


    int numRollsToTarget(int n, int k, int target) {

        vector<vector<long long int>>dp(n+1 ,vector<long long int>(target+1, -1));

        // return solveMemo(n, k, target, dp);
        return  solveUsingTabSO(n, k, target);
    
    }
};