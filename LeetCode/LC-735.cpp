//735 --> Asteroid Collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;

        for(auto ast:asteroids){
            bool destroy = false;

            if(ast > 0){
                st.push(ast);
            }
            else{
                //-ve 
                if(st.empty() || st.top() < 0){
                    st.push(ast);
                }
                else{
                    //top +ve and ast -ve
                    while(!st.empty() && st.top()>0){

                        if(abs(ast) == st.top()){
                            destroy = true;
                            st.pop();

                            break;
                        }
                        else if(st.top() < abs(ast)){
                            st.pop();
        
                        }
                        else{
                            destroy = true;
                            break;
                        }
                    }

                    if(!destroy){
                        st.push(ast);
                    }
                }
            }
        }

        vector<int>ans(st.size());

        for(int i=st.size()-1;i>=0;i--){
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};


// Time Complexity: O(n)
// Space Complexity: O(n) for the stack