//643 --> Maximum Average Subarray I
//Also called as Sliding Window 

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0, j = k-1;

        int sum = 0;
        for(int x=0;x<=j;x++){
            sum+=nums[x];
        }

        int maxSum = sum;
        j++;
        while(j<nums.size()){
            sum = sum - nums[i++];
            sum = sum + nums[j++];

            maxSum = max(maxSum, sum);
        }
        double avg = (double)maxSum/k;

        return avg;
    }
};