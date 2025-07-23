//2327. Number of People Aware of a Secret


class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int M = 1e9 + 7;

        int ans = 1; //knows secret
        int curr = 0; //active spreader of secret

        queue<pair<int, int>>forgetQ, delayQ;

        delayQ.push({1, 1});
        forgetQ.push({1, 1});

        for(int i=1;i<=n;i++){

            //step1=> remove the active spreader after forget
            if(!forgetQ.empty() && forgetQ.front().first + forget <= i){
                auto front = forgetQ.front();
                forgetQ.pop();
                auto no = front.second;
                ans = (ans - no + M) % M;
                curr = (curr - no+M)%M;
            }

            //step2 => new active spreader after some delay
            if(!delayQ.empty() && delayQ.front().first + delay <= i){
                auto front = delayQ.front();
                delayQ.pop();
                
                curr = (curr + front.second)%M;
            }

            //step3 => spread the secret
            if(curr > 0){
                ans = (ans+curr)%M;
                delayQ.push({i, curr});
                forgetQ.push({i, curr});
            }
        }
    
        return ans;
    }
};