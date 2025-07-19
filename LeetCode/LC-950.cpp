//950 --> Reveal Cards In Increasing Order

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        sort(deck.begin(), deck.end());

        queue<int>q;
        vector<int>ans(deck.size());

        //insert indices to queue
        for(int i=0;i<ans.size();i++)
            q.push(i);
        
        //reverse simulation
        for(int i=0;i<deck.size();i++){

            //reveal card
            ans[q.front()] = deck[i];
            q.pop();

            //push to bottom
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
            
        }

        return ans;
    }
};