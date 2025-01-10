//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int s = 0;
        int e = arr.size() - 1;
        int count = 0;
    
        while(s<e){
            int sum = arr[s] + arr[e];
            if(sum > target) e--;
            else if(sum < target) s++;
            else{
                // sum == target: check redunden tor not
                int elementS = arr[s];
                int elementE = arr[e];
                
                int countS = 0;
                int countE = 0;
                while(s<=e && arr[s] == elementS){
                    countS++;
                    s++;
                }
                while(s<=e && arr[e] == elementE){
                    countE++;
                    e--;
                }
                if(elementS == elementE){
                count+= countS*(countS-1)/2;
                }
                else{
                    count+=countS*countE;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends