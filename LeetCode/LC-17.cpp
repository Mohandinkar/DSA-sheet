//17 --> Letter Combinations of a Phone Number

class Solution {
    public:
    
        void solve(string&output, vector<string>&ans, unordered_map<char,string>&mapping, string digits, int i){
            //base case
            if(i>=digits.length()){
                if(output.length() > 0){
                    ans.push_back(output);
                }
    
                return;
            }
    
            //solve 1 case
            char digit = digits[i];
            string mappedString = mapping[digit];
    
            for(char ch:mappedString){
                output.push_back(ch);
    
                //RE
                solve(output, ans, mapping, digits, i+1);
    
                //backtracking
                output.pop_back();
            }
        }
        
        vector<string> letterCombinations(string digits) {
            unordered_map<char,string>mapping;
            mapping['2']="abc";
            mapping['3']="def";
            mapping['4']="ghi";
            mapping['5']="jkl";
            mapping['6']="mno";
            mapping['7']="pqrs";
            mapping['8']="tuv";
            mapping['9']="wxyz";
    
            int i=0;
            vector<string>ans;
            string output="";
    
            solve(output, ans, mapping,digits, i);
    
            return ans;
    
        }
    };