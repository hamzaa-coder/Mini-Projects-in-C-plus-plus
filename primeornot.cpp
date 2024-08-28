#include<iostream>
using namespace std;
int main ()
{
    int a,b;
    cout<<"Give Number "<<endl;
    cin>>a;
    bool prime=true;
    for(b=2;b!=a;b++){
      if(a%b==0){
        prime =false;
        break;
      }  
    }
    if(prime){
        cout<<"Prime"<<endl;
    }
    else{
        cout<<"Not Prime "<<endl;
    }
    return 0 ;

}