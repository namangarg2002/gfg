class Solution {
  public:
    int SumOfDigitsCubes(int n){
        int sum = 0;
        while(n>0){
            int digit = n % 10;
            sum += digit*digit*digit;
            n = n / 10;
        }
        
        return sum;
    }
    bool armstrongNumber(int n) {
        int sumOfCubes = SumOfDigitsCubes(n);
        
        if(sumOfCubes == n){
            return true;
        }
        
        return false;
        
    }
};