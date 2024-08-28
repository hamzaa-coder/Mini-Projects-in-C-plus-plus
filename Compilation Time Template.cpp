#include<iostream>
#include<chrono>
using namespace std;
int main(){
    auto start = chrono::steady_clock::now();
    cout<<endl;
    int a;
    int b;
    int c;
    a=654;
    b=987;
    c=a+b;
    cout<<c<<endl;
    auto end = chrono::steady_clock::now();
auto diff = end - start;
cout << chrono::duration<double, milli>(diff).count() << " ms" << endl;
return 0;
}