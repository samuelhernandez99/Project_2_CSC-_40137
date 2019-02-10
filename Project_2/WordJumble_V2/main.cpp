
/* 
 * Word Jumble Game
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

namespace jumble 
{
    
    // List of Easy Difficulty Words
    const string EasyWords[15] = 
    {
        "programming", "computer", "software", "hardware",
        "semicolon", "coffee", "yogurt", "bread", "music",
        "balloon", "mammal", "water", "correct", "snowflake",
        "number"
    };
    
    
    // Medium Difficulty Words
    const string MedWords[15] = 
    {
        "chocolate", "asthma", "island", "receipt", "february", 
        "knead", "colonel", "pronunciation", "recommend",
        "deductible", "division", "octagon", "grapefruit", 
        "nauseous", "gallon"
    };
    
    // Hard Difficulty Words
    const string HardWords[15] = 
    {
        "hydrogen", "electrolytes","hemoglobin","thermodynamics",
        "extraterrestrial","conscience","handkerchief", "rhythm",
        "pharaoh", "illusion", "chemist", "analytical", "extract",
        "absorption", "bazaar"
    };
    
    
    // Easy Hints
    const string EasyHints[15] = 
    {
        "This is what software engineers do.",
        "This is made of a bunch of components in a case.",
        "This is a technical term for a program.",
        "These are the components that make up your computer.",
        "A type of punctuation mark.",
        "A caffeinated drink, popular in the morning.",
        "Bacterial fermentation of milk.",
        "Baked flour and water.",
        "Art form made from sound, rhythm, and pitch.",
        "Flexible bag inflated with gas, such as helium.",
        "Animals constituting the class Mammalia.",
        "Transparent, tasteless, odorless, nearly colorless substance.",
        "Free from error.",
        "A flake of snow.",
        "A mathematical object used to count, measure, and also label."
    };
    
    
    // Medium Hints
    const string MedHints[15] = 
    {
        "Roasted and ground cacao seeds.", 
        "Condition which a person's airways become inflamed.",
        "Sub-continental land that is surrounded by water.",
        "Action of receiving something or the fact of its being received.",
        "Second month of the year in the Gregorian calendar.",
        "Work into dough or paste with the hands.",
        "Army officer of high rank.",
        "The way in which a word in pronounced.",
        "Put forwards with approval as being suitable for a particular purpose or role.",
        "Able to be deducted.",
        "Action of separating something into parts.",
        "Eight-sided polygon.",
        "Relatively large sour to semi-sweet, somewhat bitter fruit.",
        "Affected with nausea.",
        "Equal to 3.79 liters."
    };
    
    
    // Hard Hints
    const string HardHints[15] = 
    {
        "Atomic number 1.",
        "Produces electrically conducting solution when dissolved in a polar solvent.",
        "Iron-Containing oxygen-transport metalloprotein in red blood cells.",
        "Branch of Physics that has to do with heat.",
        "Of or from outside of earth or its atmosphere.",
        "Inner feeling or voice viewed as acting guide.",
        "Square of thin fabric or paper which can be carried in the pocket or handbag.",
        "Repeated pattern of movement or sound.",
        "Monarchs of ancient Egypt.",
        "Distortion of the senses.",
        "An expert in chemistry.",
        "Relating to our using analysis or logical reasoning.",
        "Remove or take out, especially by effort or force.",
        "Process or action by which one thing absorbs or is absorbed by another.",
        "Market in a Middle Eastern country."
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
    string WordEasy;
    string WordMed;
    string WordHard;
    string HintEasy;
    string HintMed;
    string HintHard;
    string JumbledWord;
    string Guess;
    string Difficulty;
};


WordJumble::WordJumble()
:   Tries(0), Index(rand() %15), WordEasy(jumble::EasyWords[Index]), WordMed(jumble::MedWords[Index]), WordHard(jumble::HardWords[Index]), HintEasy(jumble::EasyHints[Index]),
        HintMed(jumble::MedHints[Index]), HintHard(jumble::HardHints[Index]), JumbledWord(""), Guess(""), Difficulty("")
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
    
    cout << "Welcome to Word Jumble!\n\n";
    cout << "Unscramble the letters to guess the word.\n";
    cout << "Input 'hint' for a hint, but it will cost a try.\n";
    cout << "Input 'quit' to quit the game.\n\n";
    cout << "Select your difficulty (easy, med, hard): ";
    cin >> Difficulty;
    
    if (Difficulty == "easy") 
    {
        cout << "\nDifficulty set to easy\n\n";
        JumbleWord(WordEasy);
    }
    else if (Difficulty == "med") 
    {
        cout << "\nDifficulty set to medium\n\n";
        JumbleWord(WordMed);
    }
    else if (Difficulty == "hard")
    {
        cout << "\nDifficulty set to hard\n\n";
        JumbleWord(WordHard);
    }
    
    cout << "The jumbled word is: " << JumbledWord;
}


// Verify if Guess is correct
bool WordJumble::CheckGuess(string& g)
{
    ++Tries;
    
    
    // Easy Difficulty 
    
    if (Difficulty == "easy"){
        if (g == "hint")
        {
            cout << HintEasy;
            return false;
        }
        else if (g == "quit")
        {
            cout << "You have chosen to end the game.\n";
            cout << "Thank you for playing Word Jumble!";
            return true;
        }
        else if (g == WordEasy)
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
    
    
    // Medium Difficulty 
    
    else if (Difficulty == "med") 
    {
        if (g == "hint")
        {
            cout << HintMed;
            return false;
        }
        else if (g == "quit")
        {
            cout << "You have chosen to end the game.\n";
            cout << "Thank you for playing Word Jumble!";
            return true;
        }
        else if (g == WordMed)
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
    
    
    // Hard Difficulty 
    
    else if (Difficulty == "hard")
    {
        if (g == "hint")
        {
            cout << HintHard;
            return false;
        }
        else if (g == "quit")
        {
            cout << "You have chosen to end the game.\n";
            cout << "Thank you for playing Word Jumble!";
            return true;
        }
        else if (g == WordHard)
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

