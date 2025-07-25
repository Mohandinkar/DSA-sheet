//3487 --> Maximum Unique Subarray Sum After Deletion

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, int>mp;

        int maxNeg = INT_MIN;
        int sum = 0;

        for(auto num : nums){

            if(num <= 0){
                maxNeg = max(maxNeg, num);
            }
            //check if num already present or not
            else if(mp.find(num) == mp.end()){
                sum += num;
                mp[num] = num;
            }
        }

        return sum ? sum : maxNeg;
    }
};

//TC: O(n)
//SC: O(n)

//-------OR-----------
//using set
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>set;

        int maxNeg = INT_MIN;
        int sum = 0;

        for(auto num : nums){

            if(num <= 0){
                maxNeg = max(maxNeg, num);
            }
            //check if num already present or not
            else if(!set.count(num)){
                sum += num;
                set.insert(num);
            }
        }

        return sum ? sum : maxNeg;
    }
};