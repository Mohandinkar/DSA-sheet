//10 --> Regular Expression Matching

//using recursion
class Solution {
public:

    bool solve(string&s, string&p, int i, int j){
        if(i >= s.length() && j >= p.length()){
            return true;
        }
        if(j >= p.length()){
            return false;
        }

        bool currMatch = (i < s.length()) && (s[i] == p[j] || p[j] == '.');

        if((j+1 <p.length()) && p[j+1] == '*'){

            bool replaceWithEmt = solve(s, p, i, j+2);

            bool replaceWithPrecChar = currMatch && solve(s, p, i+1, j);

            return replaceWithEmt || replaceWithPrecChar;
        } 
        else if(currMatch){
            return solve(s, p, i+1, j+1);
        }
        else{
            //no match
            return false;
        }

    }

    bool isMatch(string s, string p) {
        return solve(s, p, 0, 0);
    }
};

//using memoization (top-down approach)
class Solution {
public:

    bool solveMemo(string&s, string&p, int i, int j, vector<vector<int>>&dp){
        if(i >= s.length() && j >= p.length()){
            return true;
        }
        if(j >= p.length()){
            return false;
        }

        if(dp[i][j] != -1) return dp[i][j];

        bool currMatch = (i < s.length()) && (s[i] == p[j] || p[j] == '.');

        bool ans;

        if((j+1 <p.length()) && p[j+1] == '*'){

            bool replaceWithEmt = solveMemo(s, p, i, j+2, dp);

            bool replaceWithPrecChar = currMatch && solveMemo(s, p, i+1, j, dp);

            ans = replaceWithEmt || replaceWithPrecChar;
        } 
        else if(currMatch){
            ans = solveMemo(s, p, i+1, j+1, dp);
        }
        else{
            //no match
            ans = false;
        }

        dp[i][j]  = ans;
        return dp[i][j];
    }

    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length()+1, vector<int>(p.length()+1, -1));

        return solveMemo(s, p, 0, 0, dp);
    }
};

/*
Approach:
-----------
1. **Problem Type:** Regular Expression Matching (Dynamic Programming + Recursion with Memoization)
   - Given a string `s` and a pattern `p`, determine if `p` matches `s`.
   - The pattern can include:
     - `.` → matches any single character.
     - `*` → matches zero or more occurrences of the preceding character.

2. **Recursive Logic:**
   - Use indices `i` (for string `s`) and `j` (for pattern `p`).
   - Base Cases:
     a. If both reach end → return true (perfect match).
     b. If only pattern ends → return false (string still has characters).

3. **Current Character Match Check:**
   - `currMatch = true` if `s[i] == p[j]` or `p[j] == '.'` (and `i` is within bounds).

4. **Handling '*':**
   - If the next character in pattern is `*`, there are two possibilities:
     a. **Zero occurrences:** skip current char and `*` → move `j + 2`.
     b. **One or more occurrences:** if `currMatch` is true, move ahead in `s` → `i + 1` (keep `j` same).

5. **If No '*':**
   - If current characters match (`currMatch`), move both pointers forward (`i+1`, `j+1`).
   - Otherwise, return false.

6. **Memoization:**
   - A 2D DP array `dp[i][j]` stores results of subproblems to avoid recomputation.

7. **Time Complexity:** O(n * m)
   **Space Complexity:** O(n * m)
   where `n` = length of `s`, `m` = length of `p`.

8. **Example:**
   s = "aab", p = "c*a*b"
   → 'c*' matches empty, 'a*' matches "aa", and 'b' matches 'b' → returns true.
*/