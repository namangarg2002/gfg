class Solution {
  public:
    void sort012(vector<int>& arr) {
        int n = arr.size();
        int s = 0;
        int e = n-1;
        int index = 0;
        while(index <= e){
            if(arr[index] == 1){
                index++;
            }else if(arr[index] == 2){
                swap(arr[index], arr[e]);
                e--;
            }else{
                swap(arr[index], arr[s]);
                s++;
                index++;
            }
        }
        
    }
};