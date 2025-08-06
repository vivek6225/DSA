//s.c =0(n)
//t.c = 0(n)

#include<bits/stdc++.h>
using namespace std;
int main(){
  queue<int> q;
  q.push(1);
  q.push(10);
  q.push(10);
  q.push(20);

  // value print  karao
  int n = q.size();
  while(n--){
    cout<<q.front()<<" ";
    q.push(q.front());  // add the front element to the back
    q.pop();           // remove the front element
    
  }
  cout<<endl;
  cout<<"size of queue = "<<q.size()<<endl;
}


///////////////////////////////////////////////////////////////////////////////
                 //s.c 0(n)
                 //t,c= 0(n)
                 
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//  queue<int> q;
//  q.push(31);
//  q.push(33);
//  q.push(4);
//  q.push(44);
//  q.push(41);

//   vector<int>ans;

//   while(!q.empty()){
//     cout<<q.front()<<" ";
//     ans.push_back(q.front());
//     q.pop();
//   }
  // cout<<endl;
  //   cout << "Queue size after popping: " << q.size() << endl;

  // for(int i = 0; i<ans.size();i++){
  //   q.push(ans[i]);
    
  // }
  //   cout << "Queue size after restoring: " << q.size() << endl;
  // return 0;
  // }

