class Solution {
  public:
    int largest(vector<int> &arr) {
        if(arr.size() == 1) return arr[0];
        
        int maxi = INT_MIN;
        for(int x: arr){
            maxi = max(maxi, x);
        }
        
        return maxi;
        
    }
};
