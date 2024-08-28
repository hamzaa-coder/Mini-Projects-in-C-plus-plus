#include<iostream>
using namespace std;
void convert(int num){
    int bin[100];
    int i=0;
    if(num==0)
    {
        cout<<"Binary Form is 0"<<endl;
        return ;
    }
    while(num>0){
            bin[i]=num%2;
            num=num/2;
            i++;
        }
        cout<<"Binary Equivalent is :: ";
        for(i=i-1;i>=0;i--){
            cout<<bin[i];
        }
        cout<<endl;
    }
int main ()
{
    int num;
    cout<<"Give  Decimal Number "<<endl;
    cin>>num;
    if(num<0){
        cout<<"Invalid Number"<<endl;
    }
    else{
        convert(num);
    }
    return 0;
}