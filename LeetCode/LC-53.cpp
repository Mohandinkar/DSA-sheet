//53 --> Maximum Subarray

class Solution {
    public:
    
        int solveMaxSubArray(vector<int>&nums, int start, int end){
    
            //base case
            if(start == end) return nums[start];
    
            int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
            
            int mid = start +(end-start)/2;
    
            int maxLeftSum = solveMaxSubArray(nums, start, mid);
            int maxRightSum = solveMaxSubArray(nums, mid+1, end);
    
            //max cross border sum
            int leftBorderSum = 0, rightBorderSum = 0;
             
            for(int i=mid;i>=start;i--){
                leftBorderSum +=nums[i];
    
                if(leftBorderSum > maxLeftBorderSum){
                    maxLeftBorderSum = leftBorderSum;
                }
            }
            
            for(int i=mid+1;i<=end;i++){
                rightBorderSum +=nums[i];
    
                if(rightBorderSum > maxRightBorderSum){
                    maxRightBorderSum = rightBorderSum;
                }
            }
    
            int maxCrossSum = maxRightBorderSum + maxLeftBorderSum;
    
            return max(maxCrossSum, max(maxLeftSum, maxRightSum));
        }
        int maxSubArray(vector<int>& nums) {
          return solveMaxSubArray(nums, 0, nums.size()-1);
        }
    };