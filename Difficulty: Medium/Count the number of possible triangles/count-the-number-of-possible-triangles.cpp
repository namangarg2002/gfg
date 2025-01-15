//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int ans = 0;
        int n = arr.size();
        
        for(int k=n-1; k>=2; k--){
            int i = 0;
            int j = k - 1;
            while(i<j){
                int twoSideSum = arr[i] + arr[j];
                if(twoSideSum > arr[k]){
                    ans+=j-i;
                    j--;
                }else{
                    i++;
                }
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends