//52 --> N-Queens II
//count the number of to arrange the Queen so no two Queens attack each other
//The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that 
//no two queens attack each other.
//Given an integer n, return the number of distinct solutions to the n-queens puzzle

class Solution {
    public:
    
        unordered_map<int, bool>rowCheck;
        unordered_map<int, bool>lowerDiagonalCheck;
        unordered_map<int, bool>upperDiagonalCheck;
    
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
    
        void solve(int n, vector<vector<char>>&board, vector<vector<string>>&ans, int col, int&count){
            //base case
            if(col >= n){
                count++;
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
                    solve(n, board,ans, col+1, count);
    
                    //backtracking
                    board[row][col] = '.';
                    rowCheck[row] = false;
                    upperDiagonalCheck[row-col]= false;
                    lowerDiagonalCheck[row+col] = false;
    
                }
            }
        }
    
    
        int totalNQueens(int n) {
            vector<vector<string>>ans;
    
            vector<vector<char>>board(n, vector<char>(n,'.'));
    
            int col = 0;
            int count = 0;
            solve(n, board, ans, col,count);
    
            return count;
    
        }
    };