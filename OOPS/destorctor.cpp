#include<bits/stdc++.h>
using namespace std;
class customer
{
    string name;
    int *data;
    public:
  
    //constructor
    customer(string name)
    {
        this->name = name;

        cout<<"constructor name  "<<name<<endl;
    }
    //destructor
    ~customer()
    {
        cout<<"destructor name "<<name<<endl;;
    }
};
int main()
{
    customer A1("1"),A2("2"),A3("3");

}