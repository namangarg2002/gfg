class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int n = arr.size();
        int ans = -1; 
        int s = 0;
        int e = n-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(arr[mid] >= x){
                ans = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        
        return ans;
        
    }
};