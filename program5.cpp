/*-----------------------------------------------------------------------------
 * 1024 and More
 * CS 141 Spring 2014
 *
 * Allison Channic
 * Lab time: Thurs. 12:00
 * System: Windows 8, written in Codewriter, compiled with Visual Studio
 *-----------------------------------------------------------------------------
 *
 * 1024 and More
 *
 * This program is based off of the game 2048 by Gabrielle Cirulli, found at
 * bit.ly/great2048. The goal of the game is to combine like tiles on a square
 * game board to create a winning number. When the program first runs, the user
 * is asked what size game board he/she would like between a size of 4 and 12.
 * The winning number is then determined by the board size, where the base case
 * is a size 4x4 board having a winning number of 1024. For each increment to
 * the size of the board, the winning number doubles. The game board is then
 * printed and two random values, 2 or 4, are placed on random positions on the
 * board. The user must then move these tiles either up, left, down, or right
 * by pressing w, a, s, or d respectively. When the user chooses what direction
 * to move the tiles, all tiles move in that direction until they reach the edge
 * of the board. After each move, another random value, 2 or 4, is placed on a
 * random open tile on the board. The user can combine tiles of the same value
 * that are next to each other by choosing the corresponding direction (up or
 * down for tiles on top of another, left or right for tiles next to each
 * other). The user must repeat this process until the winning number appears
 * on the board. The user may also place a tile of any value at any valid tile
 * by entering "p 1 2" where the 1 corresponds to the tile position and the 2
 * represents the value to be placed. The user loses the game if there are no
 * more empty tiles and no tiles of the same value are next to each other.
 *
 * Running the program looks like this:
 * 
 * Allison Channic
 * UIC CS 141, Spring 2014
 * Welcome to 1024 and more.
 * This program is based off of Gabriele Cirulli's game online at:
 * bit.ly/great2048
 * 
 * For each move enter a direction as a letter key, as follows:
 *  W
 * A S D
 * where A=left,W=up, D=right and S=down.
 * 
 * After a move, when two identical valued tiles come together they
 * join to become a new single tile with the value of the sum of the
 * two originals. This value gets added to the score. On each move
 * one new randomly chosen value of 2 or 4 is placed in a random open
 * square. User input of r restarts the game, and x exits the game.
 * 
 * Enter the board size you want, between 4 and 12: 4 [user input]
 * Game ends when you reach 1024 [corresponding winning number]
 * 
 * .  .  .  .
 * .  .  .  .
 * 2  .  .  2
 * .  .  .  .
 *
 * Score: 0
 * 
 * 1.) Your move: w
 * 
 * [SCREEN IS CLEARED]
 *
 * 2  .  .  2
 * .  .  .  .
 * .  .  .  .
 * .  .  .  2
 *
 * Score: 0
 *
 * 2.) Your move: a
 * 
 * [SCREEN IS CLEARED]
 * 
 * 4  .  .  .
 * .  .  .  .
 * .  .  .  .
 * 2  .  .  4
 *
 * etc.
 */
 
//Include necessary C/C++ libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <ctype.h>
using namespace std;
 
 
/*Function to print header and game instructions
  Takes no paramters and does not return anything
  Prints the game controls, rules, and instructions to the user, the name
  and lab time of the author, and necessary credits to the user
*/
void printInstructions()
{
 	//Print project header with name and lab time
 	printf("\nAllison Channic\n");
	printf("UIC CS 141, Spring 2014\n");
	
	//Welcome user to the game and credit the original author of the game
	printf("Welcome to 1024 and more.\n");
	printf("This program is based off of Gabriele Cirulli's game online at:\n");
	printf("bit.ly/great2048\n\n");
	
	//Print game controls
	printf("For each move enter a direction as a letter key, as follows:\n");
	printf("  W\n");
	printf("A S D\n");
	printf("where A=left,W=up, D=right and S=down.\n\n");
	
	//Print game instructions, rules, and win conditions
	printf("After a move, when two identical valued tiles come together they\n");
	printf("join to become a new single tile with the value of the sum of the\n");
	printf("two originals. This value gets added to the score. On each move\n");
	printf("one new randomly chosen value of 2 or 4 is placed in a random open\n");
	printf("square. User input of r restarts the game, and x exits the game.");
}


/*Function to get the board size
  Takes no parameters
  Gets the size of the game board, between 4 - 12 from user input
  Returns the size of the board as an int
*/
int getBoardSize()
{
	//Variable for the size of the board
	int boardSize;
	
	//Prompt the user for the board size they want and set it to the variable
	printf("\n\nEnter the board size you want, between 4 and 12: ");
	scanf("%d", &boardSize);
	
	//Return the board size the user entered
	return boardSize;
}


/*Function to get the winning number of the game
  Takes the size of the board as an int as its parameter
  The winning number is dependent on the board size
  If the board size is 4, the winning number is 1024. For each increment to
  the board size up to 12, the winning number is doubled (2048 for a size 5
  board, 4096 for a size 6 board, etc.)
  Determines the winnin number for the board using a switch statement
  Returns the winnign number as an integer
*/
int getWinNum(int boardSize)
{
	//Variable for the winning number
	int winNum = 0;
	
	//Switch case to determine the winning number based on the board size
	switch(boardSize)
	{
		//Board size 4, winning number 1024
		case 4:
			winNum = 1024;
			break;
		//Board size 5, winning number 2048	
		case 5:
			winNum = 2048;
			break;
		//Board size 6, winning number 4096	
		case 6:
			winNum = 4096;
			break;
		//Board size 7, winning number 8192
		case 7:
			winNum = 8192;
			break;
		//Board size 8, winning number 16384	
		case 8:
			winNum = 16384;
			break;
		//Board size 9, winning number 32768	
		case 9:
			winNum = 32768;
			break;
		//Board size 10, winning number 65536	
		case 10:
			winNum = 65536;
			break;
		//Board size 11, winning number 131072	
		case 11:
			winNum = 131072;
			break;
		//Board size 12, winning number 262144	
		case 12:
			winNum = 262144;
			break;
		//Any other board size is invalid	
		default:
			break;
	}
	
	//Return the winning number
	return winNum;
}


/*Function to get the tile position that contains the newly generated 2 or 4
  Takes a pointer to the board array and the number of tiles it contains as
  Integer parameters
  Generates a random number between 0 and the number of tiles minus 1
  Checks that the tile at that position is empty, represented by a value of 1
  If the tile is empty, that tile becomes the new position for the random number
  Returns the tile position as an integer
*/
int getRandomTilePos(int *&boardArray, int numTiles)
{
	//Ensure values are different each time program is run
	srand((int) time(0));
	
	//Variable for the tile to have a 2 or 4
	int randomPos = rand() % numTiles;
	
	//Check that the tile is open, if not, reset the random position
	while (boardArray[randomPos] != 0)
		randomPos = rand() % numTiles;
	
	//Return the tile that will receive the newly generated random number
	return randomPos;
}


/*Function to place a 2 or a 4 on a random tile on the board
  Takes a pointer to the board array, and the number of tiles as integer parameters
  Gets the tile to hold the new number by calling the getRandomTilePos()
  function
  Random generator chooses a number between 0 - 4. If the number is a 0, 1, or
  3, the number is set to a 2 to represent a 2 being placed more frequently than a 4
  Takes that randomly chosen number and places it on the tile
*/
void setRandomTile(int *&boardArray, int numTiles)
{
	//Ensure values are different each time program is run
	srand((int) time(0));
	
	//Get the tile to be changed by calling getRandomTilePos()
	int randomPos = getRandomTilePos(boardArray, numTiles);
	
	//Variable for the value to be added to that tile
	//Goes from 0 - 5
	int randomValue = rand() % 5;
	
	//If the value generated is a 0, 1, or 3, it is set to 2 to represent 
	//the odds of 2 being more frequent than 4
	if (randomValue == 0 || randomValue == 1 || randomValue == 3)
		randomValue = 2;
	
	//Set the tile to the randomly generated value
	boardArray[randomPos] = randomValue;
}


/* Function to initialize the board at the very beginning of the game
   Takes a pointer to the board array and the number of tiles as integer parameters
   Sets all of the values in the array to 1 to represent all open tiles
   calls the setRandomTile() function twice to place two numbers (2 or 4)
   to two random positions on the board
*/
void initializeBoard(int *&boardArray, int numTiles)
{
	//Ensure numbers chosen and their positions are different each time the
	//program runs
	srand((int) time(0));
	
	//For loop to initialize all of the values in the board to 1
	//Represents blank tiles
	int i; 
	for (i = 0; i < numTiles; i++)
		boardArray[i] = 0;
	
	//Place two random numbers (2 or 4) on two random positions on the board
	setRandomTile(boardArray, numTiles);
	setRandomTile(boardArray, numTiles);
}


/*Function to print the board
  Takes a pointer to the board array and the size of the board as integer parameters
  Prints the array in game board format by printing new lines at the end of 
  every row, spaces between tiles, and the '.' character for empty tiles
  represented by the value 1
*/
void printBoard(int *&boardArray, int boardSize)
{
	//Get the number of tiles by multiplying boardSize by itself
	int numTiles = boardSize * boardSize;
	
	char period = '.';
	
	//Loop to print the entire board array
	int i;
	for (i = 0; i < numTiles; i++)
	{
		//Print a new line at the end of every row
		if(i % boardSize == 0)
        	printf("\n\n");
		//Print a space after each tile	
        else
           	printf(" ");
			
		//Print a '.' for blank tiles, represented by a value of 1	
		if (boardArray[i] == 0)
			printf("%5c", period);
		//Print all other numbers that aren't a 1	
		else
			printf("%5d", boardArray[i]);
	}
}


/*Function to see if the user has entered a valid direction
*/
bool checkValidDirection(char direction)
{
	//Change the direction to uppercase to make user input irrelevent
	direction = toupper(direction);
	
	//Boolean variable to represent if the direction is valid or not
	bool validDirection;
	
	//Check that the direction entered is valid
	//Valid directions: W, A, S, D, P, and R
	if (direction != 'W' && direction != 'A' && direction != 'S' && 
		direction != 'D' && direction != 'P' && direction != 'R')
		validDirection = false;
	
	else
		validDirection = true;
	
	//Return if the direction is valid or not
	return validDirection;	
}


/* Function to move the tiles up
   Takes a pointer to the board array and the board size as integer parameters
   Gets the location of each tile based on its row and column
   Checks that the tile above it is empty represented by a value of 0 in the
   array. If it is, the blank tile becomes the value of the tile that was moved
   up. Process repeats until there are no more open spaces above that tile.
*/
void slideUp(int *&boardArray, int boardSize)
{
	//Variables to represent the row and column of each tile
	int row;
	int column;
	
	//Go through the number of columns in the board
	for (column = 0; column < boardSize; column++)
	{
		//Go through the number of rows in the board except the top one
		for (row = boardSize-1; row >= 1; row--)
		{
			//Access the current location
			int current = row*boardSize + column;
			
			//Check that the current location isn't a blank tile
			if(boardArray[current] != 0)
			{
				//Check that the tile above the current is blank and not at the top edge of the board
				while((boardArray[current - boardSize] == 0) && (row != 0))
				{
					//Swap values between the current tile and the one above it
					boardArray[current-boardSize] = boardArray[current];
					boardArray[current] = 0;
					//Look at the next tile
					current--;
				}
			}
		}
	}
}


/* Function to move the tiles to the left
   Takes a pointer to the board array and the board size as integer parameters
   Gets the location of each tile based on its row and column
   Checks that the tile left of it is empty represented by a value of 0 in the
   array. If it is, the blank tile becomes the value of the tile that was moved
   up. Process repeats until there are no more open spaces left of that tile.
*/
void slideLeft(int *&boardArray, int boardSize)
{
	//Variables to represent the row and column of a tile
	int row;
	int column;
	
	//Go through the number of rows in the board
	for (row = 0; row < boardSize; row++)
	{
		//Go through the number of columns in the board except the far left one
		for (column = 1; column < boardSize; column++)
		{
			//Access the current tile
			int current = row*boardSize + column;
			
			//Check that the current tile isn't blank
			if(boardArray[current] != 0)
			{
				//Check that the tile to the left of the current tile is blank and
				//not at the edge of the board
				while((boardArray[current-1] == 0) && ((current % boardSize) != 0))
				{
					//Swap values between the current tile and the one next to it
					boardArray[current-1] = boardArray[current];
					boardArray[current] = 0;
					//Go to the next tile
					current--;
				}
			}
		}
	}
}


/* Function to move the tiles down
   Takes a pointer to the board array and the board size as integer parameters
   Gets the location of each tile based on its row and column
   Checks that the tile below it is empty represented by a value of 0 in the
   array. If it is, the blank tile becomes the value of the tile that was moved
   up. Process repeats until there are no more open spaces below that tile.
*/
void slideDown(int *&boardArray, int boardSize)
{
	//Variables to represent the row and column of each tile
	int row;
	int column;
	
	//Go through the number of columns on the board
	for (column = 0; column < boardSize; column++)
	{
		//Go through the number of rows on the board except the bottom one
		for (row = 0; row < boardSize-1; row++)
		{
			//Access the current tile
			int current = row*boardSize + column;
			
			//Check that the current tile isn't blank
			if(boardArray[current] != 0)
			{
				//Check that the tile below the current tile is blank and not at the bottom edge
				while(boardArray[current+boardSize] == 0 && (row != boardSize - 1))
				{
					//Swap values between the current tile and the one below it
					boardArray[current+boardSize] = boardArray[current];
					boardArray[current] = 0;
					//Go to the next tile
					current++;
				}
			}
		}
	}	
}


/* Function to move the tiles to the right
   Takes a pointer to the board array and the board size as integer parameters
   Gets the location of each tile based on its row and column
   Checks that the tile to the right of it is empty represented by a value of 0 in the
   array. If it is, the blank tile becomes the value of the tile that was moved
   up. Process repeats until there are no more open spaces to the right of that tile.
*/
void slideRight(int *&boardArray, int boardSize)
{
	//Variables to represent the row and column of each tile
	int row;
	int column;
	
	//Go through the number of rows in the board
	for (row = 0; row < boardSize; row++)
	{
		//Go through the number of columns in the board except the right most one
		for (column = boardSize - 2; column >= 0; column--)
		{
			//Access the current tile
			int current = row*boardSize + column;
			
			//Check that the current tile isn't blank
			if(boardArray[current] != 0)
			{
				//Check that the tile next to the current one is blank and isn't on the right
				//most edge
				while(boardArray[current+1] == 0 && ((current + 1) % boardSize != 0))
				{
					//Swap values between the current tile and the one to the right of it
					boardArray[current+1] = boardArray[current];
					boardArray[current] = 0;
					//Go to the next tile
					current++;
				}
			}
		}
	}
}


/* Function to merge tiles upwards
   Takes a pointer to the board array and the size of the board as integer
   parameters
   Goes through all of the elements in the arrayand sees if the one above it is
   the same. If so, set the one above it to twice its original value
   Updates the score to the value of whatever tiles were created after merging
   Returns the score as an integer
*/
int mergeUp(int *&boardArray, int boardSize)
{
	//Variables to represent the row and column of each tile
	int row;
	int column;
	
	//Variable for the new value when the tiles merge
	int newValue;
	
	//Variable to keep track of score
	int score = 0;
	
	//Go through the number of columns in the board
	for (column = 0; column < boardSize; column++)
	{
		//Go through the number of rows in the board
		for (row = boardSize - 1; row >= 0; row--)
		{
			//Access the current tile
			int current = row*boardSize + column;
			
			//Check that the tiles have the same value and aren't blank
			if (boardArray[current] == boardArray[current-boardSize] && (boardArray[current] != 0))
			{
				//New value is twice the value of the tiles being merged
				newValue = 2*boardArray[current];
				//Update score
				score += newValue;
				//Merge tiles
				boardArray[current- boardSize] = newValue;
				boardArray[current] = 0;
			}	
		}	
	}
	
	//Slide up after merging
	slideUp(boardArray, boardSize);
	
	//Return the score after merging tiles
	return score;
	
}


/* Function to merge tiles to the left
   Takes a pointer to the board array and the size of the board as integer
   parameters
   Goes through all of the elements in the array and sees if the one to the
   left of it is the same. If so, set the one above it to twice its original value
   Updates the score to the value of whatever tiles were created after merging
   Returns the score as an integer
*/
int mergeLeft(int *&boardArray, int boardSize)
{
	//Variables to represent the number of rows and columns in the board
	int row;
	int column;
	
	//Variable to represent the new value after the tiles merge
	int newValue;
	
	//Variable to keep track of the score
	int score = 0;
	
	//Go through the number of rows in the board
	for (row = 0; row < boardSize; row++)
	{
		//Go through the number of columns in the board
		for (column = 1; column < boardSize; column++)
		{
			//Access the current tile
			int current = row*boardSize + column;
			
			//Check that the two tiles are equal to each other, not blank, and not going to go past the edge of the board
			if ((boardArray[current] == boardArray[current-1]) && (boardArray[current] != 0) && (current % boardSize != 0))
			{
				//New value is twice the value of the tiles being merged
				newValue = 2*boardArray[current];
				//Update score
				score += newValue;
				//Merge tiles
				boardArray[current-1] = newValue;
				boardArray[current] = 0;
			}	
		}	
	}
	
	//Slide tiles after merging
	slideLeft(boardArray, boardSize);
	
	//Return the score after merging tiles
	return score;
}


/* Function to merge tiles upwards
   Takes a pointer to the board array and the size of the board as integer
   parameters
   Goes through all of the elements in the array and sees if the one below it is
   the same. If so, set the one above it to twice its original value
   Updates the score to the value of whatever tiles were created after merging
   Returns the score as an integer
*/
int mergeDown(int *&boardArray, int boardSize)
{
	//Variables to represent the number of rows and columns in the board
	int row;
	int column;
	
	//Variable to represent the new value after the tiles merge
	int newValue;
	
	//Variable to keep track of score
	int score = 0;
	
	//Go through the number of columns in the board
	for (column = 0; column < boardSize; column++)
	{
		//Go through the number of rows in the board
		for (row = 0; row < boardSize; row++)
		{
			//Access the current tile
			int current = row*boardSize + column;
			
			//Check that the tiles are equal to each other and not blank
			if (boardArray[current] == boardArray[current+boardSize] && (boardArray[current] != 0))
			{
				//New value is twice the value of the tiles being merged
				newValue = 2*boardArray[current];
				//Update score
				score += newValue;
				//Merge tiles
				boardArray[current+boardSize] = newValue;
				boardArray[current] = 0;
			}	
		}	
	}
	
	//Slide tiles
	slideDown(boardArray, boardSize);
	
	//Return the score after merging tiles
	return score;
}


/* Function to merge tiles upwards
   Takes a pointer to the board array and the size of the board as integer
   parameters
   Goes through all of the elements in the array and sees if the one to the
   right of it is the same. If so, set the one above it to twice its original value
   Updates the score to the value of whatever tiles were created after merging
   Returns the score as an integer
*/
int mergeRight(int *&boardArray, int boardSize)
{
	//Variables to represent the number of rows and columns in the board
	int row;
	int column;
	
	//Variable to represent the new value after the tiles are merged
	int newValue;
	
	//Variable to keep track of the score
	int score = 0;
	
	//Go through the number of rows in the board
	for (row = 0; row < boardSize; row++)
	{
		//Go through the number of columns in the board
		for (column = boardSize - 2; column >= 0; column--)
		{
			//Access the current tile
			int current = row*boardSize + column;
			
			//Check that the tiles are equal to each other, not blank, and aren't going to go off the edge of the board
			if ((boardArray[current] == boardArray[current+1]) && (boardArray[current] != 0) && ((current+1) % boardSize != 0))
			{
				//New value is twice the value of the tiles being merged
				newValue = 2*boardArray[current];
				//Update score
				score += newValue;
				//Merge tiles
				boardArray[current+1] = newValue;
				boardArray[current] = 0;
			}	
		}	
	}
	//Slide tiles
	slideRight(boardArray, boardSize);
	
	//Return the score after merging tiles
	return score;
}


/* Function to see if the user has won
   Takes a pointer to the board array and the size of the board as integer parameters
   User has won if the winning number, determined by the size of the board
   appears somewhere on the board
   Returns whether the user has won or not as a boolean variable
*/
bool checkWin(int *&boardArray, int boardSize)
{
	//Get the number of tiles int the array
	int numTiles = boardSize*boardSize;
	
	//Boolean variable to represent if the user has won or not
	bool hasWon = false;
	
	//Get the winning number based on the board size
	int winNum = getWinNum(boardSize);
	
	//Go through the board array and see if any of the tiles contains the winning number
	int i;
	for (i = 0; i < numTiles; i++)
	{
		//If a tile contains the winning number, the user has won
		if (boardArray[i] == winNum)
			hasWon = true;
	}
	
	//Return if the user has won or not
	return hasWon;
}

/* Function to see if the board is unplayable
   Takes a pointer to the board array and the board size as integer parameters
   A board is unplayable if there are no blank tiles and no tiles of the same
   value are next to each other
   Goes through the board array and determines if these two pieces of
   information are true
   Returns if the board is unplayable as a boolean variable
*/
bool checkUnplayable(int *&boardArray, int boardSize)
{
	//Get the number of tiles
	int numTiles = boardSize*boardSize;
	
	//Boolean variable to represent if a board is unplayable
	bool unplayable = false;
	
	//Variable to represent the number of blank tiles
	int blankAccum = 0;
	
	//Go through the board array and count the number of blank tiles
	int i;
	for (i = 0; i < numTiles; i++)
	{
		if (boardArray[i] == 0)
			blankAccum++;
	}
	
	//If there are no blank tiles on the board, check that two tiles of the same
	//Value are next to each other or not
	if (blankAccum == 0)
	{
		for (i = 0; i < numTiles; i++)
		{
			//Check if two tiles left or right of each other are the same
			if (boardArray[i] == boardArray[i+1] && ((i + 1) % boardSize != 0))
				break;
			//Check if two tiles above or below each other are the same	
			else if (boardArray[i] == boardArray[i+boardSize])
				break;
			//If no tiles of the same value are next to each other, board is unplayable	
			else
				unplayable = true;
		}
	}
	
	//Return if the board is playable or not
	return unplayable;	
}


/* Function to allow the user to place a tile of his/her choice on the board
   Takes a pointer to the board array, the number of tiles, the tile to contain
   the desired value, and the desired value as integer parameters
   Checks that the tile to contain the new value exists on the board
   If so, put the value on that tile. If not, print an error message
*/
void placeTile(int *&boardArray, int numTiles, int tilePos, int tileValue)
{
	//Check that the tile position exists on the boar
	//If not, print an error message
	if (tilePos > numTiles)
		printf("ERROR: Tile does not exist for this size board.");
		
	//If so, put the specified tile value at the specified tile
	else
		boardArray[tilePos] = tileValue;
}

 
//Main method
int main()
{
	//Ensure randomly generated numbers are different each time the program runs
	srand((int) time(0));
	
	//Print the game instructions to the user
	printInstructions();
	
	//Get the size of the game board
	int boardSize = getBoardSize();
	
	//Check that the size of the game board is between 4 and 12
	//Continue to prompt the user until they enter a board size between 4 - 12
	while (boardSize < 4 || boardSize > 12)
	{
		printf("ERROR: Invalid board size. Please try again.");
		boardSize = getBoardSize();
	}
	
	//Variable for the winning number
	int winNum = getWinNum(boardSize);
	
	//Tell the user what the winning number is
	printf("\nGame ends when you reach %d", winNum);
	
	//Variable for the number of game tiles
	int numTiles = boardSize*boardSize;
	
	//Allocate memory for the array to represent the game board
	//Based on the number of tiles
	int *boardArray = new (int[numTiles+1]);
	
	//Initialize the game board and print it to the user
	initializeBoard(boardArray, numTiles);
	printf("\n");
	printBoard(boardArray, boardSize);
	
	//Variable to represent the number of moves
	int numMoves = 1;
	
	//Char variable for the direction the tiles should move
	char direction;
	
	//Boolean variable to see if the direction entered was valid or not
	bool validDirection;
	
	//Boolean variable to see if the user has won
	bool hasWon = false;
	
	//Boolean variable to see if the board is unplayable
	bool unplayable = false;
	
	//Variable to keep track of score
	int score = 0;
	
	//do-while loop to go through main gameplay
	do
	{
		//Let the user know what the score is, how many moves he or she has made,
		//and get the direction they'd like to move the tiles
		printf("\n\n");
		printf("Score: %d\n\n", score);
		printf("%d.) Your move: ", numMoves);
		scanf(" %c", &direction);
		
		//Make the direction uppercase to make case irrelevent
		direction = toupper(direction);
		
		//If user enters 'x', exit the game
		if(direction == 'X')
		{
			printf("\n\nExiting program...");
			break;
		}
		
		//If user enters 'r', restart the game by resetting the board and score
		if(direction == 'R')
		{
			printf("\n\nNow resetting board\n\n");
			initializeBoard(boardArray, numTiles);
			printBoard(boardArray, boardSize);
			score = 0;
		}
		
		//If user enters 'p', place a new tile value on the board
		if(direction == 'P')
		{
			//Variables for the tile and its value to be changed
			int tilePos;
			int tileValue;
			//Get the tile and its value
			scanf(" %d %d", &tilePos, &tileValue);
			//Place the value on that particular tile
			placeTile(boardArray, numTiles, tilePos, tileValue);
			
		}
		
		//Varify that the user entered a valid direction
		validDirection = checkValidDirection(direction);
		
		//If the user did not enter a valid direction, have them try again
		if (validDirection == false)
		{
			printf("\nERROR: Invalid Direction. Please try again.");
			continue;
		}
		
		//Switch case for the direction (up, left, down, right)
		switch (direction)
		{
			//Move the tiles up, update score, and place a new tile on the board
			case 'W':
				slideUp(boardArray, boardSize);
				score += mergeUp(boardArray, boardSize);
				setRandomTile(boardArray, numTiles);
				break;
			//Move the tiles left, update score, and place a new tile on the board	
			case 'A':
				slideLeft(boardArray, boardSize);
				score += mergeLeft(boardArray, boardSize);
				setRandomTile(boardArray, numTiles);
				break;
			//Move the tiles down, update score, and place a new tile on the board	
			case 'S':
				slideDown(boardArray, boardSize);
				score += mergeDown(boardArray, boardSize);
				setRandomTile(boardArray, numTiles);
				break;
			//Move the tiles right, update score, and place a new tile on the board	
			case 'D':
				slideRight(boardArray, boardSize);
				score += mergeRight(boardArray, boardSize);
				setRandomTile(boardArray, numTiles);
				break;
			default:
				break;
		}
		
		
		//Clear the screen between moves
		//WINDOWS system("cls");
		system("clear");
		
		//Print the updated board to the user
		printBoard(boardArray, boardSize);
		
		//Check if the board is unplayble and if so, exit program
		unplayable = checkUnplayable(boardArray, boardSize);
		if (unplayable == true)
		{
			printf("\n\nSorry, you lost the game. Now exiting.");
			break;
		}
		
		//Check if the user has won and if so, exit the program
		hasWon = checkWin(boardArray, boardSize);
		if (hasWon == true)
		{
			printf("\n\nCongratulations! You won the game! Now exiting.");
			break;
		}
		
		//Increase the number of moves by one
		numMoves++;
			
	}while (hasWon != true); //Repeat game process until the user has won
}