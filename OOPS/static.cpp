#include<bits/stdc++.h>
using namespace std;
class customer
{
    string name;
    int account_no,balance;
    static int total_customer;
    public:
    customer(string name,int account_no, int balance)

    {
        this->name = name;
        this->account_no = account_no;
        this->balance = balance;
        total_customer++;

    }
    void display()
    {
     cout<<"name = "<<name<<endl<<"accoun_no = "<<account_no<<endl<<"balance = "<<balance<<endl<<"TotalCustomer = "<<total_customer<<endl;
    }
    void display_total()
    {
        cout<<total_customer<<endl;
    }
    
};
 int customer::total_customer = 0;


   int main()
{
    customer A1("vivek",2,20000);
    customer A2("Ankit",3,44444);
    A1.display ();
    A2.display ();
    customer A3("Rupam",5,8888);
    A2.display_total();

}