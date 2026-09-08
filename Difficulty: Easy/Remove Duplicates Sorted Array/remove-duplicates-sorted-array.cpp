class Solution {
  public:
    vector<int> removeDuplicates(vector<int> &arr) {
        vector<int> ans;
        
        int j=0;
        for(int i=1; i<arr.size(); i++){
            if(arr[i] != arr[j]){
                ans.push_back(arr[j]);
                j++;
                arr[j] = arr[i];
            }
        }
        ans.push_back(arr[j]);
        
        return ans;
        
    }
};