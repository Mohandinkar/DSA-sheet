//532 --> K-diff Pairs in an Array

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

      sort(nums.begin(),nums.end());
      int i=0, j=1;
      
      //for storing the unique pairs
      set<pair<int,int>>ans;

      while(j < nums.size()){
        int diff = nums[j] - nums[i];

        if(diff == k){
            ans.insert({nums[i], nums[j]});
            i++;
            j++;
        }
        else if(diff > k){
            i++;
        }
        else{
            j++;
        }
        
        if(i == j) j++;

      }  
      return ans.size();
    }
};