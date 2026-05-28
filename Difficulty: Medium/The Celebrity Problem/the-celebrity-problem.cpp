class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            st.push(i);
        }
        
        while(st.size() > 1){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            
            if(mat[a][b] == 1){
                st.push(b);
            }else{
                st.push(a);
            }
        }
        
        int mightBeCelebrity = st.top();
        st.pop();
        
        for(int i=0; i<n; i++){
            if(i == mightBeCelebrity){
                continue;
            }
            
            if(mat[mightBeCelebrity][i] != 0){
                return -1;
            }
        }
        for(int i=0; i<n; i++){
            if(i == mightBeCelebrity){
                continue;
            }
            
            if(mat[i][mightBeCelebrity] == 0){
                return -1;
            }
        }
        
        return mightBeCelebrity;
        
    }
};