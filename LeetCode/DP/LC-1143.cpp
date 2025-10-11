//1143 ---> Longest Common Subsequence


class Solution {
public:
    int solveMemo(string &text1, string &text2, int i, int j, vector<vector<int>>&dp){
        //base case
        if(i >= text1.length() || j >= text2.length()){
            return 0;
        }

        //check already exist or not
        if(dp[i][j] != -1){
            return dp[i][j] ;
        }

        //match
        int ans = 0;
        if(text1[i] == text2[j]){
            ans = 1 + solveMemo(text1, text2, i+1, j+1, dp);
        }
        else{
            //no match
            ans = 0 + max(solveMemo(text1, text2, i+1, j, dp), solveMemo(text1, text2, i, j+1, dp));
        }
        //stored in dp
        dp[i][j] = ans;
        return dp[i][j] ;
    }

    int longestCommonSubsequence(string text1, string text2) {

        vector<vector<int>>dp(text1.length()+1, vector<int>(text2.length()+1, -1));
        
        int i=0, j=0;
        return solveMemo(text1, text2, i, j, dp);
    }
};

//OR
//using bottom-up (iterative)
class Solution {
public:

    int solveUsingTab(string&text1, string&text2){

        vector<vector<int>>dp(text1.length()+1, vector<int>(text2.length()+1, 0));

        for(int i=text1.length()-1;i>=0;i--){
            for(int j=text2.length()-1;j>=0;j--){
            //match
            int ans = 0;
            if(text1[i] == text2[j]){
                ans = 1 + dp[i+1][j+1];
            }
            else{
                //no match
                ans = 0 + max(dp[i+1][j], dp[i][j+1]);
            }
            //stored in dp
            dp[i][j] = ans;

            }
        }

        return dp[0][0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int i=0, j=0;

        return solveUsingTab(text1, text2);
    }
};


//space optimization
//space optimization
    
    int solveUsingTabSO(string&text1, string&text2){

        vector<int>prev(text2.length()+1, 0);
        vector<int>curr(text2.length()+1,0);

        for(int i=text1.length()-1;i>=0;i--){
            for(int j=text2.length()-1;j>=0;j--){
            //match
            int ans = 0;
            if(text1[i] == text2[j]){
                ans = 1 + prev[j+1];
            }
            else{
                //no match
                ans = 0 + max(prev[j], curr[j+1]);
            }
            //stored in dp
            curr[j] = ans;

            }

            //shifting 
            prev = curr;
        }

        return prev[0];
    }