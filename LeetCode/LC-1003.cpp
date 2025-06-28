//1003 --> Check If Word Is Valid After Substitutions

//using recursion => TC => O(n^2)

class Solution {
public:
    bool isValid(string s) {
        //base case
        if(s.size() == 0){
            return true;
        }
        int found = s.find("abc");

        if(found != string::npos){
            //found in string
            string tleft = s.substr(0, found);
            string tright = s.substr(found+3, s.size());

            return isValid(tleft + tright);
        }
        return false;
    }

};