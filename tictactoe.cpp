#include <iostream>
using namespace std;

char ch[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int digit;
string n1;
string n2;
int row,column;
bool winner;
char token='X';
int c=9;
void fun1(){
    cout<<"\n    |     |   "<<endl;
    cout<<ch[0][0]<<"   | "<<ch[0][1]<<"   |  "<<ch[0][2]<<endl;
    cout<<"____|_____|_____"<<endl;
    cout<<"    |     |   "<<endl;
    cout<<ch[1][0]<<"   | "<<ch[1][1]<<"   |  "<<ch[1][2]<<endl;
    cout<<"____|_____|_____"<<endl;
    cout<<"    |     |   "<<endl;
    cout<<ch[2][0]<<"   | "<<ch[2][1]<<"   |  "<<ch[2][2]<<endl;
    cout<<"    |     |   "<<endl;
    if(token=='X'){
        cout<<"\nPlayer "<<n1<<" enter the digit from 1 to 9: ";
        cin>>digit;
    }
    if(token=='O'){
        cout<<"\nPlayer "<<n2<<" enter the digit from 1 to 9: ";
        cin>>digit;
    }
    if(digit==1){
        row=0;
        column=0;
    }
    else if(digit==2){
        row=0;
        column=1;
    }
    else if(digit==3){
        row=0;
        column=2;
    }
     else if(digit==4){
        row=1;
        column=0;
    }
     else if(digit==5){
        row=1;
        column=1;
    }
     else if(digit==6){
        row=1;
        column=2;
    }
     else if(digit==7){
        row=2;
        column=0;
    }
     else if(digit==8){
        row=2;
        column=1;
    }
    else if(digit==9){
        row=2;
        column=2;
    }
    if(token=='X' && ch[row][column]!='X' && ch[row][column]!='O'){
        ch[row][column]='X';
        token='O';
    }
    else if(token=='O' && ch[row][column]!='X' && ch[row][column]!='O'){
        ch[row][column]='O';
        token='X';
    }
    else{
        cout<<"\n there is no empty space"<<endl;
        fun1();
    }
}
int fun2(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(ch[i][j]=='O' || ch[i][j]=='X'){
                c=c+1;
            }
        }
    }
    return c;
}
bool fun3(){
    for(int i=0;i<3;i++)
    {
        if(ch[0][i]==ch[1][i] && ch[0][i]==ch[2][i]){
            winner=true;
        }
        if(ch[i][0]==ch[1][i] && ch[i][0]==ch[i][2]){
            winner=true;
        }
    }
    if(ch[0][0]==ch[1][1] && ch[0][0]==ch[2][2]){
        winner=true;
    }
    if(ch[0][2]==ch[1][1]&&ch[0][2]==ch[2][0]){
        winner=true;
    }
    
    return winner;
}
int main()
{
    bool tie;
    cout<<"Tic Tac Toe Game "<<endl;
    cout<<"\n\n";
    cout<<"enter the player 1 name: ";
    cin>>n1;
    cout<<"\nenter the player 2 name: ";
    cin>>n2;
    while(!fun3()){
    fun1();
    fun3();
    fun2();
    }
    int d=fun2();
    bool r=fun3();
    if(d>=9 && r==false){
        tie=true;
    }
    else{
        tie=false;
    }
    if(token=='X'&& tie==false){
        cout<<"\nPlayer "<<n2<<" is the winner";
    }
    else if(token=='O'&& tie==false){
        cout<<"\nPlayer "<<n1<<" is the winner";
    }
    else{
        cout<<"\nits a draw game";
    }
}