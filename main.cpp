//
//  main.cpp
//  Hangman
//
//  Created by user on 26.09.2020.
//  Copyright © 2020 user. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

int main(int argc, const char * argv[]) {
    const int MAX_WRONG = 8;
    std::vector<std::string>words;
    words.push_back("WOLF");
    words.push_back("BEAR");
    words.push_back("TURTLE");
    words.push_back("OWL");
    words.push_back("PELICAN");
    words.push_back("TIGER");
    words.push_back("PINGUIN");
    words.push_back("OWL");
    
    srand(static_cast<unsigned int>(time(0)));
    random_shuffle(words.begin(),words.end());
    const std::string THE_WORD = words[0];
    int wrong = 0;
    std::string tooClose(THE_WORD.length(), '-');
    std::string opened = "";
    std::cout << "\t\tWelcome to HANGMAN!";
    
    while ((wrong < MAX_WRONG) && (tooClose != THE_WORD))
    {
        std::cout <<"\n\n\tYou have " << MAX_WRONG - wrong;
        std::cout <<" incorrect guesses!";
        std::cout <<"\n\n\tYou have used folowing letters:\n\t" << opened << std::endl;
        std::cout <<"\nTOO CLOSE! THE WORD IS:\n" << tooClose << std::endl;
        
        char guess;
        std::cout << "\n\nEnter your guess: ";
        std::cin >> guess;
        guess = toupper(guess);
        
        while (opened.find(guess) != std::string::npos)
        {
            std::cout << "\n\tYou've already guessed: " << guess << std::endl;
            std::cout << "\n\nEnter your guess: ";
            std::cin >> guess;
            guess = toupper(guess);
        }
        opened += guess;
        
        if (THE_WORD.find(guess) != std::string::npos)
        {
            std::cout << "\n\tThat's right! " << guess << " is in the word!";
            for (int i = 0; i < THE_WORD.size(); i++)
            {
                if(THE_WORD[i] == guess)
                {
                    tooClose[i] = guess;
                }
            }
        }
        else
        {
            std::cout << "\n\tSorry, " << guess << " isn't in teh word.";
            ++wrong;
        }
        
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
