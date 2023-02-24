// #include "imagelib.h"
#include <iostream>
#include <string>
#include<cstdlib>

#include "functionDeclarations.h"

using namespace std;


// Converting Grayscale to Binary Image
/*
int main() {
  // Displays input image
  loadFile("input.png");

  // write your solution here
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (image[i][j] < 70) {
        image[i][j] = 0;
      }
      else {
        image[i][j] = 255;
      }
    }
  }

  // Displays modified image
  saveFile("output/modified.png");
}
*/


int main() {
    int maxGuesses = 7;
    int remainingGuesses = 7;
    char letter;
    static string word;
    static int wordLength;

    displayGameDetails(maxGuesses);

    word = chooseWord();
    wordLength = word.size();
    // cout << word << endl;

    char guessedWord[wordLength];
    replaceDashes(guessedWord, wordLength);

    cout << "Your guess word is:";
    displayWord(guessedWord, wordLength);

    // Game Logic
    while (remainingGuesses > 0) {
        cin >> letter;
        int guess = isGuessTrue(word, guessedWord, letter);
        if (guess == 0) {
            remainingGuesses--;
            cout << remainingGuesses << endl;
            displayHangMan(remainingGuesses);
        }
        if (guess == 1) {
            displayWord(guessedWord, wordLength);
        }
        if (guess == 2) {
            cout << "Already guessed that letter. Try again.";
        }
        if (guessedWord == word) {
            cout << "You Win!";
            break;
        }
    }

    if (remainingGuesses == 0)
        cout << "You Lose!";
}

