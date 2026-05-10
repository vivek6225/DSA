//--------------------Optimal Approach--------------------
// Time: O(n)
// Space: O(1)
class Solution {
public:

    // check if character is vowel
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    }

    string reverseVowels(string s) {

        int n = s.length();

        int start = 0, end = n - 1;

        // two pointer approach
        while(start < end){

            // move start until vowel found
            if(!isVowel(s[start])){
                start++;
            }
            // move end until vowel found
            else if(!isVowel(s[end])){
                end--;
            }
            else{
                // swap vowels
                swap(s[start], s[end]);
                start++;
                end--;
            }
        }

        return s;
    }
};
//------------Briye force Approach-------------------------------
class Solution {
public:

    // check if character is vowel
    bool isVowel(char ch){
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
                ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U');
    }

    string reverseVowels(string s) {

        vector<char> v;   // store vowels

        // Step 1: collect vowels
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];

            if(isVowel(ch)){
                v.push_back(ch);
            }
        }

        int j = v.size() - 1;

        // Step 2: replace vowels in reverse order
        for(int i = 0; i < s.length(); i++){

            if(isVowel(s[i])){
                s[i] = v[j];   // put reversed vowel
                j--;           // move backward
            }
        }

        return s;
    }
};