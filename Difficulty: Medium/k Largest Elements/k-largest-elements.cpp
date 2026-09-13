class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        vector<int> ans;
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<k; i++){
            int element = arr[i];
            pq.push(element);
        }
        
        for(int i=k; i<n; i++){
            int element = arr[i];
            if(element > pq.top()){
                pq.pop();
                pq.push(element);
            }
        }
        
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            ans.push_back(top);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};