#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Give Size of Array"<<endl;
    cin>>n;
    int a[n];
    int i;
    cout<<"Give Array Entries"<<endl;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int j;
    cout<<"Sorted Array is "<<endl;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(a[j]<a[i]){
            int b=a[j];
            a[j]=a[i];
            a[i]=b;
        }
    }

    }
    cout<<"[ "; 
    for(i=0;i<n;i++){
        cout<<a[i]<<" ,";
    }
    cout<<" ]"<<endl;
    return 0;   
}