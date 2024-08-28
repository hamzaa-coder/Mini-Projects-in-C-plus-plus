#include<iostream>
using namespace std;
int i;
int main ()
{
    int n;
    int bin[100];
    cout<<"Give Number with Base 10 "<<endl;
    cin>>n;
    for(i=0;n>0;i++)
    {
        bin[i]=n%2;
        n=n/2;
    }
    cout<<"Binary Equilent is :: ";
    for(i=i-1;i>=0;i--){
        cout<<bin[i];
    }
    return 0;
}