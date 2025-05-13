//1655. Distribute Repeating Integers

class Solution {
public:
    bool solve(vector<int>&counts, vector<int>&quantity, int ithCust){
        
        //base case
        if(ithCust == quantity.size()){
            return true;
        }

        for(int i=0;i<counts.size();i++){

            if(counts[i] >= quantity[ithCust]){
                counts[i] -= quantity[ithCust];
                
                if(solve(counts, quantity, ithCust + 1)){
                    return true;
                }

                //backtrack
                counts[i] += quantity[ithCust];
            }
        }

        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int>countMap;
        for(auto num:nums)
            countMap[num]++;
        
        vector<int>counts;
        for(auto it:countMap){
            counts.push_back(it.second);
        }

        //to optimize time complexity sort 
        //quantity in decreasing order
        sort(quantity.rbegin(), quantity.rend());
        return solve(counts, quantity, 0);
    }
};  