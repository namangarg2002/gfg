//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int n = arr.size();
        if (n < 3) return -1;
    
        int totalSum = 0, leftSum = 0;
    
        for (int num : arr) {
            totalSum += num;
        }
    
        for (int i = 0; i < n; ++i) {
            totalSum -= arr[i];  // Right sum is total sum minus current element
    
            if (leftSum == totalSum) {
                return i;  // Return 0-based index
            }
    
            leftSum += arr[i];  // Update left sum
        }
    
        return -1;  // No equilibrium point found
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends