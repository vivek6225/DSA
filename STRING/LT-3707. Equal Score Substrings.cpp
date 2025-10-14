
//T.C =0(n)
//S.C = 0(1)

class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.size();   

        int totScore = 0;   
        for (int i = 0; i < n; i++) {
      // Calculate total score by converting each character to its alphabetical value
            totScore += (s[i] - 'a' + 1);
        }

        int leftScore = 0;  
        // Loop through each character except the last one (since we must have both sides non-empty)
        for (int i = 0; i < n - 1; i++) {
            // Add current character's score to leftScore
            leftScore += (s[i] - 'a' + 1);

         
            int rightScore = totScore - leftScore;

         
            if (leftScore == rightScore)
                return true;  // Balanced point found
        }

        // If no balance point found, return false
        return false;
    }
};