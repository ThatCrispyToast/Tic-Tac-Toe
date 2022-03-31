# Global Imports
import random # Should be "from random import choice", but variable name consistency and conflicts
from os import system

# Init Board as List Casted From String for Readability and Consistency
board = list("123456789")

"""Fetches and Validates User Input"""
def get_choice():
    # Get Player Input
    choice = input("Enter a position 1-9:\n")
    # Check if input is valid
    while True:
        if choice in board:
            # If valid, return choice
            return choice
        # If invalid, inform player and re-prompt
        print("Invalid Position.")
        choice = get_choice()

"""Prints and Styles the Board"""
def print_board():
    # Top Line
    print(" _____")
    # Rows
    print(f"|{board[0]}|{board[1]}|{board[2]}|")
    print(f"|{board[3]}|{board[4]}|{board[5]}|")
    print(f"|{board[6]}|{board[7]}|{board[8]}|")
    # Bottom Line
    print(" ‾‾‾‾‾")

"""Checks For a Win on the Board"""
def check_win():
    # Check Horizontal
    for i in range(0, 9, 3):
        if board[0 + i] == board[1 + i] == board[2 + i]:
            return True
    # Check Vertical
    for i in range(3):
        if board[0 + i] == board[3 + i] == board[6 + i]:
            return True
    # Check Diagonal
    if board[0] == board[4] == board[8] or board[2] == board[4] == board[6]:
        return True
    # Return False if no win
    return False

"""Main Function"""
def main():
    # Random Turn
    player = random.choice(["X", "O"])
    # Init Turn Count
    turn = 9
    # Main Game Loop
    while True:
        # Inform Player of Turn
        print(f"{player}'s turn!")
        # Draw Board
        print_board()
        # Get Player Input
        choice = get_choice()
        # Update Board
        board[int(choice) - 1] = player
        # Decrement Turn Count
        turn -= 1
        # Check for Win/Draw
        if check_win():
            # Clear Console, Inform Player of Win, Break Loop
            system("clear")
            print(f"{player} wins!")
            break
        elif turn < 1:
            # Clear Console, Inform Player of Draw, Break Loop
            system("clear")
            print("Draw!")
            break
        # Flip Player
        player = "X" if player == "O" else "O"
        # Clear Console Window
        system("clear")
    # Print Board
    print_board()
    # Inform User of Game End
    print("Game Over.")

# Inform Runner that main.py is the Main File and Only Run on Direct Invocation
if __name__ == "__main__":
    # Main Function
    main()