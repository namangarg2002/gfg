class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> ans;
        unordered_map<int, int> mp; // number->count
        for(int x: arr){
            mp[x]++;
        }
        
        for(auto x: mp){
            if(x.second >= 2){
                ans.push_back(x.first);
            }
        }
        
        return ans;
        
    }
};