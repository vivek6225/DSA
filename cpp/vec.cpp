#include<bits/stdc++.h>
using namespace std;
int main() 
{
//     vector<int>v;
//     vector<int>v1(5,2);

//     cout<<"size of v:"<<v.size()<<endl;
//     cout<<"capacity of v:"<<v.capacity()<<endl;
//     v.push_back(4);
//     v.push_back(5);
//     v.push_back(8);
//     cout<<"size of v :"<<v.size()<<endl;
//     cout<<"size of capaciyt :"<<v.capacity()<<endl;
//     v[1]=8;

//     cout<<"size of v1 :"<<v1.size()<<endl;
//     cout<<"size of capacity :"<<v1.capacity()<<endl;
//     v1.push_back(6);
//     cout<<"size of v1 :"<<v1.size()<<endl;
//     cout<<"size of capacity :"<<v1.capacity()<<endl;
// 

// vector<int>vnew;
// vnew.push_back(62);
// vnew.push_back(61);
// vnew.push_back(67);
// vnew.push_back(601);
// vnew.push_back(666);
// vnew.pop_back();
// 
// vector<int>arr;
// arr.push_back(222);
// arr.push_back(29);
// arr.push_back(21);
// arr.push_back(22);
// arr.push_back(24);
// cout<<"size of arr :"<<arr[0]<<endl;
// cout<<"size of arr :"<<arr.front()<<endl;
// cout<<"size of arr:"<<arr[arr.size()-1]<<endl;
// cout<<"size of arr:"<<arr.back()<<endl;


vector<int>ans;
ans.push_back(2);
ans.push_back(0);
ans.push_back(1);
ans.push_back(550);
ans.push_back(533);

sort(ans.begin(),ans.end());
for(int i=0;i<ans.size();i++)
cout<<ans[i]<<" ";
cout<<endl;

// sort(ans.begin(),ans.end(),greater<int>());
// for(int i=0;i<ans.size();i++)
// cout<<ans[i]<<" ";

cout<<binary_search(ans.begin(),ans.end(),550)<<endl;






}


