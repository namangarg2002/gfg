class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        vector<vector<int>> result;
        int n = arr.size();
        
        sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        
        int start1 = arr[0][0];
        int end1 = arr[0][1];
        
        for(int i=1; i<n; i++){
            int start2 = arr[i][0];
            int end2 = arr[i][1];
            
            if(end1 >= start2){
                start1 = start1;
                end1 = max(end1, end2);
                continue;
            }
            
            result.push_back({start1, end1});
            start1 = start2;
            end1 = end2;
            
        }
        
        result.push_back({start1, end1});
        
        return result;
        
    }
};