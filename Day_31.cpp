//=======================================================================================================
//                                                                                                      =
//............................Character manupulation....................................................=
//                                                                                                      =
//=======================================================================================================


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//......................................................................................
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//                      Game to find Random numbers
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//.......................................................................................
int fun() {

    // Generate a random number
    srand(time(0));  //// Seed the random number generator with the current time
    int secretNumber = rand() % 100 + 1;    // Generate a random number between 1 and 100


    // using the srand and rand functions from the <cstdlib> library
    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Guessing Game!" << std::endl;

    do {
        std::cout << "Enter your guess (1-100): ";
        std::cin >> guess;

        attempts++;

        if (guess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        }
        else if (guess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        }
        else {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts." << std::endl;
        }
    } while (guess != secretNumber);

    return 0;
}

//......................................................................................
//''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
//                      Game "Dungeon Dash"
//,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//.......................................................................................

// Function to generate a random number within a given range
int generateRandomNumber(int min, int max) {
    static bool initialized = false;
    if (!initialized) {
        srand(time(0));
        initialized = true;
    }
    return min + rand() % (max - min + 1);
}

int main() {
    int playerHealth = 100;
    int enemyHealth = 100;
    int playerAttack;
    int enemyAttack;

    cout << "Welcome to Dungeon Dash!" << endl;

    while (playerHealth > 0 && enemyHealth > 0) {
        cout << "Player Health: " << playerHealth << endl;
        cout << "Enemy Health: " << enemyHealth << endl;

        // Player's turn
        cout << "Enter your attack power (1-10): ";
        cin >> playerAttack;

        // Enemy's turn
        enemyAttack = generateRandomNumber(1, 10);

        // Update health
        playerHealth -= enemyAttack;
        enemyHealth -= playerAttack;

        cout << "Player attacked with power " << playerAttack << endl;
        cout << "Enemy attacked with power " << enemyAttack << endl;
        cout << endl;
    }

    // Determine the winner
    if (playerHealth <= 0 && enemyHealth <= 0) {
        cout << "It's a tie!" << endl;
    }
    else if (playerHealth <= 0) {
        cout << "You lost!" << endl;
    }
    else {
        cout << "Congratulations! You won!" << endl;
    }

    return 0;
}


/*

This code defines a simple single-player combat game called "Dungeon Dash". Here's a breakdown of the steps:

1. Includes and Declarations:

The code includes necessary libraries for input/output (iostream), random number generation (cstdlib, ctime), and namespace access (std).
A function generateRandomNumber is declared to generate a random number within a specified range.
2. generateRandomNumber function:

This function checks if the random number generator has been initialized (initialized) using srand with the current time as the seed.
If not, it sets the seed and marks initialized as true.
It then generates a random number between min and max using the formula min + rand() % (max - min + 1).
3. Main function:

Player and enemy health are initialized to 100. Variables for player and enemy attack are declared.
A welcome message is printed.
4. Game loop:

While both player and enemy have health remaining, the following steps are repeated:
Player health and enemy health are printed.
Player is prompted to enter their attack power between 1 and 10.
Enemy attack is generated using the generateRandomNumber function with a range of 1 to 10.
Both player and enemy health are updated based on the attacks.
Each attack power is printed.
5. Winner determination:

After the loop exits, the winner is determined:
If both player and enemy health are 0, it's a tie.
If player health is 0, the player loses.
Otherwise, the player wins.
6. Game ends:

Depending on the winner, a victory or defeat message is printed.
The program returns 0, indicating successful execution.
Summary:

This code implements a basic combat game where players battle an enemy by entering their attack power. The enemy's attack is generated randomly. Each round, both player and enemy health are updated based on the attacks. The loop continues until one character's health reaches 0 or both reach 0 simultaneously.

This is a good starting point for a simple combat game, but it can be extended in many ways:

Implement different levels with increasing difficulty.
Add more enemy types with unique attacks.
Introduce character customization with weapon or magic upgrades.
Expand the story and world elements for a more immersive experience.


*/