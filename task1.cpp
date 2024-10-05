#include<bits/stdc++.h>
using namespace std;

int main(){
    srand(static_cast<unsigned int>(time(0)));

    int ranNumber = rand() % 50 + 1; // 50 is used to generate a random number between 1 and 50
    int guessNumber = 0;

    cout << "Let us begin:)" << endl;

    while(guessNumber != ranNumber){
        
        cout << "Guess the Number :";
        cin >> guessNumber;

        if(guessNumber > ranNumber){
            cout << "Too High! Try again." << endl;
        }
        else if(guessNumber < ranNumber){
            cout << "Too Low! Try again." << endl;
        }
        else{
            cout << "Congrats! You guessed the correct number." << endl;
        }
    }

}