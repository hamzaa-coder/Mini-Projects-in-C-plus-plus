#include<iostream>
#include<conio.h>
using namespace std;
int main ()
{
    int m,n;
    cout<<"Give Order of Matrix "<<endl;
    cin>>m>>n;
    int a[m][n];
    int i,j;
    cout<<"Give Entries Of Matrix"<<endl;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<"You Entered Following Array "<<endl;
    
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            cout<<a[i][j]<<"    ";   
         }
         cout<<endl;
    }
    cout<<"Highest Entry In Each Row Are :: "<<endl;

    int high;
    for(i=0;i<m;i++){
        high=a[i][0];
        for(j=0;j<m;j++){
            if(a[i][j]>high){
                high=a[i][j];
            }
          }
          cout<<"Highest Entry in Row  "<<i+1<<" = "<<high<<endl;
    }
    getch();
    return 0;
}