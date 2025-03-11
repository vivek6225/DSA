class Solution {
  public:
  
   bool isFreqsame(int freq1[],int freq2[]){
      for(int i = 0; i<26;i++){
          if(freq1[i] != freq2[i]){
              return false;
          }
      }
      return true;
   }
      bool checkInclusion(string s1, string s2) {  
      int freq[26] = {0};
          for(int i = 0; i<s1.length(); i++){
             // int index = s1[i] - "a" //
              freq[s1[i] - 'a']++;
          }
          int windsize = s1.length();
          for(int i = 0; i<s2.length(); i++){
         int  windindx = 0, indx = i;
         int windFreq[26] = {0};
  
         while(windindx < windsize && indx < s2.length()){
          windFreq[s2[indx] - 'a']++;
          windindx++,indx++;
         }
         if(isFreqsame(freq,windFreq)){  // found
  
         return true;
         }
  
          }
          return false;
  
          
      }
  };