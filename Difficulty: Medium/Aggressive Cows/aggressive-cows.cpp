class Solution {
  public:
    bool isPossible(vector<int> &stalls, int k, int dist){
        int countCow = 1;
        int lastCow = stalls[0];
        
        for(int i=1; i<stalls.size(); i++){
            if(stalls[i] - lastCow >= dist){
                countCow++;
                lastCow = stalls[i];
            }
            
            if(countCow >= k){
                return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        
        int s = 1;
        int e = stalls.back() - stalls.front();;
        
        int ans = 0;
        while(s<=e){
            int mid = s + (e-s)/2;
            
            if(isPossible(stalls, k, mid)){
                ans = mid;
                s = mid + 1;
            }else{
                e = mid - 1;
            }
            
        }
        return ans;
    }
};