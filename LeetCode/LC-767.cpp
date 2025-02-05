//767 --> Reorganize String

class Solution {
public:
    string reorganizeString(string s) {
        int hash[26] = {0};

        //store the count of each character
        for(int i=0;i<s.size();i++){

            hash[s[i]-'a']++;
        }

        //find the max frequency count 
        char max_freq_char;
        int max_freq = INT_MIN;
        for(int i=0;i<26;i++){

            if(hash[i] > max_freq){
                max_freq = hash[i];
                max_freq_char = i + 'a';
                
            }
        }

        int index = 0;
        while(max_freq > 0 && index < s.size()){
            s[index] = max_freq_char;
            index += 2;
            max_freq--;
        }

        if(max_freq != 0 ){
            return "";
        }

        hash[max_freq_char - 'a'] = 0;

        //place the rest of the char
        for(int i=0;i<26;i++){

            while(hash[i]>0){
                index = index>= s.size() ? 1 : index;
                s[index] = i + 'a';
                hash[i]--;
                index += 2;
            }
        }
        return s;
    }
};