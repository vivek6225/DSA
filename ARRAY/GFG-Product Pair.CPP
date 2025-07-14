// User function template for C++
// T.C == 0(N)
//S.C = 0(N)

      //NOTES
  //  1.  Sort the array.

// 2.USE TWO POINTERS:

//.start from beginning
// .end from end

// 3. WHILE START < END:

// .Calculate product using long long:
// .long long product = 1LL * arr[start] * arr[end];
// .If product == x: ✅ return true
// .If product > x: move end--
// .If product < x: move start++

// 4. If no pair found: return false

class Solution {
  public:
    bool isProduct(vector<int> arr, long long x) {
        // code here
        sort(arr.begin(),arr.end());
        int start = 0, end = arr.size()-1;
        while(start < end){
             long long product = 1LL * arr[start] * arr[end];
 
            if(product == x)
            return true;
            else
            if(product > x){
                end--;
            }
            else{
                start++;
            }
        }
        return false;
        
    }
};