#include<iostream>
using namespace std;
int main ()
{
    char oper;
    cout<<"Enter M for Conversion from Meter to Feet : Enter F for Conversion from Feet to Meter "<<endl;
    cin>>oper;
    double x,y;
    switch(oper){
        case 'M':case 'm':{
            cout<<"Give Length in Meters "<<endl;
            cin>>x;
            y=(3.28084)*x;
            cout<<"Length in Feet is :: "<<y<<endl;
            break;
        }
        case 'F':case 'f':{
            cout<<"Give Length in Feet "<<endl;
            cin>>x;
            y=x/(3.28084);
            cout<<" Length in Meters is :: "<<y<<endl;
            break;
        }
        default:
        {
            cout<<"Invalid Input "<<endl;
            break;
        }
    }
    return 0;
}