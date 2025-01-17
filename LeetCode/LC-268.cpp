//268 --> Missing Number

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
