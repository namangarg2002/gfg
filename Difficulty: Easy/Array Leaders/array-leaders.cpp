class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        
        if(n == 1) return arr;
        
        ans.push_back(arr[n-1]);
        
        int element = arr[n-1];
        
        for(int i=n-2; i>=0; i--){
            if(arr[i] >= element){
                ans.push_back(arr[i]);
                element = arr[i];
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};