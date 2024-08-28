#include<iostream>
using namespace std;
int main ()
{
    int num;
    cout<<"Give Number "<<endl;
    cin>>num;
    int sum=0;
    while(num!=0){
        int a =num%10;
        num=num/10;
        sum+=a;
    }
    cout<<"Sum Of Digits is : "<<sum<<endl;
    return 0;
}