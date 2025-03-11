class Solution {
  public:
      string reverseWords(string s) {
        
        // T.C = 0(n);
        //S.C = 0(1);
        
          int n = s.size();
          string ans = "";
          reverse(s.begin(),s.end());
          for(int  i = 0; i<n; i++){
              string word = "";
              while(i < n && s[i] != ' ' ){
                   word += s[i];
                   i++;
              }
              reverse(word.begin(),word.end());
              if(word.length() > 0){
                  ans += " " + word;
              }
          }
          return ans.substr(1);
            
          
      }
  
  };