class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        unordered_map<int, int> mp; // number -> count
        vector<int> ans;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        
        for(auto it: mp){
            if(it.second == 2){
                ans.push_back(it.first);
            }
        }
        
        return ans;
        
    }
};