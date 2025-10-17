//44 --> Wildcard Matching

class Solution {
public:
    bool solveMemo(string&s, string&p, int i, int j, vector<vector<int>>&dp){
        //base cases
        if(i == s.length() && j == p.length()){
            return true;
        }

        if(j == p.length()){
            return false;
        }

        if(i == s.length()){
            //if pattern has * which can be empty sring then it is true
            for(int k=j;k<p.length();k++){
                if(p[k] != '*'){
                    return false;
                }
            }
                return true;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        bool ans;
        //match 
        if(p[j] == '?' || s[i] == p[j]){
            ans = solveMemo(s, p, i+1, j+1, dp);
        }
        else if(p[j] == '*'){
            // "*" can be empty string or can be seq of chars 
            //* is some chars or  * is empty string
            ans = solveMemo(s, p, i+1, j, dp) || solveMemo(s, p, i, j+1, dp);
        }
        else{
            //not match 
            ans = false;
        }

        dp[i][j] = ans;
        return dp[i][j];
    }

        //using Bottom-Up approach(iterative)
    bool solveUsingTab(string s, string p, int m, int n){

        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

        //base case analysis
        dp[m][n] = 1;

        for(int col=0;col<n;col++){
            bool flag = true;
             for(int k=col;k<p.length();k++){
                if(p[k] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[m][col] = flag;
        }

        for(int i=m-1;i>=0;i--){
            for(int j=n;j>=0;j--){
                bool ans;
                if(p[j] == '?' || s[i] == p[j]){
                    ans = dp[i+1][j+1];
                }
                else if(p[j] == '*'){

                    ans = dp[i+1][j] || dp[i][j+1];
                }
                else{
                    ans = false;
                }
                dp[i][j] = ans;
            }
        }

        return dp[0][0];
    }

    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<int>>dp(s.length()+1, vector<int>(p.length()+1, -1));

        return solveMemo(s, p, 0, 0, dp);
    }
};

/*
Approach:
-----------
1. **Problem Type:** Pattern Matching (Dynamic Programming + Recursion with Memoization)
   - Given two strings: `s` (input) and `p` (pattern).
   - The pattern `p` may contain:
     - `?` which matches any single character.
     - `*` which matches any sequence of characters (including empty string).

2. **Recursive Logic:**
   - Use two pointers `i` and `j` to traverse `s` and `p` respectively.
   - Base Cases:
     a. If both strings end (`i == s.length()` and `j == p.length()`): return true.
     b. If pattern ends first (`j == p.length()` but string not): return false.
     c. If string ends but pattern has remaining `*`, check if all remaining are `*` (can match empty).

3. **Transition:**
   - If current characters match or pattern has '?', move both pointers ahead.
   - If pattern has '*', there are two possibilities:
     - `*` matches one or more characters → move in `s` (`i+1, j`)
     - `*` matches an empty string → move in `p` (`i, j+1`)
   - Otherwise, characters don’t match → return false.

4. **Memoization:**
   - A 2D DP table `dp[i][j]` stores whether substring `s[i:]` matches pattern `p[j:]`.
   - Avoids recomputation of overlapping subproblems.

5. **Time Complexity:** O(n * m)
   **Space Complexity:** O(n * m)
   where `n` = length of `s`, `m` = length of `p`.

6. **Example:**
   s = "abc", p = "a*?"
   → '*' can match "b", and '?' matches "c" → returns true.
*/