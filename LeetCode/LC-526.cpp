//526 --> Beautiful Arrangement

class Solution {
    public:
    
        void solve(int n, vector<int>v, int&ans, int currNum){
    
            //base case
            if(currNum == n+1){
                ans++;
                return;
            }
    
            for(int i=1;i<=n;i++){
    
                if(v[i] == 0 && (i%currNum == 0 || currNum%i == 0)){
                    v[i] = currNum;
    
                    solve(n, v, ans, currNum+1);
    
                    //backtrack
                    v[i] = 0;
                }
            }
        }
    
        int countArrangement(int n) {
            vector<int>v(n+1);
            int ans = 0;
    
            solve(n, v, ans, 1);
            
            return ans;
        }
    };