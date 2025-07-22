//279 --> Perfect Squares

class Solution {
public:

    int solve(int n, vector<int>&memo){
        //base case
        if(n == 0)
            return 0;

        
        // If the result for 'n' is already computed, return it
        if (memo[n] != -1)
            return memo[n];
        
        int ans = INT_MAX;
        int end = sqrt(n);
        int i = 1;

        while(i <= end){
            int perfectSquare = i * i;
            int noOfPerfectSquares = 1 + solve(n - perfectSquare, memo);

            if(noOfPerfectSquares < ans){
                ans = noOfPerfectSquares;
            }
        
            i++;
        }

        return memo[n] = ans;
    }
    int numSquares(int n) {
        vector<int>memo(n+1, -1);

        return solve(n, memo);
    }
};