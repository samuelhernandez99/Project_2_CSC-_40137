
/* 
 * Word Jumble Game
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

namespace jumble 
{
    const string Words[7] = 
    {
        "programming", "computer", "software", "hardware",
        "semicolon", "coffee", "yogurt"
    };
    
    const string Hints[7] = 
    {
        "This is what software engineers do.",
        "This is made of a bunch of components in a case.",
        "This is a technical term for a program.",
        "These are the components that make up your computer.",
        "A type of punctuation mark.",
        "A caffeinated drink, popular in the morning.",
        "Bacterial fermentation of milk"
    };
}

class WordJumble
{
public:
    WordJumble();
    void JumbleWord(string& w);
    void Introduce();
    bool CheckGuess(string& g);
    bool Run();
    
    
private:
    int Tries;
    int Index;
    string Word;
    string JumbledWord;
    string Guess;
};


WordJumble::WordJumble()
:   Tries(0), Index(rand() %7), Word(jumble::Words[Index]),
        JumbledWord(""), Guess("")
{}

// Scramble Word
void WordJumble::JumbleWord(string& w)
{
    JumbledWord = w;
    int length = JumbledWord.size();
    
    for (int i = 0; i < length; i++)
    {
        int index1 = (rand() % length);
        int index2 = (rand() % length);
        
        char temp = JumbledWord[index1];
        JumbledWord[index1] = JumbledWord[index2];
        JumbledWord[index2] = temp;
    }
}

// Introduce Game
void WordJumble::Introduce()
{
    JumbleWord(Word);
    
    cout << "Welcome to Word Jumble!\n\n";
    cout << "Unscramble the letters to guess the word.\n";
    cout << "Input 'quit' to quit the game.\n\n";
    
    cout << "The jumbled word is: " << JumbledWord;
}


// Verify if Guess is correct
bool WordJumble::CheckGuess(string& g)
{
    ++Tries;
    
    if (g == "quit")
    {
        cout << "You have chosen to end the game.\n";
        cout << "Thank you for playing Word Jumble!";
        return true;
    }
    else if (g == Word)
    {
        cout << "Congratulations! You have guessed the word in " << Tries << " tries.\n";
        cout << "Thank you for playing Word Jumble!";
        return true;
    }
    else 
    {
        cout << "Sorry, that is the incorrect guess.";
        return false;
    }
}

bool WordJumble::Run()
{
    Introduce();
    
    while(true)
    {
        cout << "\n\nYour guess: ";
        cin >> Guess;
        
        if (CheckGuess(Guess))
        {
            return true;
        }
    }
}

int main(int argc, char** argv) 
{
    srand(static_cast<unsigned int>(time(0)));
    
    WordJumble myGame;
    myGame.Run();
    
    cin.ignore();
    cin.get();
    return 0;
}

