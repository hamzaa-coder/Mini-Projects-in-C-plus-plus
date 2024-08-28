#include<iostream>
using namespace std;
#include<cstdlib>
#include<conio.h>
int main(){
    int secretNumber= rand() %101;
    int guess;
    int attempt=0;
    cout<<"Welcome To the Number Guessing Game"<<endl;
    do{
        cout<<"Please Input Your Guess :: "<<endl;
        cin>>guess;
        attempt++;
        if(guess==secretNumber){
            cout<<"Great,You Guessed Correct Number in "<<attempt<<" Attempts"<<endl;
            break;
        }
        else if(guess>secretNumber){
            cout<<"***Too High***"<<endl;
        }
        else if(guess<secretNumber){
            cout<<"***Too Low***"<<endl;
        }
    }while(guess!=secretNumber);
    getch();
    return 0;
}