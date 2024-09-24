#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

int main() {
    // Seed the random number generator
    srand(time(NULL));
     
    bool playAgain = true;
    
    while (playAgain) {
        // Generate a new random number
        int answer = std::rand() % 100 + 1;
        int guess;
        bool correct = false;
        
        std::cout << "Guess a number between 1 and 100:\n";
        
        for (int i = 0; i < 10; i++) {
            std::cin >> guess;
            
            if (guess > answer) {
                std::cout << "Too high\n";
            } else if (guess < answer) {
                std::cout << "Too low\n";
            } else {
                std::cout << answer << " is correct!\n";
                correct = true;
                break;  // Exit the loop if the guess is correct
            }
            
            // Check if the player wants to reset the game after each guess
            if (i < 9) {  // Only ask if there are guesses left
                char yesno;
                std::cout << "Reset the game? (y/n)\n";
                std::cin >> yesno;

                if (yesno == 'y' || yesno == 'Y') {
                    correct = false; // Reset correct to allow for new game
                    break; // Exit the loop to restart the game
                } else if (yesno == 'n' || yesno == 'N') {
                    break; // Exit the guessing loop
                } else {
                    std::cout << "Invalid Input, continuing game.\n";
                }
            }
        }

        if (!correct) {
            std::cout << "Ran out of guesses or reset game. The correct number was " << answer << ".\n";
        }

        // Ask if the player wants to play again
        char playAgainInput;
        std::cout << "Play again? (y/n)\n";
        std::cin >> playAgainInput;
        playAgain = (playAgainInput == 'y' || playAgainInput == 'Y');
    }

    return 0;
}