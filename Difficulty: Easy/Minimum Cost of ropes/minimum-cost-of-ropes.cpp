//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public: 
    int minCost(vector<int>& arr) {
        if(arr.size() < 2){
            return 0;
        }
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
        
        int result = 0;
        while(pq.size() > 1){
            int firstMinNo = pq.top();
            pq.pop();
            int secondMinNo = pq.top();
            pq.pop();
            
            int sum = firstMinNo + secondMinNo;
            result += sum;
            
            pq.push(sum);
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
        string input;
        int num;
        vector<int> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends