#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global Variables
char board[10] = "123456789";
char player;
int errcount = 0;

// Declare Functions
void printboard();
int getnum();
int checkwin();

/* Main Function */
int main(void) {
    // Generate Random Turn
    // Seed Random
    srand(time(NULL));
    // Assign Turn Based on Random Num [0, 1]
    if (rand() % 2) {
        player = 'X';
    }
    else {
        player = 'O';
    }
    // Init Turn Count
    int turn = 9;
    // Loop While Board Has Empty Spaces (Counted w/ "turn")
    while (1) {
        // Inform Player of Turn
        printf("%c's Turn.\n", player);
        // Print Board
        printboard();
        // Get Player Choice
        int choice = getnum();
        // Assign Choice to Board
        board[choice] = player;
        // Decrement Turn
        turn--;
        // Check if Board Has Win/Draw
        if (checkwin()) {
            // Clear Console, Inform Player of Win, and Break Loop
            system("clear");
            printf("%c Wins!\n", player);
            break;
        }
        else if (turn < 1) {
            // Clear Console, Inform Player of Draw, and Break Loop
            system("clear");
            printf("Draw!\n");
            break;
        }
        // Flip Player
        if (player == 'X') {
            player = 'O';
        }
        else {
            player = 'X';
        }
        // Clear Console
        system("clear");
    }
    // Print Board
    printboard();
    // Inform Player of Game End
    printf("Game Over!\n");
}

/* Checks For a Win on the Board */
int checkwin() {
    // Check Horizontal
    for (int i = 0; i < 9; i += 3) {
        if (board[0 + i] == board[1 + i] && board[1 + i] == board[2 + i]) {
            return 1;
        }
    }
    // Check Vertical
    for (int i = 0; i < 3; i++) {
        if (board[0 + i] == board[3 + i] && board[3 + i] == board[6 + i]) {
            return 1;
        }
    }
    // Check Diagonal
    if ((board[0] == board[4] && board[4] == board[8]) || (board[2] == board[4] && board[4] == board[6])) {
        return 1;
    }
    // Return 0 if No Win on Board
    return 0;
}

/* Prints and Styles the Board */
void printboard() {
    // Init printline boolean
    int printline = 0;
    // Draw Top Line
    printf(" _____\n");
    // Draw Inital Vertical Line
    printf("|");
    // Draw Main Board
    for (int i = 0; i < 9; i++) {
        // Check for Designated Board Break
        if (i % 3 == 0 && i != 0) {
            // Break Board and Add Line
            printf("\n|");
            printline = 0;
        }
        else {
            printline = 1;
        }
        // Print Current Board Item
        printf("%c|", board[i]);
    }
    // Draw Bottom Line
    printf("\n ‾‾‾‾‾\n");
}

/* Fetch and Validate User Input */
int getnum() {
    // Init Choice
    int choice;
    // User Prompt
    printf("Enter a position 1-9:\n");
    // Get User Input
    scanf("%d", &choice);
    // Convert Input to Board Position
    choice--;
    // Check if A Character/String was Input
    if (errcount > 100) {
        system("clear");
        printf("-------------------\nCharacter Input Error\n-------------------\n");
        exit(80085);
    }
    // Check for Input Validity
    if (choice > 8 || choice < 0 || board[choice] == 'X' || board[choice] == 'O') {
        // Inform User of Invalid Input and Recursively Call Function
        errcount++;
        printf("Invalid Position.\n");
        getnum();
        return;
    }
    // Return Valid Position Value
    return choice;
}