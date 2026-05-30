class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {


        stack<int> st;
        int n = arr.size();
        for(int i=n-1; i>=0; i--){
            int curr = arr[i];
            while(!st.empty() && curr >= st.top()){
                st.pop();
            }
            if(st.empty()){
                arr[i] = -1;
            }else{
                arr[i] = st.top();
            }
            st.push(curr);
        }

        return arr;
        
    }
};