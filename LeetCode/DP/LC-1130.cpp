//1130 --> Minimum Cost Tree From Leaf Values

//merge interval pattern

class Solution {
public:

    //using 2DP (top-down)
    int solveMemo(vector<int>& arr, map<pair<int,int>, int>&maxiMp, int s, int e,vector<vector<int>>&dp){
        //base case
        if(s >= e)
            return 0;
        
        if(dp[s][e] != -1){
            return dp[s][e];
        }

        int ans = INT_MAX;

        for(int i = s;i<e;i++){

            int leftRangeMaxVal = maxiMp[{s, i}];
            int rightRangeMaxVal = maxiMp[{i+1, e}];
            int nonLeafVal = leftRangeMaxVal * rightRangeMaxVal;

            ans = min(ans, nonLeafVal + solveMemo(arr,maxiMp, s, i, dp) + solveMemo(arr, maxiMp, i+1, e, dp));
        }

        dp[s][e] = ans;
        return dp[s][e];
    }

    //using 2DP (bottom-up) iterative
    int solveUsingTab(vector<int>& arr, map<pair<int,int>, int>&maxiMp){
        
        vector<vector<int>>dp(arr.size()+1, vector<int>(arr.size()+1, 0));

        int n = arr.size();
        for(int s=n-1;s>=0;s--){
            for(int e=0;e<=n-1;e++){

                if(s >= e){
                    continue;
                }
                else{
                    int ans = INT_MAX;

                    for(int i = s;i<e;i++){

                        int leftRangeMaxVal = maxiMp[{s, i}];
                        int rightRangeMaxVal = maxiMp[{i+1, e}];
                        int nonLeafVal = leftRangeMaxVal * rightRangeMaxVal;

                        ans = min(ans, nonLeafVal + dp[s][i] + dp[i+1][e]);
                    }

                    dp[s][e] = ans;
                }
            }
        }

        return dp[0][n-1];
    }

    int mctFromLeafValues(vector<int>& arr) {
        
        //step1 dp creation
        vector<vector<int>>dp(arr.size()+1, vector<int>(arr.size()+1, -1));
        //used map for storing  max value in range to int mapping 
        map<pair<int, int>, int>maxiMp;

        int n = arr.size();

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){

                if(i == j){
                    maxiMp[{i, j}] = arr[i];
                }
                else{
                    maxiMp[{i, j}] = max(maxiMp[{i, j-1}], arr[j]);
                }
            }
        }

        int s = 0;
        int e = n-1;

        // return solveMemo(arr,maxiMp, s, e, dp);
        return solveUsingTab(arr, maxiMp);
    }
};

/*
Approach (Memoization - Top-Down):

- Goal: Build a binary tree from leaf values such that the sum of all non-leaf node values 
  (each being the product of the max leaf in its left & right subtrees) is minimized.

Why use maxiMp:
- To store the maximum value in every subarray [s, e] beforehand.
- Avoids recalculating max(arr[s...e]) repeatedly inside recursion, reducing time complexity.

Steps:
1. Precompute maxiMp[{i, j}] → max value in arr[i...j].
2. Define dp[s][e] = minimum cost to build a tree from subarray [s, e].
3. Base Case: If s >= e → return 0 (single leaf, no cost).
4. Recursively try every partition point i in [s, e-1]:
       cost = (max_left * max_right) + solve(left) + solve(right)
5. Take the minimum of all possible partitions.
6. Store result in dp[s][e] and return it.

Time:  O(n^3)
Space: O(n^2)
*/
