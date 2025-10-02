//322 --> Coin Change


class Solution {
public:

    int solve(vector<int>&coins, int amount, vector<int>&dp){

        if(amount == 0) return 0;

        if(dp[amount] != -1){
            return dp[amount];
        }

        int minCoinAns = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int coin = coins[i];

            if(coin <= amount){
                int recAns = solve(coins, amount - coin, dp);

                if(recAns != INT_MAX){
                    int coinUsed = 1 + recAns;

                    minCoinAns = min(minCoinAns, coinUsed);
                }
            }
        }
        
        dp[amount] = minCoinAns;
        return dp[amount];

    }

    int coinChange(vector<int>& coins, int amount) {
        
        vector<int>dp(amount+1, -1);

        int ans = solve(coins, amount, dp);
        if(ans == INT_MAX)  
            return -1;
        
        return ans;
    }
};

/*
    Approach:
    - Use recursion + memoization (Top-Down DP).
    - Base case: if amount == 0 → return 0.
    - For each coin ≤ amount, recursively solve for (amount - coin).
    - Take minimum of all valid choices + 1.
    - Memoize results in dp[] to avoid recomputation.
    - If no valid combination → return -1.
    Time: O(n * amount), Space: O(amount)
*/

//OR

class Solution {
public:

    int solveUsingTab(vector<int>&coins, int amount){

        vector<int>dp(amount+1, -1);
        
        dp[0] = 0;

        for(int amt = 1;amt<=amount;amt++){

        
        int minCoinAns = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int coin = coins[i];

            if(coin <= amt){
                int recAns = dp[amt - coin];

                if(recAns != INT_MAX){
                    int coinUsed = 1 + recAns;

                    minCoinAns = min(minCoinAns, coinUsed);
                }
            }
        }
        
        dp[amt] = minCoinAns;
        }

        return dp[amount];

    }

    int coinChange(vector<int>& coins, int amount) {

        int ans = solveUsingTab(coins, amount);
        if(ans == INT_MAX)  
            return -1;
        
        return ans;
    }
};

