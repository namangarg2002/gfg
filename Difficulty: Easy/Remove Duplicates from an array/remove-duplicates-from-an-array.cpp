class Solution {
  public:
    vector<int> remDuplicate(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int j = 0;
        for(int i=1; i<arr.size(); i++){
            if(arr[i] != arr[j]){
                j++;
                swap(arr[i], arr[j]);
            }
        }
        arr.resize(j+1);
        return arr;
    }
};