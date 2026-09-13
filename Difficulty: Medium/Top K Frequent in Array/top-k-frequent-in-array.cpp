class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        vector<int> ans;
        
        unordered_map<int, int> freq;
        for(int x: arr){
            freq[x]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(auto x: freq){
            pq.push({x.second, x.first});
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            int top = pq.top().second;
            pq.pop();
            ans.push_back(top);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};
