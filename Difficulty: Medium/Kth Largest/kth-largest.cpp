class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<k; i++){
            int element = arr[i];
            pq.push(element);
        }
        
        for(int i=k; i<n; i++){
            int element = arr[i];
            if(element > pq.top()){
                pq.pop();
                pq.push(element);
            }
        }
        
        return pq.top();
        
    }
};