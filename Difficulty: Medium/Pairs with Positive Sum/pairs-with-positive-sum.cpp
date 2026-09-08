class Solution {
  public:
    long long validPair(vector<int> &arr) {
        sort(arr.begin() , arr.end());
        long long count = 0;
        int start= 0;
        int end = arr.size() -1;
        while(start < end){
            if(arr[start] + arr[end] > 0){
                count += (end - start);
                end--;
            }else{
                start++;
            }
        }
        
        return count;
        
    }
};