#include<iostream>
#include<chrono>
#include<string>

using namespace std;

int main(int argc, char const *argv[]){

    char cur_state, button, initial;

    string sentence;
    while(true){
        HERE:
    cur_state = 'S';
    cout << "\n\nInitial point: "<< cur_state << "\n\nEnter expression: ";
    cin >> sentence;

    cout<<"\nPath:\n";

    for(int i = 0; i < sentence.length(); i++){
        button = sentence[i];
        switch(cur_state){
            case 'S':
            switch(button){
                case 'd':
                cur_state = 'A';
                break;
                default:
                cout<<"\nInvalid expression!";
                goto HERE;
                ;

            };
            break;
            case 'C':
            switch(button){
                case 'c':
                cur_state = 'B';
                break;
                default: cout<<"\nInvalid expression!";
                goto HERE;
                ;

            };
            break;

            case 'A':
            switch(button){
                case 'a':
                cur_state = 'B';
                break;
                case 'b':
                cur_state = 'A';
                break;
                default:
                 cout<<"\nInvalid expression!";
                 goto HERE;
                ;

            };
            break;

            case 'B':
            switch(button){
                case 'b':
                cur_state = 'C';
                break;
                case 'a':
                cur_state = 'B';
                break;
                case 'd':
                cout<<"terminal point reached"<< "\nValid expression";
                goto HERE;

                break;
                default:
                 cout<<"\nInvalid expression!";
                 goto HERE;
                ;

            };
            break;



        }


        printf("%c\n", cur_state);

    }


    cout<<"\nFinal destination - "<<cur_state << "\nSentence is valid!";

    }
    return 0;
}
