class Solution {
  public:
    int possibeBouquet(vector<int> &arr, int days, int k){
    	int counter = 0;
    	int noOfBouquet = 0;
    	for(int i=0; i<arr.size(); i++){
    		if(arr[i] <= days){
    			counter++;
    		}else{
    			noOfBouquet += (counter/k);
    			counter = 0;
    		}
    	}
    	noOfBouquet += (counter/k);
    	return noOfBouquet;
    }
    int minDaysBloom(vector<int>& arr, int k, int m) {
        
        int s = *min_element(arr.begin(), arr.end());
    	int e = *max_element(arr.begin(), arr.end());
    	int ans = -1;
    
    	int n = arr.size();
    
    	if(k*m > n) return -1;
    
    	while(s<=e){
    		int mid = s + (e-s)/2;
    
    		int noOfBouquet = possibeBouquet(arr, mid, k);
    		if(noOfBouquet >= m){
    			ans = mid;
    			e = mid - 1;
    		}else{
    			s = mid + 1;
    		}
    	}
    	return ans;
    }
};