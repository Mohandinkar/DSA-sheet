//1823 --> Find the Winner of the Circular Game

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int>q;

        for(int i=1;i<=n;i++){
            q.push(i);
        }

        while(!q.empty() && q.size() != 1){

            int i = 1;
            while(i < k){
                int player = q.front();
                q.pop();
                q.push(player);
                i++;
            }

            //i value equals to k means remove friend from circle
            q.pop();
        }

        return q.front();

    }
};