//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> result;
        unordered_map<int, int> freq_map;
        
        // Process the first window of size k
        for (int i = 0; i < k; i++) {
            freq_map[arr[i]]++;
        }
        
        // Store the count of distinct elements in the first window
        result.push_back(freq_map.size());
        
        // Slide the window over the rest of the array
        for (int i = k; i < n; i++) {
            // Remove the element going out of the window
            freq_map[arr[i - k]]--;
            if (freq_map[arr[i - k]] == 0) {
                freq_map.erase(arr[i - k]);
            }
            
            // Add the new element coming into the window
            freq_map[arr[i]]++;
            
            // Store the count of distinct elements for the current window
            result.push_back(freq_map.size());
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends