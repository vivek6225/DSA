
//T.C = 0(log n)
//S.C = 0(1)

class Solution {
public:
    double myPow(double x, int n) {
        // Base cases
        if (n == 0) return 1.0;   // x^0 = 1
        if (x == 0) return 0.0;   // 0^n = 0

        // Convert 'n' to a long to handle overflow when n = INT_MIN
        long power = n;

        // If exponent is negative, invert x and make power positive
        if (power < 0) {
            x = 1 / x;
            power = -power;
        }

        double ans = 1.0;

        // Fast Exponentiation (Binary Exponentiation)
        // Multiply 'ans' only when the current bit of power is 1
        while (power > 0) {
            if (power % 2 == 1)  // If the current bit is set
                ans *= x;

            x *= x;              // Square the base
            power /= 2;          // Move to the next bit
        }

        return ans;
    }
};