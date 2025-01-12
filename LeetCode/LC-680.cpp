//680 --> Valid Palindrome II

class Solution {
public:

    bool checkPalindrome(string str,int s,int e){
        while(s<=e){
        if(str[s] == str[e]){
            s++;
            e--;
        }

        else{
            return false;
        }


        }
        return true;

    }

    bool validPalindrome(string s) {
       int n = s.length();
       int i=0;
       int j = n-1;

       while(i<=j){
        //same
        if(s[i] == s[j]){
            i++;
            j--;
        }
        //different
        else{
            //delete the one character form string and then check
            //delete i th char
            bool ansOne = checkPalindrome(s,i+1,j);
            //delete j th char
            bool ansTwo = checkPalindrome(s,i,j-1);

            bool finalAns = ansOne || ansTwo;

            return finalAns;
        }
       } 
       return true;
    }
};