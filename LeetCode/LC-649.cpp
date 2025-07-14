//649 --> Dota2 Senate

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>radiantQ, direQ;

        int position = 0;

        for(;position<senate.size();position++){
            if(senate[position] == 'R'){
                radiantQ.push(position);
            }
            else{
                direQ.push(position);
            }
        }

        while(!radiantQ.empty() && !direQ.empty()){

            int rFront = radiantQ.front(); radiantQ.pop();
            int dFront = direQ.front(); direQ.pop();

            if(rFront < dFront){
                //R will ban the D
                radiantQ.push(position++);
            }
            else{
                //D will ban the R
                direQ.push(position++);
            }
        }

        if(!radiantQ.empty()) return "Radiant";

        return "Dire";
    }
};