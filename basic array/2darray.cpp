#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,m;
   
    cout<<"Enter rows and cols = ";
     cin>>n>>m;
     cout<<"enter the number = ";
    vector<vector<int> >matrix(n,vector<int>(m,1));

    for(int i = 0;i<n; i++)
    for(int j = 0;j<m;j++)
    cin>>matrix[i][j];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        cout<<matrix[i][j] <<" ";
        cout<<endl;
    }
    return 0;
}


//create vector
// vector<vector<int> >matrix(3,vector<int>(4,3));
// for(int i= 0;i<3;i++)
// for(int j= 0; j<4; j++)
// cout<<matrix[i][j]<<" ";
// cout<<endl;
// cout<<"rows = " <<matrix.size();
// cout<<endl;
// cout<<"cols = "<<matrix[0].size(); 

// }