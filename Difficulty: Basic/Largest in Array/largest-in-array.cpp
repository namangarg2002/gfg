class Solution {
  public:
    int largest(vector<int> &arr) {
        int maxi = INT_MIN;
        for(int i=0; i<arr.size(); i++){
            maxi = max(arr[i], maxi);
        }
        
        return maxi;
        
    }
};
