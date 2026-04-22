// User function template for C++
class Solution {
  public:
    int lowerBound(vector<int>& arr, int n, int target){
        int s = 0;
        int e = n - 1;
        int ans = -1;
        while(s<=e){
            int mid = (s + e) >> 1;
            if(arr[mid] >= target){
                ans = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return ans;
    
    }
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        int cnt_max = -1;
        int index = -1;
        for(int i=0; i<n; i++){
            int idx = lowerBound(arr[i], m, 1);
            int cnt_ones;
    
            if(idx == -1){
                cnt_ones = -1;
            }else{
                cnt_ones = m - idx;
                if(cnt_ones > cnt_max){
                    cnt_max = cnt_ones;
                    index = i;
                }
            }
        }
        return index;
            
    }
};