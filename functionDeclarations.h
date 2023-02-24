#include <string>

using std::string;


// Function Declarations
void displayGameDetails(int maxGuesses);
string chooseWord();
void replaceDashes(char(&guessedWord)[5], int length);
void displayWord(string word, int length);
int isGuessTrue(string word, char(&guessedWord)[5], char letter);
void displayHangMan(int remainingGuesses);
