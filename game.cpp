#include <iostream>
#include "game.h"
#include <string>
#include "character.h"

using namespace std;

//Implement constructor functions
Game::Game()
{
    current_turn = 0;
    num_of_characters = 0;

    for (int i = 0; i < 2; i++)
    {
        players[i] = nullptr;
    }
}

/*A public function called "RemoveCharacter()" that takes an int index(0 - 1) of the character to be removed.
 *If the index is invalid (negative or more than # of characters), prints:
 *Invalid index!
 */
void Game::RemoveCharacter(int index)
{
    Character *tempChar;

    if ((index != 0) && (index != 1))
    {
        cout << "Invalid index!" << endl;
    }
    else
    {
        if (index == 0)
        {
            tempChar = players[1];
            players[1] = nullptr;
            players[0] = tempChar;

            tempChar = nullptr;
        }
        else
        {
            players[1] = nullptr;
        }

        num_of_characters--;
    }
}

/*A public function called "AddCharacter()" that takes a pointer of a Character and adds it to the players array.
 *If there are already two players, prints:
 *Character limit reached, please wait for the next game!
 */
void Game::AddCharacter(Character *c)
{
    if (num_of_characters == 2)
    {
        cout << "Character limit reached, please wait for the next game!" << endl;
    }
    else
    {
        players[num_of_characters] = c;
        num_of_characters++;
    }
}

/*A public void function called "NextTurn()".
 *First, it checks if there are two players in the game, if not then print:
 *Need more players!
 *
 *If there are enough players, it first calls the first player's Attack function, using the pointer to the second player as the input. 
 *Then it checks if the second player has negative health then prints:
 *Player one wins!
 *and exit.
 *If not, the function then calls the second player's Attack function, using the pointer to the first player as the input. 
 *Then it checks if the first player has negative health then prints:
 *Player two wins! 
 *and exit. 
 *If not then it returns to main function (the menu)
 */
void Game::NextTurn() 
{
    if (num_of_characters < 2)
    {
        cout << "Need more players!" << endl;
    }
    else
    {
        players[0]->Attack(players[1]);

        if (players[1]->getHealth() < 0)
        {
            cout << "Player one wins!" << endl;
            exit(0);
        }
        else
        {
            players[1]->Attack(players[0]);

            if (players[0]->getHealth() < 0)
            {
                cout << "Player two wins!" << endl;
                exit(0);
            }
        }
    }
}

//A public void function called "Print()" that calls each character in the player array's Print() function
void Game::Print() 
{
    for (int i = 0; i < num_of_characters; i++)
    {
        players[i]->Print();
    }
}

//Accessors for current turn and number of characters.
int Game::getCharacters() 
{ 
	return num_of_characters; 
}

int Game::getTurn() 
{ 
	return current_turn; 
}

