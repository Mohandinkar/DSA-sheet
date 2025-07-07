//134 ---> Gas Station

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int balance = 0;
        int deficit = 0;
        int start = 0;

        for(int i=0;i<gas.size();i++){
            balance = balance + gas[i] - cost[i];

            if(balance < 0){
                deficit += abs(balance);
                start = i+1;

                balance = 0;
            }
        }

        if(balance - deficit >= 0){
            return start;
        }
        else{
            return -1;
        }
    }
};

//-------------------OR-----------------

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int balance = 0;
        int deficit = 0;
        int start = 0;

        for(int i=0;i<gas.size();i++){

            if(balance + gas[i] < cost[i]){
                //deficit
                deficit += abs(balance + gas[i] - cost[i]);

                start = i+1;
                balance = 0;
            }
            else{
                balance += gas[i] - cost[i];
            }
        }

        if(balance - deficit >= 0){
            return start;
        }
        else
            return -1;
    }
};