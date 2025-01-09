class Solution {
public:
    string decodeMessage(string key, string message) {
        //step1 - to create mappping 
        unordered_map<char,char>mapping;
        char space = ' ';
        mapping[space] = space;
        char start = 'a';
        int index = 0;

        while(start <= 'z' && index<key.length()){
            char keyCurrChar = key[index];

            if(mapping.find(keyCurrChar) != mapping.end()){
                //if already present
                //move to next char of key
                index++;
            }
            else{
                //not present
                //map abcd... to key char
                mapping[keyCurrChar] = start;
                start++;
                index++;
            }
        }


        //step2 -use it for decoding the message
        string ans = "";
        for(int i=0;i<message.length();i++){
            char msgChar = message[i];
            char mappedChar = mapping[msgChar];
            ans.push_back(mappedChar);
        }
        return ans;
    }
};