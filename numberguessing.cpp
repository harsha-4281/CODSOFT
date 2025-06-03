#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    cout<<"Welcome to the guessing number game"<<endl;
    cout<<"you need to guess the number between 1-100 genreated by computer within limited chances"<<endl;
    
    while(true){
        cout<<"enter 1 for difficulty level"<<endl;
        cout<<"enter 2 for medium level"<<endl;
        cout<<"enter 3 for hard level"<<endl<<endl;
        
        int level;
        cout<<"enter the level: ";
        cin>>level;
        
        srand(time(0));
        int rnumber= 1+(rand() % 100);
        
        int playerchoice;
        if(level==1){
            cout<<"\nyou have 10 chances to guess the right number"<<endl<<endl;
            int chancesleft=10;
            for(int i=0;i<10;i++){
                cout<<"\nguess the number: ";
                cin>>playerchoice;
                if(playerchoice==rnumber){
                    cout<<"\nYou won, well played"<<endl<<endl;
                    cout<<"\nplay agian or else exit by entering 0"<<endl;
                    break;
                }
                else{
                    cout<<"\nNope you guessed the wrong number"<<endl;
                    if(playerchoice<rnumber){
                    cout<<"\nrandom number is greater than the number you chosen"<<endl;
                    }
                    else{
                    cout<<"\nrandom number is less than the number you chosen"<<endl;
                    }
                }
                chancesleft--;
                if(chancesleft==0){
                    cout<<"\nYour chances are over "<<endl;
                    cout<<"\nYou lost the game"<<endl;
                }
            }
        }
        else if(level==2){
            cout<<"\nyou have 7 chances to guess the number"<<endl;
            int chancesleft=7;
            for(int j=0;j<7;j++){
                 cout<<"\nguess the number: ";
                cin>>playerchoice;
                if(playerchoice==rnumber){
                    cout<<"\nYou won, well played"<<endl<<endl;
                    cout<<"\nplay agian or else exit by entering 0"<<endl;
                    break;
                }
                else{
                    cout<<"\nNope you guessed the wrong number"<<endl;
                    if(playerchoice<rnumber){
                    cout<<"\nrandom number is greater than the number you chosen"<<endl;
                    }
                    else{
                    cout<<"\nrandom number is less than the number you chosen"<<endl;
                    }
                }
                chancesleft--;
                if(chancesleft==0){
                    cout<<"\nYour chances are over "<<endl;
                    cout<<"\nYou lost the game"<<endl;
                }
            }
        }
        else if(level==3){
            cout<<"\nyou have 5 chances to guess the number"<<endl;
            int chancesleft=5;
            for(int k=0;k<5;k++){
                cout<<"\nguess the number: ";
                cin>>playerchoice;
                if(playerchoice==rnumber){
                    cout<<"\nYou won, well played"<<endl<<endl;
                    cout<<"\nplay agian or else exit by entering 0"<<endl;
                    break;
                }
                else{
                    cout<<"\nNope you guessed the wrong number"<<endl;
                    if(playerchoice<rnumber){
                    cout<<"\nrandom number is greater than the number you chosen"<<endl;
                    }
                    else{
                    cout<<"\nrandom number is less than the number you chosen"<<endl;
                    }
                }
                chancesleft--;
                if(chancesleft==0){
                    cout<<"Your chances are over "<<endl;
                    cout<<"You lost the game"<<endl;
                }
            }
        }
        else if(level==0){
            exit(0);
        }
        else{
            cout<<"\nyour input value is invalid "<<endl;
            cout<<"try to enter valid number"<<endl;
        }
    }
    return 0;
}