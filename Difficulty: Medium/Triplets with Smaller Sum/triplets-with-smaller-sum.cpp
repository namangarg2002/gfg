class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        int count = 0;
        sort(arr.begin(),arr.end());
        for(int i=0; i<arr.size()-2; i++){
            int left = i+1;
            int right = arr.size()-1;
            while(left < right){
                int currSum = arr[i] + arr[left] + arr[right];
                if(currSum < sum){
                    count = count + (right - left);
                    left++;
                }else{
                    right--;
                }
            }
        }
        return count;
    }
};