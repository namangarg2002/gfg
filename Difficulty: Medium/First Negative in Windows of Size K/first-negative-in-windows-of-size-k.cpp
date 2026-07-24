class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        vector<int> ans;
        queue<int> q;
        int n = arr.size();
        
        for(int i=0; i<k; i++){
            if(arr[i] < 0){
                q.push(i);
            }
        }
        
        if(!q.empty()){
            ans.push_back(arr[q.front()]);
        }else{
            ans.push_back(0);
        }
        
        for(int i=k; i<n; i++){
            while(!q.empty() && q.front() <= i-k){
                q.pop();
            }
            
            if(arr[i] < 0){
                q.push(i);
            }
            
            if(!q.empty()){
                ans.push_back(arr[q.front()]);
            }else{
                ans.push_back(0);
            }
                
        }
        
        return ans;
        
    }
};