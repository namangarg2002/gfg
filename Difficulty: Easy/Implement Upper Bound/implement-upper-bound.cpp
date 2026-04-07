class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int ub = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
        
        return ub;
        
    }
};
