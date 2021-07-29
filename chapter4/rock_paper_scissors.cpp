/* This is a program for the game rock,paper,scissors.

The input is the user's guess and the output is a randomly
generated result between rock,paper, or scissors. 
*/
#include <iostream>
#include <random>
#include "../include/timer.h"
#include "../include/common_utilities.h"

//rock paper scissors game
enum class rpsGame{
    kRock=1,
    kPaper,
    kScissors
};

//Returns the int value of the rock,paper,scissors enum
static rpsGame IntToRpsGame(int x)
{
    if(x<int(rpsGame::kRock) || int(rpsGame::kScissors)<x)
        common_utility::Error("Bad rock, paper, scissors value");
    return rpsGame(x);
}

//Returns the string value of the rock,paper,scissors enum
static std::string RpsGameToString(rpsGame rps)
{
    switch (rps)
    {
    case rpsGame::kRock:
        return "rock";
        break;
    case rpsGame::kPaper:
        return "paper";
        break;
    case rpsGame::kScissors:
        return "scissors";
        break;
    }
    return nullptr;
}

//Checks if the user has won the game
static bool CheckUserWin(rpsGame user, rpsGame cpu)
{
    //User wins
    if(user == rpsGame::kRock && cpu == rpsGame::kScissors)
        return true;
    else if(user == rpsGame::kPaper && cpu == rpsGame::kRock)
        return true;
    else if(user == rpsGame::kScissors && cpu == rpsGame::kPaper)
        return true;  
    //Cpu wins    
    return false;
}

int main()
{
    using namespace common_utility;

    Print("Welcome to the rock, paper, scissors game!");
    Print("Please enter \"rock\", \"paper\", \"scissors\".");
    rpsGame user = rpsGame::kRock;

    //get users input
    std::string userInput;
    while(std::cin >> userInput)
    {
        if(userInput == "rock"){
            rpsGame user = rpsGame::kRock;
            break;
        }
        else if(userInput == "paper"){
            rpsGame user = rpsGame::kPaper;
            break;
        }
        else if(userInput == "scissors"){
            rpsGame user = rpsGame::kScissors;
            break;
        }
        else
            Print("Invalid input. Please enter \"rock\", \"paper\", \"scissors\".");
    }

    //generate cpus input
    rpsGame cpu = rpsGame::kRock;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1,3);

    cpu = IntToRpsGame(dist(mt));
    std::cout << "CPU: " << RpsGameToString(cpu) << '\n';

    //results of game
    if(user == cpu)
        Print("The game is a draw!");
    else
    {
        if(CheckUserWin(user,cpu))
            Print("You win!");
        else
            Print("CPU Wins!");
    }

    KeepWindowOpen();
    return 0;
}