//Rat in a Maze Problem - I

class Solution {
    public:
    
     bool isSafe(int newx, int newy,vector<vector<int>> &mat, vector<vector<bool>> &visited, int n){
         if(newx <0 || newy <0 || newx >=n || newy >=n){
             return false;
         }
         if(visited[newx][newy] == true){
             return false;
         }
         if(mat[newx][newy] == 0){
             return false;
         }
         
         return true;
     }
    
      void solve(vector<vector<int>> &mat, vector<vector<bool>> &visited, int n,  vector<string>&ans,int currx, int curry,int destx,int desty,string output){
          //base case
          if(currx == destx && curry == desty){
              ans.push_back(output);
              return;
          }
          
          //solve 1 case and remanining cases wiil be solved by the RE
          
          //UP
          //i = i-1, j=j
          int newx = currx-1;
          int newy = curry;
          if(isSafe(newx, newy,mat,visited,n)){
              visited[newx][newy] = true;
              solve(mat, visited, n, ans, newx, newy, destx, desty, output+"U");
              
              //Backtracking 
              visited[newx][newy] = false;
          }
          
          //LEFT
          //i = i, j=j-1
          newx = currx;
          newy = curry-1;
          if(isSafe(newx, newy,mat,visited,n)){
              visited[newx][newy] = true;
              solve(mat, visited, n, ans, newx, newy, destx, desty, output+"L");
              
              //Backtracking 
              visited[newx][newy] = false;
          }
          
          //DOWN
          //i = i+1, j=j
          newx = currx+1;
          newy = curry;
          if(isSafe(newx, newy,mat,visited,n)){
              visited[newx][newy] = true;
              solve(mat, visited, n, ans, newx, newy, destx, desty, output+"D");
              
              //Backtracking for finding all paths
              visited[newx][newy] = false;
          }
          
          //RIGHT
          //i = i, j=j+1
          newx = currx;
          newy = curry+1;
          if(isSafe(newx, newy,mat,visited,n)){
              visited[newx][newy] = true;
              solve(mat, visited, n, ans, newx, newy, destx, desty, output+"R");
              
              //Backtracking 
              visited[newx][newy] = false;
          }
      }
      
      
      vector<string> findPath(vector<vector<int>> &mat) {
          int n = mat.size();
          
          vector<string>ans;
          //visited vector
          //create 2d vector properly
          vector<vector<bool>>visited(n, vector<bool>(n,0));
          string output = "";
          int currx = 0, curry = 0;
          int destx = n-1, desty = n-1;
          
          visited[0][0] = true;
          
          //rat initially on the blocked cell
          if(mat[0][0] == 0){
              return ans;
          }
          
          solve(mat, visited, n, ans, currx, curry, destx, desty, output);
          
          return ans;
          
          
      }
  };