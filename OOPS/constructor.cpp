#include<bits/stdc++.h>
using namespace std;
class customer
{
    string  name;
    int  balance;
    int  account_no;

    public:
    //default constructor
    customer()
    {
      name = "vivek";
      balance = 32000;
      account_no = 44412;
    }
   
    //parametrized constructor
    customer(string a,int b,int c)
    {
    name = a;
    balance = b;
    account_no = c;
    }
     void display()
    {
        cout<<"name = " <<name<<endl<<"balance = "<<balance<<endl<<"account_no = "<<account_no<<endl;
    }
};
int main()
{
    customer A1;
    customer A2("vivek", 1234,4412);
     A1.display();
    A2.display();


}