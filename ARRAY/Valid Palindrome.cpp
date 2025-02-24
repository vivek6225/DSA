class Solution {
  public:
  
  // tc = 0(n)
    bool isAlphaNum(char ch){
      if((ch >= '0' && ch <= '9') ||
      (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
  
      return true;
      }
      
      return false;
    }
      bool isPalindrome(string s) {
          int n = s.size();
          int start = 0, end = n-1;
          while(start < end){
              if(!isAlphaNum(s[start])){
                  start++;continue;
  
              }
               if(!isAlphaNum(s[end])){
                  end--;continue;
  
              }
              
              if(tolower(s[start])  != tolower(s[end])){
                  return false;
              }
                  start++;
                  end--;
  
          }
          return true;
        
      }   
      
  };