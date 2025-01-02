//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int>map;
        int ans = 0; //max length of subaaray with 0 sum
        int csum = 0;
        for(int i=0; i<n; i++){
            csum += arr[i];
            if(csum == 0){
                ans = max(ans, i+1);
            }
            else if(map.find(csum) == map.end()){
                // pahle se csum nhi tha
                map[csum] = i;
            }else{
                // pahle se csum tha 
                ans = max(ans, i-map[csum]);
            }
        }
        return ans;
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
        cout << obj.maxLen(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends