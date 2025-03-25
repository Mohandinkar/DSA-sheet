// 240 --> Search a 2D Matrix II


//TC => O(n*logn)
class Solution {
    public:
    
        bool binarySearch(vector<int>&row, int target){
            int s = 0;
            int e = row.size() - 1;
    
            while(s <= e){
                int mid = s + (e-s)/2;
    
                if(row[mid] == target) return true;
    
                if(row[mid] < target){
                    s = mid+1;
                }
                else{
                    e = mid-1;
                }
            }
            return false;
        }
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            
            for(auto &row:matrix){
    
                if(binarySearch(row, target)){
                    return true;
                }
            }
    
            return false;
        }
    };

//-----------------OR----------------

//TC => O(n+m)

class Solution {
    public:
    
        bool searchInMatrix(vector<vector<int>>& matrix, int target){
            int rowSize = matrix.size();
            int colSize = matrix[0].size();
            int row = 0, col = colSize - 1;
            while(row < rowSize && col >= 0){
    
                if(matrix[row][col] == target){
                    return true;
                }
                if(target < matrix[row][col]){
                    col--;
                }
                else{
                    row++;
                }
            }
            return false;
        }
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            return searchInMatrix(matrix, target);
        }
    };


