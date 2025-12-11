#include<iostream>
using namespace std;

// Function to print even numbers from num to N
void printeven(int num, int N) {
    // Base condition: when num reaches N, print last number and stop
    if (num == N) {
        cout << num;
        return;
    }

    // Print current even number
    cout << num << " ";

    // Recursive call to print next even number
    printeven(num + 2, N);  
}

int main() {
    int N;
    cin >> N;

    // If N is odd, reduce it to previous even number
    if (N % 2 == 1)
        N--;

    // Start printing from 2 to N
    printeven(2, N);   //  Pass both arguments
}
