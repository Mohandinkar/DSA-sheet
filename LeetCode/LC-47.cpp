//47 --> Permutations II

class Solution {
    public:
        void solve(vector<int>&nums, vector<vector<int>>&ans, int start){
            //base case
            if(start == nums.size()){
                ans.push_back(nums);
                return;
            }
    
            unordered_map<int, bool>visited;
            for(int i=start;i<nums.size();i++){
    
                //once i swap with "start" it will not swap again with same item to avoid duplicate 
                if(visited.find(nums[i]) != visited.end()){
                    continue;
                }
    
                visited[nums[i]] = true;
    
                swap(nums[i], nums[start]);
                solve(nums, ans, start+1);
                swap(nums[i], nums[start]);
            }
    
        }
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<vector<int>>ans;
    
            solve(nums, ans, 0);
            return ans;
        }
    };