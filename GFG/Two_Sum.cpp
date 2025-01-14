// TwoSum - Pair with Given Sum


class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        sort(arr.begin(),arr.end());
        int l = 0;
        int h = arr.size() - 1;
        
        while(l<h){
            int currSum = arr[l] + arr[h];
            if( currSum == target){
                return true;
            }
            else if(currSum > target){
                h--;
                
            }
            else if(currSum < target){
                l++;
            }
            
        }
        return false;
     
    }
};

