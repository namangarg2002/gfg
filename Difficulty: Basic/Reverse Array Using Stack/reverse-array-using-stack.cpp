class Solution {
  public:
    void reverseArray(vector<int>& arr) {
        stack<int> st;
        for(int x: arr){
            st.push(x);
        }
        
        int index = 0;
        while(!st.empty() && index < arr.size()){
            int top = st.top();
            st.pop();
            arr[index++] = top;
        }
    }
};