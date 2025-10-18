#include <bits/stdc++.h>
using namespace std;

int power(int num, int n) {
    if (n == 0)
        return 1;  // any number power 0 = 1
    if (n == 1)
        return num;  // base case

    return num * power(num, n - 1);
}

int main() {
    int n;
    cout << "Enter the power: ";
    cin >> n;
    cout << power(2, n);  // calculates 2^n
    return 0;
}
