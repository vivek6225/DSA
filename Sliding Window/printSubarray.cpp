#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[100];
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    cin.ignore(); // clear newline

    cout << "Enter the elements (comma or space separated): ";
    string line;
    getline(cin, line);

    // Replace commas with spaces
    for (char &c : line)
        if (c == ',') c = ' ';

    stringstream ss(line);
    for (int i = 0; i < n; i++)
        ss >> arr[i];

    // Print all subarrays
    for (int start = 0; start < n; start++) {
        for (int end = start; end < n; end++) {
            for (int i = start; i <= end; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
    return 0;
}
