class Solution {
  public:
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
        set<int> st;
        vector<int> ans;
        int i = 0;
        int j = 0;
        while(i < arr1.size() && j < arr2.size()){
            if(arr1[i] == arr2[j]){
                st.insert(arr1[i]);
                i++;
                j++;
            }else if(arr1[i] > arr2[j]){
                j++;
            }else{
                i++;
            }
        }
        
        for(auto it=st.begin(); it != st.end() ; it++){
            ans.push_back(*it);
        }
        
        return ans;
        
    }
};