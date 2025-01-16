//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int, int>map;
        int ans = 0;
        int csum = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == 0){
                arr[i] = -1;
            }
            csum += arr[i];
            if(csum == 0){
                ans = max(ans, i+1);
            }
            else if(map.find(csum) == map.end()){
                // pahle se nhi tha toh push karedenge
                map[csum] = i; 
            }else{
                // pahlse se tha 
                ans = max(ans, i-map[csum]);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends