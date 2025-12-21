#include<iostream>
using namespace std;

void upperToLower(string &str, int index){

    // Base case
    if(index == -1)
        return;

    // Check: agar character uppercase hai
    if(str[index] >= 'A' && str[index] <= 'Z')
        str[index] = 'a' + (str[index] - 'A');

    // Recursive call
    upperToLower(str, index - 1);
}

int main(){
    string str = "ViVEK";
    upperToLower(str, str.length() - 1);
    cout << str;
}
