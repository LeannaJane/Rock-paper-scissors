#include <iostream>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <thread>
#include <chrono>
#include <random>
using namespace std;

// A C++ program for ROCK PAPER OR SCISSORS.
int main()
{
    // initialising variables for user choices, repeitions. 
    bool repeat = true;

    string computerChoice;
    string choice;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 2);


    while (repeat) {
        cout << "----------------------------------------------------------------------" << endl;
        cout << "Rock, Paper and Scissors Game!" << endl;

        while (true)
        {
            cout << "Choose one of the following options: rock, paper, scissors" << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cin >> choice;

            transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

            if (choice == "rock" || choice == "paper" || choice == "scissors") {
                break;
            }
            else {
                cout << "Invalid choice. Please enter Rock, Paper, or Scissors.\n";
            }
        }


        choice[0] = toupper(choice[0]);
        cout << "You chose: " << choice << ".\n";
        choice[0] = tolower(choice[0]);
        cout << "The computer is choosing";
        for (int i = 0; i < 3; i++) {
            cout << ".";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        cout << "\r                 " << "\r";

        int randomNumber = dis(gen);

        switch (randomNumber) {
        case 0:
            computerChoice = "rock";
            break;
        case 1:
            computerChoice = "paper";
            break;
        case 2:
            computerChoice = "scissors";
            break;
        default:
            computerChoice = "invalid";
            break;
        }

        computerChoice[0] = toupper(computerChoice[0]);
        cout << "The Computer chose: " << computerChoice << ".\n";
        computerChoice[0] = tolower(computerChoice[0]);
        cout << "----------------------------------------------------------------------" << endl;

        if (choice == computerChoice) {
            cout << "It's a tie!" << endl;
        }
        else if (choice == "rock" && computerChoice == "scissors") {
            cout << "User wins! Rock beats Scissors." << endl;
        }
        else if (choice == "scissors" && computerChoice == "rock") {
            cout << "Computer wins! Rock beats Scissors." << endl;
        }
        else if (choice == "scissors" && computerChoice == "paper") {
            cout << "User wins! Scissors beats Paper." << endl;
        }
        else if (choice == "paper" && computerChoice == "scissors") {
            cout << "Computer wins! Scissors beats Paper." << endl;
        }
        else if (choice == "paper" && computerChoice == "rock") {
            cout << "User wins! Paper beats Rock." << endl;
        }
        else if (choice == "rock" && computerChoice == "paper") {
            cout << "Computer wins! Paper beats Rock." << endl;
        }


        cout << endl;
        cout << "----------------------------------------------------------------------" << endl;
        cout << "Do you want to play again? (yes/no): " << endl;
        cout << "----------------------------------------------------------------------" << endl;
        string playAgain;
        cin >> playAgain;

        transform(playAgain.begin(), playAgain.end(), playAgain.begin(), ::tolower);

        if (playAgain != "yes") {
            repeat = false;
            cout << "----------------------------------------------------------------------" << endl;
            cout << "Thanks for playing";
        }
        else {
            system("cls");
        }
    }
    return 0;
}
