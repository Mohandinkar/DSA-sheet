//79 --> Word Search

class Solution {
    public:
    
        bool solve(vector<vector<char>>&board, string&word, int row,int col, int i){
    
            //base case
            if(i == word.size())
            return true;
    
            if(row<0 || row >= board.size() || col<0 || col >= board[0].size() || board[row][col] != word[i]){
                return false;
            }
    
            //word[i] is exist
            //make it visited
            char temp = board[row][col];
            board[row][col] = '$';
    
            bool found = solve(board, word, row + 1, col, i+1) || //down
             solve(board, word, row - 1, col, i+1) ||  //up
             solve(board, word, row, col + 1, i+1) || // right
             solve(board, word, row , col - 1, i+1); //left 
    
            //unvisit
            board[row][col] = temp;
             return found;
                         
        }
        bool exist(vector<vector<char>>& board, string word) {
            
            for(int i=0;i<board.size();i++){
                for(int j=0; j<board[0].size(); j++){
    
                    if(solve(board, word, i, j, 0))
                     return true;
                }
            }
    
            return false;
        }
    };