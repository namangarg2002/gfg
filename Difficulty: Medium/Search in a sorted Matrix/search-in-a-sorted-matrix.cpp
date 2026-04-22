class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
    
        int s = 0;
        int e = (n*m)-1;
    
        while(s<=e){
            long long mid = s + (e-s)/2;
            int row = mid / m;
            int col = mid % m;
            if(mat[row][col] == x){
                return true;
            }else if(mat[row][col] > x){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        return false;
        
    };
};