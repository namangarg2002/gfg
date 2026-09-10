class Solution {
  public:
    string isAutomorphic(int n) {
        int temp = n;
        int square = n*n;
        int digitCount = 0;
        while(temp > 0){
            digitCount++;
            temp = temp/10;
        }
        
        int devisor = pow(10, digitCount);
        
        return (square % devisor == n) ? "Automorphic" : "Not Automorphic";
        
    }
};