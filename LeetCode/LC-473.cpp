//473 --> Matchsticks to Square

class Solution {
    public:
    
        bool solve(vector<int>& matchsticks, vector<int>& sides, int i){
            //base case
            if(i == matchsticks.size()) {
                return sides[0] == 0 && sides[1] == 0 && sides[2] == 0 && 
                sides[3] == 0;
                //when all are zeros means we got the 4 sub parts of squr
            }
    
            bool ans = false;
            for(int j = 0;j<sides.size();j++){
    
                if(matchsticks[i] <= sides[j]){
                    //include the matchstick
                    sides[j] -= matchsticks[i];
                    ans = ans || solve(matchsticks, sides, i+1);
                    if(ans) return true;
                    //exclude or backtrack
                    sides[j] += matchsticks[i];
    
                }
            }
            return ans;
        }
        bool makesquare(vector<int>& matchsticks) {
            
            if(matchsticks.size() < 4)
            return false;
    
            auto sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    
            //it must divisible by 4 to make the 4 equal parts
            if(sum % 4 != 0) return false;
    
            int sideSum = sum/4;
            vector<int>sides(4, sideSum);
    
            //sort in desc order to avoid the TLE or extra RE calls
            sort(matchsticks.rbegin(), matchsticks.rend());
    
            return solve(matchsticks, sides, 0);
        }
    };