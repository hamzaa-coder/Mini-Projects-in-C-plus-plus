#include<iostream>
using namespace std;
int main ()
{
    int num1,num2;
    cout<<"Give Two Numbers"<<endl;
    cin>>num1>>num2;
    cout<<"Number 1 : "<<num1<<endl;
    cout<<"Number 2 : " <<num2<<endl;
    int temp;
    temp=num1;
    num1=num2;
    num2=temp;;
    cout<<"Number 1 : "<<num1<<endl;
    cout<<"Numbwe 2 : "<<num2<<endl;
    return 0;
}