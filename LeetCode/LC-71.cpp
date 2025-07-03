//71 --> Simplify Path


class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;

        int i = 0;
        while(i < path.size()){
            int start = i;
            int end = i+1;

            while(end < path.size() && path[end] != '/'){
                ++end;
            }

            string minPath = path.substr(start, end-start);

            i = end;
            if(minPath == "/" || minPath == "/."){
                continue;
            }
            else if(minPath != "/.."){
                st.push(minPath);
            }
            else if(!st.empty()){
                st.pop();
            }
        }

        string ans = st.empty() ? "/" : "";

        while(!st.empty()){
            string top = st.top();

            ans = top + ans;
            st.pop();
        }

        return ans;
    }
};