class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> vec;
        queue<int> q;
        
        for(int i=0; i<k; i++){
            if(arr[i] < 0){
                q.push(i);
            }
        }
        
        if(q.empty()){
            vec.push_back(0);
        }else{
            vec.push_back(arr[q.front()]);
        }
        
        for(int i=k; i<n; i++){
            
            if(!q.empty() && q.front() <= i-k){
                q.pop();
            }
            
            if(arr[i] < 0){
                q.push(i);
            }
            
            if(q.empty()){
                vec.push_back(0);
            }else{
                vec.push_back(arr[q.front()]);
            }
                
            
        }
        
        return vec;
        
    }
};