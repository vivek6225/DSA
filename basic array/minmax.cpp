#include<bits/stdc++.h>
using namespace std;

int getMin(int num[],int n){
//int min = INT_MAX;
int mini = INT_MAX;

    for(int i = 0;i<n; i++){

        mini = min(mini,num[i]);
        // if(num[i]<min){
        //     min = num[i];
        }
    //}
  //  return min;
  return mini;
}
    int getMax(int num[],int n){
        //int max = INT_MIN;
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++){

            maxi = max(maxi,num[i]);
            // if(num[i]>max){
            //     max = num[i];
            // }

        }
       // return max;
       return maxi;
    }


int main(){
    int size;
    cout<<"size of element = ";
    cin>>size;
    int num[100];
    cout<<"enter the element = ";
    for(int i = 0; i<size; i++){
    cin>>num[i];
}
 cout<<"maximum value is =  "<<getMax(num,size)<<endl;
 cout<<"minimum value is = "<<getMin(num,size)<<endl;
}