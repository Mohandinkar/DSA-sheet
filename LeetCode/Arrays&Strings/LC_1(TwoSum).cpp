//1 --> Two Sum


//TC = O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
              if(nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
              }

            }
        }
        return ans;
        
    }
};


//TC = O(n) approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i;
        }

        for(int i=0;i<nums.size();i++){

            int currEle = nums[i];
            int remainEle = target - currEle;

            if(mp.find(remainEle) != mp.end() && (mp[remainEle] != i) ){
                
                return {i, mp[remainEle]};
            }
        }

        return {};
    }
};