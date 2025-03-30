//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        int ans = -1;
        while(s<=e){
            int diff = arr[mid]-mid;
            
            if(diff == 1){
                s = mid + 1;
            }else{
                ans = mid;
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        
        return (ans == -1)? n + 1 : ans + 1;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
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
        cout << obj.missingNumber(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends