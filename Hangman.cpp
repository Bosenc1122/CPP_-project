#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to check if the guessed letter is in the word
bool isGuessCorrect(const string& word, char guess) {
    return word.find(guess) != string::npos;
}

// Function to update the display word with correctly guessed letters
void updateDisplayWord(const string& word, const string& displayWord, char guess, string& updatedDisplayWord) {
    for (int i = 0; i < word.length(); ++i) {
        if (word[i] == guess) {
            updatedDisplayWord[i] = guess;
        }
    }
}

// Function to display the hangman
void displayHangman(int attempts) {
    switch (attempts) {
        case 0:
            cout << "_______" << endl;
            cout << "|     |" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "=========" << endl;
            break;
        case 1:
            cout << "_______" << endl;
            cout << "|     |" << endl;
            cout << "|     O" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "=========" << endl;
            break;
        case 2:
            cout << "_______" << endl;
            cout << "|     |" << endl;
            cout << "|     O" << endl;
            cout << "|     |" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "=========" << endl;
            break;
        case 3:
            cout << "_______" << endl;
            cout << "|     |" << endl;
            cout << "|     O" << endl;
            cout << "|    /|" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "=========" << endl;
            break;
        case 4:
            cout << "_______" << endl;
            cout << "|     |" << endl;
            cout << "|     O" << endl;
            cout << "|    /|\\" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << "=========" << endl;
            break;
        case 5:
            cout << "_______" << endl;
            cout << "|     |" << endl;
            cout << "|     O" << endl;
            cout << "|    /|\\" << endl;
            cout << "|    /" << endl;
            cout << "|" << endl;
            cout << "=========" << endl;
            break;
        case 6:
            cout << "_______" << endl;
            cout << "|     |" << endl;
            cout << "|     O" << endl;
            cout << "|    /|\\" << endl;
            cout << "|    / \\" << endl;
            cout << "|" << endl;
            cout << "=========" << endl;
            break;
    }
}

int main() {
    // Word bank (animals and food)
    vector<string> wordBank = {"cat", "dog", "fish", "bird", "elephant", "monkey",
                               "apple", "banana", "orange", "strawberry", "grape", "watermelon",
                               "rabbit", "deer", "chicken", "cow", "sheep", "pig", "goat",
                               "tomato", "potato", "carrot", "lettuce", "cucumber", "onion",
                               "salmon", "shrimp", "lobster", "crab", "squid", "octopus",
                               "steak", "chicken", "pork", "beef", "bacon", "sausage",
                               "cheese", "bread", "butter", "milk", "yogurt", "cream",
                               "pizza", "pasta", "spaghetti", "burger", "sandwich", "fries",
                               "cake", "cookie", "pie", "brownie", "cupcake", "icecream",
                               "soup", "salad", "sushi", "noodle", "rice", "curry",
                               "hamburger", "hotdog", "taco", "burrito", "quesadilla", "enchilada",
                               "grapefruit", "melon", "kiwi", "pineapple", "blueberry", "raspberry",
                               "broccoli", "pepper", "corn", "avocado", "eggplant", "zucchini",
                               "lobster", "crab", "squid", "octopus", "clam", "oyster",
                               "smoothie", "juice", "tea", "coffee", "soda", "water"};

    // Seed for random word selection
    srand(time(0));
    
    // Selecting a random word from the word bank
    string word = wordBank[rand() % wordBank.size()];

    // Display word (initially all underscores)
    string displayWord(word.length(), '_');

    // Set of guessed letters
    string guessedLetters;

    // Number of incorrect guesses
    int incorrectGuesses = 0;

    // Game loop
    while (incorrectGuesses < 6 && displayWord != word) {
        // Display current state of the game
        cout << "Word: ";
        for (char letter : displayWord) {
            cout << letter << " ";
        }
        cout << endl;

        cout << "Guessed letters: ";
        for (char letter : guessedLetters) {
            cout << letter << " ";
        }
        cout << endl;

        // Display hangman
        displayHangman(incorrectGuesses);

        // Get user input
        cout << "Enter a letter guess: ";
        char guess;
        cin >> guess;

        // Check if the guess is valid
        if (guessedLetters.find(guess) != string::npos) {
            cout << "You already guessed that letter!" << endl;
            continue;
        }

        // Add the guessed letter to the set of guessed letters
        guessedLetters += guess;

        // Check if the guess is correct
        if (isGuessCorrect(word, guess)) {
            cout << "Correct guess!" << endl;
            updateDisplayWord(word, displayWord, guess, displayWord);
        } else {
            cout << "Incorrect guess!" << endl;
            incorrectGuesses++;
        }
    }

    // Display final outcome
    if (incorrectGuesses >= 6) {
        cout << "You've been hanged! The word was: " << word << endl;
    } else {
        cout << "Congratulations! You've guessed the word: " << word << endl;
    }

    return 0;
}
