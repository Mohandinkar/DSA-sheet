//221 --> Maximal Square

//solution is based on the recursion so it will through the TLE but do not give the wrong answer
//will be solved by DP


class Solution {
    public:
    
        int solve(vector<vector<char>>& matrix, int i, int j, int row, int col, int&maxi){
            //base case
            if(i>=row || j>=col){
                return 0;
            }
    
            //explore
            int right=solve(matrix, i, j+1, row, col, maxi);
            int diagonal=solve(matrix, i+1, j+1, row, col, maxi);
            int down=solve(matrix, i+1, j, row, col, maxi);
    
            //check if the square is formed or not
            if(matrix[i][j] == '1'){
                int ans = 1 + min(right, min(diagonal, down));
                maxi = max(maxi, ans);
                return ans;
            }
            else{
                //current pos is not the 1
                return 0;
            }
        }
        int maximalSquare(vector<vector<char>>& matrix) {
            int i=0;
            int j=0;
            int row=matrix.size();
            int col=matrix[0].size();
            int maxi=0;
    
            int ans = solve(matrix, i, j, row, col, maxi);
            return maxi*maxi;
        }
    };
