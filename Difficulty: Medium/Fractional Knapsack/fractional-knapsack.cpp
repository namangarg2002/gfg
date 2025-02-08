//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<double>ProfitWeightRatio(n);
        for(int i=0; i<n; i++){
            ProfitWeightRatio[i] = double(val[i])/wt[i];
        }
        priority_queue<pair<double, pair<int,int>>>maxi;
        for(int i=0; i<n; i++){
            maxi.push({ProfitWeightRatio[i], {val[i], wt[i]}});
        }
        
        double totalVal = 0;
        
        // max heap redy
        while(capacity != 0 && !maxi.empty()){
            auto top = maxi.top();
            maxi.pop();
            double Ratio = top.first;
            int value = top.second.first;
            int weight = top.second.second;
            
            // full insert hoga capacity 
            if(capacity >= weight){
                totalVal += value;
                capacity -= weight;
            }
            else{
                // fractional insert hoga capacity mai
                totalVal += capacity*Ratio;
                capacity = 0;
                break;
                
            }
            
        }
        return totalVal;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends