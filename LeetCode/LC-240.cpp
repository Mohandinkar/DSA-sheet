// 240 --> Search a 2D Matrix II

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



