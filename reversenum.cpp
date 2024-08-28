#include<iostream>
using namespace std;
int main ()
{
  int n;
  cout<<"Give Number You Want to be Reversed "<<endl;
  cin>>n;
  int r=0;
  while(n!=0){
    int dig=n%10;
    r=r*10+dig;
    n=n/10;
  }
  cout<<r<<endl;
  return 0;
}