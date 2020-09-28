#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

int wrong = 0; //current times of wrong
const int MAX_WRONG = 8; // max times of wrons
std::string openedLetters = " "; //letters, that was used

//prototypes
void initGame(std::string opened, std::string tooClose);
char getGuess(std::string prompt, std::string opened);
std::string checkAndUpdateWord(std::string THE_WORD, std::string opened, std::string tooClose);

int myrandom (int i) { return std::rand() % i; }; // random generator

int main()
{
    std::vector<std::string> words; //initializing vector of words
    
    words.push_back("WOLF");
    words.push_back("BEAR");
    words.push_back("TURTLE");
    words.push_back("OWL");
    words.push_back("TIGER");
    words.push_back("PINGUIN");
    words.push_back("OWL");
    
    
    std::random_shuffle(words.begin(), words.end(), myrandom); //mix the elements of vector
    
    const std::string& THE_WORD = words[0]; // secret word
    std::string tooClose(THE_WORD.length(), '-'); //making the word secret
    
    std::cout << "\t\tWelcome to HANGMAN!";
    
    while ((wrong < MAX_WRONG) && (tooClose != THE_WORD)) //main game cycle
    {
        initGame(openedLetters, tooClose);
        
        tooClose = checkAndUpdateWord(THE_WORD, openedLetters, tooClose); // updating and opening letters
        
        if (wrong == MAX_WRONG)
        {
            std::cout << "\n\tYou have been hanged!";
        }
        else
        {
            std::cout << "\n\tYou guessed it!";
        }
    }
    
    std::cout << "\n\tThe word was " << THE_WORD << std::endl;
    return 0;
}

void initGame(std::string opened, std::string tooClose) //initializing game; show used letters, hidden word;
{
    std::cout <<"\n\n\tYou have " << MAX_WRONG - wrong;
    std::cout <<" incorrect guesses!";
    
    if (opened == " ")
    {
        std::cout <<"\n\n\tYou didn'n use any of letter :(" << std::endl;
        std::cout <<"\tTry to make a guess... :)" << std::endl;
    }
    else
    {
        std::cout <<"\n\n\tYou have used folowing letters:\n\t" << opened << std::endl;
    }
    std::cout <<"\nTOO CLOSE! THE WORD IS:\n" << tooClose << std::endl;
}

char getGuess(std::string prompt, std::string opened) //getting client input and checking it
{
    char guess;
    std::cout << prompt;
    std::cin >> guess;
    guess = toupper(guess);
    
    while (opened.find(guess) != std::string::npos)
    {
        std::cout << "\n\tYou've already guessed: " << guess << std::endl;
        std::cout << "\n\tTry another one :)";
        std::cout << "\n\nEnter your guess: ";
        std::cin >> guess;
        guess = toupper(guess);
    }
    openedLetters += guess;
    return guess;
}

std::string checkAndUpdateWord(std::string word, std::string opened, std::string tooClose)
{
    std::string open = opened;
    char guess = getGuess("\nEnter your guess: ", open); // getting a guess
    
    if (word.find(guess) != std::string::npos) //finding guess in hidden word
    {
        std::cout << "\n\tThat's right! " << guess << " is in the word!";
        for (int i = 0; i < word.size(); i++)
        {
            if(word[i] == guess) // show guessed letter in hidden word, if it finded
            {
                tooClose[i] = guess;
            }
        }
    }
    else
    {
        std::cout << "\n\tSorry, " << guess << " isn't in tht word.";
        ++wrong;
    }
    return tooClose;
}
