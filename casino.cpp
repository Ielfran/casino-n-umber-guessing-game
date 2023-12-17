#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
void rules();
void draw(int n,char c);

int main(){
    string playname;
    int amount;
    int betting;
    int guess;
    int dice;
    char choice;

    srand(time(0));
    draw(60,'_');
    cout<<"\n\n\n\n\n\nCASINO\n\n\n\n\n\n\n";
    draw(60,'_');
    cout<<"\nEnter your name:";
    getline(cin,playname);
    cout<<"\n\nEnter amount to play the game with:$";
    cin>>amount;

    do{
        system("cls");
        rules();
        cout<<"\nYour current balance is:"<<amount<<endl;

        do{
            cout<<playname<<"Enter the money to bet:$";
            cin>>betting;
            if(betting>amount){
                cout<<"Your betting amount exceeds the amount you have\n";
                cout<<"Re enter the data";
            }
        }while(betting>amount);

        do{
            cout<<"Guess your number to bet between 1 to 10:";
            cin>>guess;
            if(guess<=0||guess>10){
                cout<<"Please check the number . It should be between 1 and 10\n";
                cout<<"Re enter the data\n";
            }
        }while(guess<=0||guess>10);

        dice=rand()%10+1;   //generates random number between 1 and 10
    
        if(dice==guess){
            cout<<"\n\nyou won Rs"<<betting*10;
            amount=amount+betting*10;
        }
        else{
            cout<<"Bad luck you lost.You lost Rs"<<betting<<"\n";
            amount=amount-betting;
        }
        cout<<"\nThe winning number was:"<<dice<<"\n";
        cout<<"\n"<<playname<<" you have $"<<amount<<"\n";
        if(amount==0){
            cout<<"You have no money to play.";
            break;
        }
        cout<<"\n\nDo you want to play again(y/n):";
        cin>>choice;
    }while(choice=='y'||choice=='n');
    draw(90,'-');
    cout<<"Thanks for playing"<<endl;
    draw(90,'-');

    return 0;
}
void draw(int n,char c){
        for(int i=0;i<n;i++)
            cout<<c;
        cout<<'\n';
}
void rules(){
    system("cls");
    cout<<"\n\n";
    draw(90,'-');
    cout<<"\t\t\tThe rules of the game are\n";
    draw(90,'-');
    cout<<"\t\t\t\tChoose a number between 1 to 10\n";
    cout<<"\t\t\t\tIf you win you will get 10 times of money you bet\n";
    cout<<"\t\t\t\tIf you lose your money will be taken.";
    draw(90,'-');
}