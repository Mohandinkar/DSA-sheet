//5 -->Longest Palindromic Substring

//using recursion
class Solution {
public:
    int maxLen = 1, start = 0;
    bool solve(string&s, int i,int j){
        //base case
        if(i >= j){
            return true;
        }
        bool flag = false;
        if(s[i] ==s[j]){
            flag = solve(s, i+1, j-1);
        }

        if(flag){
            int currLen = j - i + 1;
            if(currLen > maxLen){
                maxLen = currLen;
                start = i;
            }

        }

        return flag;
    }
    string longestPalindrome(string s) {

        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){

                bool isP = solve(s, i, j);
            }
        }

        return s.substr(start, maxLen);
    }
};

///-------------------OR-----------------------
//using DP Top-Down
class Solution {
public:
    int maxLen = 1, start = 0;
    bool solveMemo(string&s, int i,int j, vector<vector<int>>&dp){
        //base case :single character or empty string is palindrome
        if(i >= j){
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        bool flag = false;
        if(s[i] ==s[j]){
            flag = solveMemo(s, i+1, j-1, dp);
        }

        if(flag){
            int currLen = j - i + 1;
            if(currLen > maxLen){
                maxLen = currLen;
                start = i;
            }

        }

        return dp[i][j] = flag;
    }
    string longestPalindrome(string s) {

        vector<vector<int>>dp(s.size(), vector<int>(s.size(), -1));

        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){

                bool isP = solveMemo(s, i, j, dp);
            }
        }

        return s.substr(start, maxLen);
    }
};


/*
Approach:
-----------
- Use recursion + memoization to check if substring s[i...j] is a palindrome.  
- Base case: if i >= j, it's a palindrome.  
- If s[i] == s[j] and inner substring is palindrome → update longest length.  
- Try all substrings using nested loops and track max length and start index.  
- Time Complexity: O(n²), Space: O(n²).
*/