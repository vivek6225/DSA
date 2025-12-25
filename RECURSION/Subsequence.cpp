#include<bits/stdc++.h>
using namespace std;

// Function to generate all subsequences
void Subsequence(int arr[], int index, int n,
                 vector<vector<int>>& ans, vector<int> temp) {

    // Base case: when we reach end of array
    if(index == n){
        ans.push_back(temp);   // store current subsequence
        return;
    }

    // 1️⃣ Choice: Do NOT include current element
    Subsequence(arr, index + 1, n, ans, temp);

    // 2️⃣ Choice: Include current element
    temp.push_back(arr[index]);
    Subsequence(arr, index + 1, n, ans, temp);
}

int main(){
    int arr[] = {1,2,3};

    vector<vector<int>> ans;  // stores all subsequences
    vector<int> temp;        // stores one subsequence at a time

    Subsequence(arr, 0, 3, ans, temp);

    // Print all subsequences
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
