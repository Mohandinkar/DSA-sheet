//37 --> Sudoku Solver

class Solution {
    public:
        bool isSafe(char digit,int row, int col,vector<vector<char>>& board){
            int n = board.size();
    
            for(int k=0;k<n;k++){
                //check for the row
                if(board[row][k] == digit){
                    return false;
                }
    
                //check for the column
                if(board[k][col]== digit){
                    return false;
                }
    
                //check for sub box 3*3
    
                if(board[3*(row/3)+(k/3)][3*(col/3)+(k%3)] == digit){
                    return false;
                }
            }
            return true;
        }
    
        bool solve(vector<vector<char>>& board){
    
            for(int i=0;i<board.size();i++){
    
                for(int j=0;j<board.size();j++){
    
                    if(board[i][j] == '.'){
    
                        for(char digit='1';digit<='9';digit++){
    
                            if(isSafe(digit, i, j, board) == true){
    
                                board[i][j] = digit;
    
                                //recursion
                                bool isSolved = solve(board);
    
                                if(isSolved){
                                    return true;
                                }
                                else{
                                    //backtracking -> when put the wrong digit
                                    board[i][j] = '.';
                                }
                            }
                        }
                        //when no digits palced form 1->9
                        return false;
                    }
                }
            }
            //board completely filled
            return true;
    
        }
        void solveSudoku(vector<vector<char>>& board) {
           solve(board); 
        }
    };

