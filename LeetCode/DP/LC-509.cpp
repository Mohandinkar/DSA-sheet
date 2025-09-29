//509 --> Fibonacci Number



class Solution {
public:
    int fib(int n) {
        
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        
        int ans = fib(n-1) + fib(n-2);

        return ans;
    }
};

// TC = O(2^n)
// SC = O(n)

//Using DP (Bottom-up DP)
class Solution {
public:

    //using DP (Top-down DP)
    int solveUsingMemo(int n, vector<int>&dp){
        //Base case
        if(n == 0) return 0;
        if(n == 1) return 1;

        //step 3 : check if the ans already exist or not
        if(dp[n] != -1){
            return dp[n];
        }

        //step 2 : store the ans in dp array
        dp[n] = solveUsingMemo(n-1, dp) + solveUsingMemo(n-2, dp);

        return dp[n];
    }

    int fib(int n) {
        //step 1 : create the array
        vector<int>dp(n+1, -1);

        return solveUsingMemo(n, dp);
    }
};

/*
Approach:
- The problem asks for nth Fibonacci number.
- A naive recursive approach has exponential time due to repeated calculations.
- To optimize, we use Dynamic Programming with memoization:
    1. Create a DP array to store results of subproblems.
    2. Base cases: fib(0) = 0, fib(1) = 1.
    3. For each n, fib(n) = fib(n-1) + fib(n-2).
    4. If fib(n) is already computed (dp[n] != -1), return it directly.
    5. Otherwise compute recursively, store in dp, and return.
- This avoids recomputation and reduces time complexity.

Time Complexity: O(n)  (each state is computed once)
Space Complexity: O(n)  (for dp array + recursion stack)
*/


