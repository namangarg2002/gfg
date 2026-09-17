class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        int n = arr.size();
        for(int i=1; i<n; i++){
            int key = arr[i];
            int j = i-1;
            
            while(i>= 0 && key < arr[j]){
                swap(arr[j], arr[j+1]);
                j--;
            }
        }
        
    }
};