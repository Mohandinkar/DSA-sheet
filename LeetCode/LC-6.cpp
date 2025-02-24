//6 --> Zigzag Conversion

class Solution {
    public:
        string convert(string s, int numRows) {
            if(numRows == 1)
            return s;
    
            vector<string>zigZag(numRows);
            int i = 0;
            int row = 0;
            bool direction = 1 ;//top to bottom
    
            while(true){
                //if top to bottom
                if(direction){
    
                    while(row<numRows && i<s.size()){
                        zigZag[row++].push_back(s[i++]);
                    }
                    row = numRows - 2;
                }
                //bottom to top
                else{
                    while(row >= 0 && i<s.size()){
                        zigZag[row--].push_back(s[i++]);
                    }
                    row = 1;
                }
    
                direction = !direction;
    
                if(i>=s.size()) break;
            }
    
            string ans="";
            for(auto i:zigZag){
                ans = ans+i;
            }
    
            return ans;
        }
    };