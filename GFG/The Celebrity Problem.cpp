//The Celebrity Problem

class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        stack<int>st;
        
        //step1 : push all persons in stack
        for(int i=0;i<mat.size();i++){
            st.push(i);
        }
        
        //step2 : discard to get might be celebrity person
        while(st.size() != 1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            //if a knows b => a is not celebrity but b might b
            if(mat[a][b]){
                
                st.push(b);
            }
            else{
                //b knows a means  is not celebrity and a might be
                
                st.push(a);
            }
        }
        
        //step 3: check that the single person actually celebrity
        int mightCelebrity = st.top();
        st.pop();
        
        //cel. should not know anyone 
        for(int i=0;i<mat.size();i++){
            if(mat[mightCelebrity][i] != 0 && i != mightCelebrity ){
                return -1;
            }
        }
        
        //everyone should know celebrity
        for(int i=0;i<mat.size();i++){
            //except diagonal if column zero then it is not celebrity
            
            if(mat[i][mightCelebrity] == 0 && i != mightCelebrity){
                return -1;
            }
        }
        
        return mightCelebrity;
        

     
    }
};