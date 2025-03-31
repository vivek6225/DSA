class Solution {
  public:
  
  // T.C= 0(2^n)
  //  S.C = n*1
      int fib(int n) {
      if(n == 0 || n == 1) {
          return n;                       
          }
          return fib(n-1) + fib(n-2);
          
      }
  };