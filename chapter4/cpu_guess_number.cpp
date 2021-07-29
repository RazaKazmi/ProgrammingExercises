/* This is a program where the computer will ask the user for a number between 
a number from 1-100. The cpu will then ask the user if their number is less then a certain value 
or not. After 7 questions the cpu will have guessed the number.

ch4_exercise_4
*/
#include <iostream>
#include "../include/common_utilities.h"

int main()
{
    std::cout << "Enter a whole number between 1-100 for the computer to guess after 7 questions: ";
    int input_number;
    std::cin >> input_number;

    int left = 0;
    int right = 100;
    int middle = right/2;
    char question_input = ' ';

    while((right - left)/2 > 0){        
        std::cout << "Is your number smaller than " << middle << '\n';
        std::cout << "y/n: ";
        std::cin >> question_input;

        if(question_input == 'y' || question_input == 'Y'){
            //right moves to middle
            right = middle;
            middle = left + ((right - left)/2);
        }
        else if(question_input == 'n' || question_input == 'N'){
            //left moves to middle
            left = middle;
            middle = left + ((right - left)/2);
        }
        else
            std::cout << "Please enter y or n";
    }
    int cpu_guess = middle;
    std::cout << "Your number is: " << cpu_guess << '\n';

    common_utility::KeepWindowOpen();
}