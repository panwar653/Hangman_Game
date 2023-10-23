#include<iostream>
#include<ctime>
using namespace std;

int tries=5;
string message="you have 5 chances!";

void hang_man(char);
int checkGuess(char,string,string&);

int main(){
    char letter ;
    string movie;
    string movies[]={"jawan","heropanti","fukreyy","tarzan","avengers","doraemon"};
    
    srand(time(NULL));
    int movie_number=rand()%6;
    movie=movies[movie_number];
    
    string hide_movie(movie.length(),'X');
    system("cls");

    while(tries!=0){
         hang_man('n');
         cout<<"\t\t\t\tLife: "<<tries<<endl;
         cout<<hide_movie<<endl;
         cout<<"\t\t\t\tGuess a letter: ";
         cin>>letter;

         system("cls");
         
         if(checkGuess(letter,movie,hide_movie)==0){
            message="Incorretc Letter!";
            tries--;
         }
         else{
            message="Nice! Correct Guess";
         }

         if(hide_movie==movie){
            message="You're Free!";
            hang_man('f');
            cout<<"\t\t\t\tLife:"<<tries<<endl;
            cout<<"\t\t\t\tThe movie is :"<<movie<<endl;
            break;

         }
    }

    if(tries==0){
        message="you are hanged!";
        hang_man('h');
         cout<<"\t\t\t\tLife:"<<tries<<endl;
         cout<<"\t\t\t\tThe movie is :"<<movie<<endl;
         

    }
}

    int checkGuess(char guess,string real_movie, string &hidden_movie){
        int matches=0;
        int len=real_movie.length();
        for(int i=0;i<len;i++){
            if(guess==hidden_movie[i]){
                return 0;
            }
            if(guess==real_movie[i]){
                hidden_movie[i]==guess;
                matches++;
            }
        }
        return matches;
    }

    void hang_man(char state){
        string head_string="|";
        string stage="=";
        if(state=='f'){
            head_string=" ";
        }
        else if(state=='h'){
            stage=" ";
        }

        cout<<"\t\t\t\t__________________"<<endl;
        cout<<"\t\t\t\t        "<<head_string<<"        |"<<endl;
        cout<<"\t\t\t\t        O        |"<<endl;
        cout<<"\t\t\t\t       / \\      |"<<"\t      "<<message<<endl;    
        cout<<"\t\t\t\t        |        |"<<"\t      /"<<endl;
        cout<<"\t\t\t\t       / \\      |           O"<<endl;
        cout<<"\t\t\t\t=="<<stage<<stage<<stage<<stage<<stage <<"==|          / \\"<<endl;
        cout<<"\t\t\t\t|               ||           |  "<<endl;
        cout<<"\t\t\t\t|               ||         /  \\"<<endl;
        cout<<"\t\t\t\t============================================"<<endl;



    }


