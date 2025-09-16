
//T.C = 0(N)
//S.C= 0(1)

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        
      //  reverse(arr.begin(),arr.end()); // using stl
      
      int  i = 0, j = arr.size()-1;
          while( i < j){
              swap( arr[i], arr[j]); // // swap elements, not indices
              i++;
              j--;
          }
    }
};