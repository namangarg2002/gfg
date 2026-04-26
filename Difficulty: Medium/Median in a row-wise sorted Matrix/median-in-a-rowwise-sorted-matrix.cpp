class Solution {
  public:
    int upperBound(vector<int> &arr, int target){
        int s = 0;
        int e = arr.size() - 1;
        int ans = arr.size();
    
        while(s<=e){
            int mid = s + (e-s)/2;
    
            if(arr[mid] > target){
                ans = mid;
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return ans;
    }
    int countSmallerEquals(vector<vector<int>> &mat, int row, int col, int mid){
        int count = 0;
        for(int i=0; i<row; i++){
            count += upperBound(mat[i], mid);
        }
        return count;
    }
    int median(vector<vector<int>> &mat) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        int s = INT_MAX;
        int e = INT_MIN;
        for(int i=0; i<m; i++){
            s = min(s, mat[i][0]);
            e = max(e, mat[i][n-1]);
        }
    
        int req = (n*m)/2;
        while(s<=e){
            int mid = s + (e-s)/2;
            int smallEqual = countSmallerEquals(mat, m, n, mid);
    
            if(smallEqual <= req){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return s;
    }
};
