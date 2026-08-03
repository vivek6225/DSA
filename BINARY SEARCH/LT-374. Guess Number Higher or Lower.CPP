//-----------Optimal Approach-----------------
/**
 * Forward declaration of guess API.
 * int guess(int num);
 */
// Time Complexity = O(log n)
// Space Complexity = O(1)
class Solution {
public:
    int guessNumber(int n) {

        int start = 1, end = n;

        // Apply Binary Search
        while (start <= end) {

            // Calculate middle in every iteration
            int mid = start + (end - start) / 2;

            if (guess(mid) == 0) {
                return mid;
            }

            // Guessed number is higher than the picked number
            if (guess(mid) == -1) {
                end = mid - 1;
            }

            // Guessed number is lower than the picked number
            else {
                start = mid + 1;
            }
        }

        return -1;
    }
};

//-----------Brute Force Approach-----------------
/** 
 * Forward declaration of guess API.
 * int guess(int num);
 */
// Time Complexity = O(n)
// Space Complexity = O(1)
class Solution {
public:
    int guessNumber(int n) {

        // Check every number from 1 to n
        for (int i = 1; i <= n; i++) {

            // If the guessed number is correct
            if (guess(i) == 0) {
                return i;
            }
        }

        return -1;
    }
};