class Solution {
  public:
    void rearrange(vector<int> &arr) {
        vector<int> posNum;
        vector<int> negNum;
        
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            if(arr[i] >= 0){
                posNum.push_back(arr[i]);
            }else{
                negNum.push_back(arr[i]);
            }
        }
        
        int posIdx=0;
        int negIdx=0;
        int index = 0;
        while(posIdx < posNum.size() && negIdx < negNum.size()){
            if(index%2 == 0){
                arr[index] = posNum[posIdx];
                posIdx++;
            }else{
                arr[index] = negNum[negIdx];
                negIdx++;
            }
            
            index++;
        }
        
        // remaining positives
        while(posIdx < posNum.size()){
            arr[index] = posNum[posIdx];
            posIdx++;
            index++;
        }
        
        while(negIdx < negNum.size()){
            arr[index] = negNum[negIdx];
            negIdx++;
            index++;
        }
        
    }
};