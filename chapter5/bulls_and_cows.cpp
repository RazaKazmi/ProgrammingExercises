// A program for the guessing game bulls and cows
// Game Description:
// Bulls and cows is a game where a user guesses a number where each digit is unique.
// If they get the correct number and index they get a bull.
// If they get the correct number but wrong index they get a cow.
// The game ends when the user guesses the number correctly and gets all the bulls.

#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <unordered_map>
#include "../include/common_utilities.h"

static constexpr int kDigitNum = 4;

//generate a 4 digit number where each digit is unique
int GenerateNum()
{
    //TODO: generate unique digit number
    return 1234;
}

//print the instructions of the game
void PrintInstructions()
{
    std::cout << "Welcome to bulls and cows!\n";
    std::cout << "You have to guess the exact number as the cpu! The number is 4 digits and each digit is unique.\n";
    std::cout << "If you get a correct number in the correct place, you'll have a bull.\n";
    std::cout << "Otherwise if you get a correct number in the incorrect place, you'll have a cow.\n";
}

std::string GetUserInput()
{
    std::cout << "Enter your 4 unique digit number: ";
    int user_guess;
    std::cin >> user_guess;
    if(!std::cin)
        common_utility::Error("Invalid input entered");
    //TODO: Check validity of user input (Number is 4 digits, and each digit is unique)

    return std::to_string(user_guess);
}

//print the results of the game
void AnnounceResults(int bulls, int cows)
{
    std::cout << "You got: " <<  bulls << " bull and " << cows << " cow" << '\n';
    if(bulls == kDigitNum)
        common_utility::Print("You win!");
}

void BullsAndCows()
{
    std::string num = std::to_string(GenerateNum());
    int bull = 0, cow = 0;
    while(bull != kDigitNum){
        bull = 0;
        cow = 0;
        std::string user_guess = GetUserInput();
        //ASSERT num.length() == user_guess.length()
        std::unordered_map<char,int> umap;
        //place our number in to map for easy comparisons
        for (int i = 0; i < num.length();i++) {
            umap.insert({num[i],i});
        }
        //check for bulls and cows
        for (int i = 0; i < user_guess.length();i++) {
            //if guess is in the map
            if (umap.find(user_guess[i]) != umap.end()) {
                //if the index of the guess is the same as the maps
                if (umap[user_guess[i]] == i) {
                    bull++;
                } else {
                    cow++;
                }
            }
        }
        AnnounceResults(bull,cow);
    }
}

int main()
{
    try {
        //TODO: do while user wants to play again
        PrintInstructions();
        BullsAndCows();
    }
    catch(std::exception& e) {
        std::cerr << "error: " << e.what() << '\n';
        common_utility::KeepWindowOpen();
        return 1;
    }
    catch(...) {
        std::cerr << "Unknown exception!" << '\n';
        common_utility::KeepWindowOpen();
        return 2;
    }
}