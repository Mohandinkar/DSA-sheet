//51 --> N-Queens

class Solution {
    public:
        unordered_map<int, bool>rowCheck;
        unordered_map<int, bool>lowerDiagonalCheck;
        unordered_map<int, bool>upperDiagonalCheck;
        void storeSolution(vector<vector<string>>&ans, vector<vector<char>>&board, int n){
            vector<string>tempAns;
            for(int i=0;i<n;i++){
                string output = "";
                for(int j=0;j<n;j++){
                    output.push_back(board[i][j]);
                }
                tempAns.push_back(output);
            }
            ans.push_back(tempAns);
        }
    
        bool isSafe(int row, int col, vector<vector<char>>&board){
    
            //check for row
            if(rowCheck[row] == true){
                return false;
            }
    
            //for lowerDigonal
            if(lowerDiagonalCheck[row+col] == true){
                return false;
            } 
    
            //for upperDiagonal
            if(upperDiagonalCheck[row-col] == true){
                return false;
            }
    
            //else
            return true;
        }
    
        void solve(int n, vector<vector<char>>&board, vector<vector<string>>&ans, int col){
            //base case
            if(col >= n){
                //store the board
                storeSolution(ans, board, n);
                return;
            }
    
            //solve 1 case 
            for(int row=0;row<n;row++){
    
                if(isSafe(row,col,board)){
                    board[row][col] = 'Q';
                    rowCheck[row] = true;
                    upperDiagonalCheck[row-col] = true;
                    lowerDiagonalCheck[row+col] = true;
    
                    //recursion
                    solve(n, board,ans, col+1);
    
                    //backtracking
                    board[row][col] = '.';
                    rowCheck[row] = false;
                    upperDiagonalCheck[row-col]= false;
                    lowerDiagonalCheck[row+col] = false;
    
                }
            }
        }
    
    
        vector<vector<string>> solveNQueens(int n) {
            vector<vector<string>>ans;
    
            vector<vector<char>>board(n, vector<char>(n,'.'));
    
            int col = 0;
            solve(n, board, ans, col);
            return ans;
        }
    };