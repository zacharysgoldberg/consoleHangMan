#include "functionDeclarations.h"

#include <iostream>
#include<ctime>


using namespace std;

// Functions

string chooseWord() {
    string words[5] = { "development", "information", "technology", "software", "engineer" };
    srand(time(NULL));
    int arrayLength = *(&words + 1) - words;
    int index = rand() % arrayLength;
    // cout << index;
    string word = words[index];
    return word;
}

void replaceDashes(char(&guessedWord)[5], int length) {
    for (int i = 0; i < length; i++) {
        guessedWord[i] = '-';
    }
    guessedWord[length] = '\0';
}

void displayWord(string word, int length) {
    for (int i = 0; i < length; i++) {
        cout << word[i];
    }
    cout << endl;
}

int isGuessTrue(string word, char(&guessedWord)[5], char letter) {
    int wordLength = word.length();
    int flag = 0;
    for (int i = 0; i < wordLength; i++) {
        if (word[i] == letter) {
            if (guessedWord[i] == letter) {
                flag = 2;
            }
            else {
                guessedWord[i] = letter;
                flag = 1;
            }
        }
    }
    return flag;
}

void displayHangMan(int remainingGuesses) {
    string part[5];
    switch (remainingGuesses) {
    case 0:
        part[4] = "|";
    case 1:
        part[3] = "/ \\";
    case 2:
        part[2] = "|";
    case 3:
        part[1] = "/|\\";
    case 4:
        part[0] = "( )";
        break;
    }

    cout << "--------------\n";
    cout << "  |       " << part[4] << endl;
    cout << "  |       " << part[4] << endl;
    cout << "  |      " << part[0] << endl;
    cout << "  |      " << part[1] << endl;
    cout << "  |       " << part[2] << endl;
    cout << "  |      " << part[3] << endl;
    cout << "  |\n";
    cout << "  |\n";
    cout << "--------------\n";
}

void displayGameDetails(int maxGuesses) {

    string rules = " You are shown a number of blank lines representing a secret word,\
    and you have to reveal the secret word by guessing letters correctly.\n\
    You can guess one letter at a time, and the game terminates after a certain number of incorrect guesses.\n\
    If you guess the letter that is present in the secret word, that letter is revealed in place of the blank.\n\
    If you guess the wrong letter, you lose one try, and some part of a person is drawn on the gallows.\n\
    After a certain number of incorrect guesses, a person will be hanged on the gallows, and the game is over.\n\
    If you guess all the letters in the secret word before the man is hanged completely, you win!";

    cout << "Intro:" << "\n"
        "        .-------------------------------------------------------------------------------.\n"
        "        |      _      _                                                                  |\n"
        "        |     | |    | |   __ _    _ __      __ _        /\\/\\      __ _    _ __          |\n"
        "        |     | |----| |  / _  |  |  _ \\    / _` |      /    \\    / _  |  |  _  \\        |\n"
        "        |     | |----| | | (_| |  | | | |  | (_| |     / /\\/\\ |  | (_| |  | | | |        |\n"
        "        |     |_|    |_|  \\_ _ |  |_| |_|   \\__, |     \\/    \\/   \\_ _ |  |_| |_|        |\n"
        "        |                                    |___/                                       |\n"
        "        .--------------------------------------------------------------------------------.\n";
    cout << "Rules:" << rules << endl;
    cout << "" << endl;
    cout << "You have to guess one letter at a time and you can have " << maxGuesses << " wrong attempts\n\n";
    cout << "Enter a lower-case letter and don't forget to enter key after each guess\n\n";
    cout << "Let's play the game!\n\n";
}
