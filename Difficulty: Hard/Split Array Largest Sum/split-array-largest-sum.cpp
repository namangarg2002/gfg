class Solution {
  public:
    int countpainter(vector<int> &arr, int paints){
        int painter = 1;
        int paintarr = 0;
        for(int i=0; i<arr.size(); i++){
            if(paintarr + arr[i] <= paints){
                paintarr += arr[i];
            }else{
                painter++;
                paintarr = arr[i];
            }
        }
        return painter;
    }
    int splitArray(vector<int>& arr, int k) {
        
        int s = *max_element(arr.begin(), arr.end());
        int e = accumulate(arr.begin(), arr.end(), 0);
    
        while(s<=e){
            int mid = s + (e-s)/2;
            int cntPainter = countpainter(arr, mid);
            if(cntPainter > k){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }
        return s;
            
    }
};