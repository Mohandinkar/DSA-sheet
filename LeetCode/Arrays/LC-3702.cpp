//3702 --> Longest Subsequence With Non-Zero Bitwise XOR

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total = 0;
        int countZero = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            total ^= nums[i];
            if(nums[i] == 0)
                countZero++;
        }

        if(countZero == n)
            return 0;
        if(total != 0){
            return n;
        }
    
            return n-1;

    }
};