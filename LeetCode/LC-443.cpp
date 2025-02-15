//443 --> String Compression


class Solution {
    public:
        int compress(vector<char>& chars) {
            int index = 0, count = 1;
            char prev = chars[0];
    
            for(int i=1;i<chars.size();i++){
                if(chars[i] == prev){
                    count++;
                }
                else{
                    chars[index++] = prev;
    
                    if(count>1){
                        int start =  index;
                        while(count){
                            //convert into the int to char
                            chars[index++] = (count % 10) + '0';
                            count /=10;
    
                        }
                        reverse(chars.begin()+start, chars.begin()+index);
                    }
    
                    prev = chars[i];
                    count = 1;
                }
            }
    
            //handle out of bound condition
            chars[index++] = prev;
            
            if(count>1){
                int start =  index;
                while(count){
                //convert into the int to char
                    chars[index++] = (count % 10) + '0';
                    count /=10;
    
                }
                reverse(chars.begin()+start, chars.begin()+index);
            }
            //index will be the length
            return index;
    
        }
    };