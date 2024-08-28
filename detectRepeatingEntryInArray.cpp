#include<iostream>
using namespace std;
int main ()
{
    int n;
    cout<<"Give Size of Array"<<endl;
    cin>>n;
    int a[n];
    cout<<"Give Entries of Array"<<endl;
    int i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    bool repeating=false;
    for(i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j]){
                cout<<" Duplicate Entry Found : "<<a[i]<<endl;
                repeating =true;
            }
        }
    }
    if(!repeating){
        cout<<"No Repeating Entry Found"<<endl;
    }
    return 0;
}
