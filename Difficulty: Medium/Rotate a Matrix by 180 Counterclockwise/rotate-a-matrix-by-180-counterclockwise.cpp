class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        
        reverse(mat.begin(), mat.end());
        
        for(int i=0; i<n; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
        
        return;
        
    }
};