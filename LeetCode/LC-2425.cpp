//2425 --> Bitwise XOR of All Pairings

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();

    int ans = 0;

    if(n%2 == 1 && m%2 == 1){
        for(int i=0;i<n;i++){
            ans = ans ^ nums1[i];
        }
         for(int i=0;i<m;i++){
            ans = ans ^ nums2[i];
        }

    }
    else if(n%2 == 1 && m%2 == 0){
        for(int i = 0;i<m;i++){
            ans = ans^nums2[i];
        }
    }
    else if(n%2 == 0 && m%2 == 1){
        for(int i = 0;i<n;i++){
            ans = ans^nums1[i];
        }
    }
    return ans;

    }
};