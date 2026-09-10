class Solution {
  public:
  public:
    int factorial(int x){
        if(x == 0 || x == 1) return 1;
        
        return x*factorial(x-1);
    }
    bool isStrong(int n) {
        int sum = 0;
        int temp = n;
        while(n > 0){
            int digit = n % 10;
            sum += factorial(digit);
            n = n / 10;
        }
        
        return sum == temp;
    }
};
