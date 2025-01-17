//268 --> Missing Number
//Given an array nums containing n distinct numbers in the range [0, n],
// return the only number in the range that is missing from the array

class Solution {
public:
 
    int missingNumber(vector<int>& arr) {
       
       int ans = 0;
       for(int i=0;i<arr.size();i++){
         ans = ans ^ arr[i];
       }
        int n = arr.size();
       for(int i=0;i<=n;i++){
        ans ^= i;
       }
       return ans;
           
    }
};
