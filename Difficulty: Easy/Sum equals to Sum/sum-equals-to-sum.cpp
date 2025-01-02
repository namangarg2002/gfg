//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findPairs(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, bool>map;
        bool ans = false;
        // pairs
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int sum = arr[i] + arr[j];
                if(map.find(sum)==map.end()){
                    // pahle se nahi tha
                    map[sum] = true;
                }else{
                    // pahlse se tha
                    return true;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        bool res = obj.findPairs(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends