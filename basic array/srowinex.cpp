#include<bits/stdc++.h>
using namespace std;

void printrowmax(int arr[][4],int row,int col){
   
   int index = -1, sum = INT_MIN;
   for(int i=0; i<row; i++){
    int total = 0;
    for(int j = 0; j<col; j++)
        total+=arr[i][j];
        if(total>sum){
        sum = total;
        index = i;
    }
   }
   cout<<index<<" ";
}

int main()
{
 int arr1[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
 int arr2[3][4] = {1,2,3,3,2,1,4,5,6,6,5,4};

 printrowmax(arr2,3,4);

}