#include <iostream>

bool gameLoop = true;
long numberToGuess = 0;
long guess = 0;

// Pure C++ does not have a clear screen, so I just write 20 new lines
void clearScreen(){
    for(int i = 0; i < 20; i ++){
        std::cout << std::endl;
    }
}

// Get the hint string based on how much away the answer is
std::string calculateGameHint(long input, long val){
    std::string output = "";
    long condition = abs(val-input);

    // Based on value of condition decide the Hint string
    if(condition < 3){
        output = "IT'S BURNING. VERY HOT!";
    }else if(condition < 5){
        output = "HOT";
    }else if(condition < 8){
        output = "COLD";
    }else{
        output = "ICE COLD";
    }

    return output;
}

int main() {
    // Main Game loop
    while(gameLoop){
        // Init the variables for another iteration
        numberToGuess = 0;
        guess = 0;

        // Get value from player one
        std::cout << "Player 1, enter the number that Player 2 will have to guess:";
        std::cin >> numberToGuess;

        //Clear Screen
        clearScreen();

        // Ask Player 2 to guess value
        std::cout << "Player 2, please guess the number" << std::endl;
        std::cin >> guess;

        // Loop while we get correct response
        while(guess != numberToGuess){
            std::cout << calculateGameHint(guess, numberToGuess) << std::endl << "Try again: ";
            std::cin >> guess;
            std::cout << std::endl;
        }

        // Break loop when the number match, so notify win and ask for a replay
        std::cout << "Congratulations! You won!" << std::endl << "Want to try again? (1) Yes (2) No:";
        std::cin >> guess;

        if(guess == 1){
            continue;
        }else{
            break;
        }
    }

    return 0;
}
