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
    // Word bank
    vector<string> wordBank = {"hangman", "programming", "computer", "algorithm", "variable", "function", "apple", "banana", "orange", "grape", "strawberry", "blueberry", "pineapple", "watermelon", "kiwi", "mango", "cat", "dog", "bird", "fish", "hamster", "rabbit", "turtle", "guinea pig", "ferret", "parrot",
"horse", "cow", "pig", "sheep", "goat", "chicken", "duck", "goose", "turkey", "rooster", "deer", "bear", "lion", "tiger", "elephant", "giraffe", "zebra", "hippopotamus", "rhinoceros", "kangaroo",
"koala", "panda", "monkey", "gorilla", "chimpanzee", "orangutan", "sloth", "bat", "fox", "wolf",
"seal", "walrus", "otter", "penguin", "dolphin", "whale", "shark", "octopus", "squid", "jellyfish",
"starfish", "crab", "lobster", "shrimp", "snail", "slug", "caterpillar", "butterfly", "bee", "ant",
"grasshopper", "cricket", "spider", "scorpion", "centipede", "millipede", "cockroach", "mosquito", "dragonfly", "ladybug",
"beetle", "moth", "fly", "wasp", "hornet", "lizard", "snake", "frog", "toad", "salamander",
"tortoise", "chameleon", "iguana", "crocodile", "alligator", "komodo dragon", "turtle", "gecko", "anaconda", "cobra",
"python", "viper", "mamba", "rattlesnake", "black mamba", "green anaconda", "king cobra", "diamondback", "boaconstrictor"
"peach", "pear", "plum", "cherry", "apricot", "lemon", "lime", "coconut", "pomegranate", "raspberry",
"blackberry", "cantaloupe", "nectarine", "fig", "cranberry", "dragonfruit", "guava", "passionfruit", "lychee",
"tangerine", "persimmon", "grapefruit", "papaya", "melon", "jackfruit", "kiwifruit", "avocado", "durian",
"breadfruit", "starfruit", "plantain", "cherimoya", "gooseberry", "boysenberry", "mulberry", "elderberry",
"rhubarb", "date", "currant", "aprium", "quince", "soursop", "kumquat", "ackee", "cloudberry", "loquat",
"tamarillo", "ugli fruit", "yuzu", "salak", "pawpaw", "horned melon", "feijoa", "rambutan", "jabuticaba",
"cupuacu", "soursop", "carambola", "mangosteen", "langsat", "longan", "sapodilla", "chayote", "custard apple",
"guanabana", "honeydew", "persimmon", "sugar apple", "breadnut", "tamarind", "tomato", "potato", "carrot",
"cucumber", "lettuce", "onion", "garlic", "broccoli", "cauliflower", "celery", "spinach", "kale",
"asparagus", "zucchini", "eggplant", "bell pepper", "beet", "radish", "turnip", "cabbage", "squash",
"chair", "table", "desk", "sofa", "bed", "wardrobe", "bookcase", "couch", "ottoman", "bench",
"stool", "shelf", "cabinet", "dresser", "mirror", "nightstand", "vanity", "futon", "armchair", "recliner",
"loveseat", "sectional", "chaise", "hutch", "buffet", "barstool", "rocking chair", "daybed", "beanbag", "trundle bed",
"murphy bed", "chest", "lounge chair", "pouf", "cot", "dining table", "coffee table", "end table", "console table", "accent table",
"sideboard", "tv stand", "entertainment center", "credenza", "dressing table", "settee", "kitchen island", "wine rack", "etagere", "vanity table",
"writing desk", "breakfast nook", "workbench", "computer desk", "gaming chair", "standing desk", "trestle table", "nesting tables", "picnic table", "bar table",
"camping chair", "adirondack chair", "swing chair", "sling chair", "zero gravity chair", "director's chair", "patio table", "lawn chair", "folding chair", "rocker",
"office chair", "swivel chair", "club chair", "wingback chair", "barrel chair", "papasan chair", "rocking bench", "chaise longue", "chesterfield", "chifforobe",
"poof", "poof chair", "deck chair", "sling chair", "saucer chair", "chase", "lawn chair", "butterfly chair", "hassock", "seat"};

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
