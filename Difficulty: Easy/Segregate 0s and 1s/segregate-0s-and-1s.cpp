class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int left = 0;
        int right = arr.size()-1;
        while(left < right){
            // skip left index where element is 0
            while(left < right && arr[left] == 0){
                left++;
            }
            
            // skip right index where element is 1
            while(left < right && arr[right] == 1){
                right--;
            }
            
            if(left < right){
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
            
            
        }
        
    }
};