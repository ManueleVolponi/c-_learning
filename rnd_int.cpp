#include <string>
#include <vector>
#include <iostream>
#include <cstdlib> // for rand, srand
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int currentGuess;
    int rndNumber  = rand() % 100;


    cin.clear();

    do {
        cout << "Choose your number between 0 and 99: ";
        cin >> currentGuess;
        
    } while (currentGuess != rndNumber);

    cout << "You guessed the number: " << currentGuess << '\n';
    return 0;
}