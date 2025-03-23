//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        vector<int>ans;
        int rows = R;
        int cols = C;
        
        int startCol = 0;
        int startRow = 0;
        int endCol = cols - 1;
        int endRow = rows - 1;
        
        int totalElement = rows * cols;
        int count = 0;
        
        while(count < totalElement){
            for(int i=startCol; i<=endCol && count<totalElement; i++){
                ans.push_back(a[startRow][i]);
                count++;
            }
            startRow++;
            for(int i=startRow; i<=endRow && count<totalElement; i++){
                ans.push_back(a[i][endCol]);
                count++;
            }
            endCol--;
            for(int i=endCol; i>=startCol && count<totalElement; i--){
                ans.push_back(a[endRow][i]);
                count++;
            }
            endRow--;
            for(int i=endRow; i>=startRow && count<totalElement; i--){
                ans.push_back(a[i][startCol]);
                count++;
            }
            startCol++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends