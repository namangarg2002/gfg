// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
    
        int row = 0;
        int col = m - 1;
        while(row < n && col >= 0){
            if(mat[row][col] == x){
                return true;
            }
            else if(mat[row][col] > x){
                col--;
            }else{
                row++;
            }
        }
        return false;
            
    }
};