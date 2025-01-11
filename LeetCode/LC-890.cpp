// 890 --> Find and Replace Pattern

class Solution {
public:
    void normalize(string &str){
        char start = 'a';
        unordered_map<char,char> mapping;

        for(int i=0;i<str.size();i++){
            char currChar = str[i];

            if(mapping.find(currChar) == mapping.end()){
                mapping[currChar] = start;
                start++;
            }
        }
        //update the string with mapped char
        for(int i=0;i<str.size();i++){
            char mappedChar = mapping[str[i]];
            //stored mappedMap char in str 
            str[i] = mappedChar;

        }

    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;

        normalize(pattern);
        for(int i=0;i<words.size();i++){
            //normalize the each word
            string currWord = words[i];
           
            normalize(currWord);
            
            if(currWord.compare(pattern) == 0){
                //if both same then return the 0
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};