//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int firstOccurence(vector<int>& arr, int n, int target){
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        int ans = -1;
        while(s<=e){
            if(arr[mid] == target){
                ans = mid;
                e = mid - 1;
            }else if(arr[mid] < target){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
    int lastOccurence(vector<int>& arr, int n, int target){
        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
        int ans = -1;
        while(s<=e){
            if(arr[mid] == target){
                ans = mid;
                s = mid + 1;
            }else if(arr[mid] < target){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        int firstOccurenceIndex = firstOccurence(arr, n, target);
        int lastOccurenceIndex = lastOccurence(arr, n, target);
        
        int totalOccurence = lastOccurenceIndex - firstOccurenceIndex + 1;
        
        return (firstOccurenceIndex == -1 && lastOccurenceIndex == -1) ? 0 : totalOccurence;
    }
};



//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends