// 791 --> Custom Sort String

string orderCopy;
class Solution {
public:
    static bool cusCmp(char a, char b){
        //if true -> a will be placed before b
        //if false -> b will be placed before a
        //based on the order string string s will be sorted
        return (orderCopy.find(a) < orderCopy.find(b));

    }

    string customSortString(string order, string s) {
        orderCopy = order;

        // sort the s as per the custom comparator
        sort(s.begin(),s.end(),cusCmp);

        return s;
    }
};