#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

int main() {
    
    // Clears and creates new random number.
    srand(time(NULL));
    int answer = std::rand() % 100 + 1;
     
    int guess;
    bool correct = false;


    for (int i = 0; i < 10; i++) {
        std::cout << "Guess a number between 1 and 100:\n";
        std::cin >> guess;
        
        
        if (guess > answer) {
            std::cout << "To high\n";
            
        }
        
        else if (guess < answer) {
            std::cout << "To low\n";
        }
        
        else {
            std::cout << answer << " is correct!\n";
            correct = true;
            break;  // Exit the loop if the guess is correct

        }
    }
    
    
    if (!correct) {
    std::cout << "Ran out of guesses. The correct number was " << answer << ".\n";
    }

    return 0;
}