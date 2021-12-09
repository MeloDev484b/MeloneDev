#include <iostream>
#include <array>
#include <string>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

string winner = " ";
string gameBoard[ROWS][COLS];
string playerTurn = "[X]";

int turn = 1;

bool boardFull = false;

void runGame();
//initialize winner as a string that is empty - X
//create gameboard dimensions rows x cols - X
//call initializeGameBoard() to print board, lines and contents of 2D array cells - X
//loop until winner is found:
	//keep track of whose turn it is - X
	//call getUserInput to obtain user's input and modify board if a valid move is selected(tell player to pick another cell if invalid) - X
	//after getUserInput is called, board is re-printed with printCurrentBoard since board has changed - X
	//after board is printed, set winner to whatver is returned by getWinner (X, O, or empty if no winner yet) - X
	//switch whose turn it is - X
	//at the end of the game loop, check if the board is full and winner has not been selected (if so, cat's game)
//after loop, tell user if cat won or which player won
void initializeGameBoard(string gameBoard[ROWS][COLS]);
//loop through game board, ensure elements are set to a "space" - X
void printCurrentBoard(string gameBoard[ROWS][COLS]);
//takes current board and prints the lines and game board - X
void getUserInput(string gameBoard[ROWS][COLS]);
//takes parameter representing whose turn it is and the game board --modified - X
//uses loop to determine whose turn it is and game board - X
//valid selections include values for rows and cols >= 0 and <= 2 - X
//use cellAlreadyOccupied to determine if selected row/col is legitimate - X
//after validation loop, put an X or O inside the gameboard at the appropriate row or col - X
bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS]); //currently handled in getUserInput()
//take row and col being tested and game board as parameters -
//return whether the gameboard has space at that row and col -
string getWinner(string gameBoard[ROWS][COLS]);
//takes gameboard as parameter - 
//check win con for rows - 
//check win con for cols if no row winner - 
//check win con for diagonals if no column winner - 
//default return value is an empty string...if empty loop continues - 
bool isBoardFull(string gameBoard[ROWS][COLS]); //instead, checks for turn number, board is always full turn 9
//takes game board as parameter - X
//loop through board to check if all spaces are occupied - 
//9 non-"space"es means it is full - 
//used to determine a cat's game - 


int main()
{
	initializeGameBoard(gameBoard);
	runGame();
	return 0;
}

void runGame()	
{
	isBoardFull(gameBoard);
	if (boardFull == false)
	{
		turn++;
		if (turn % 2 == 0)
		{
			playerTurn = "[X]";
			cout << "It is now X's turn." << endl << endl;
			cout << "X, please enter the coordinates for your move." << endl;
		}
		else
		{
			playerTurn = "[O]";
			cout << "It is now O's turn." << endl << endl;
			cout << "O, please enter the coordinates for your move." << endl;
		}
		printCurrentBoard(gameBoard);
	}
	if (winner == " ")
	{
		getUserInput(gameBoard);
	}
}

void initializeGameBoard(string gameBoard[ROWS][COLS])//starter
{
	cout << "Welcome to Tic Tac Toe!" << endl;
	cout << "To select your square, enter the Column followed by the Row you would like to mark." << endl << endl;
	for (int c = 0; c < ROWS; c++)
	{
		for (int r = 0; r < COLS; r++)
		{
			gameBoard[c][r] = "[ ]";
		}
	}
}

void printCurrentBoard(string gameBoard[ROWS][COLS])//starter - takes current board and prints the lines and game board
{
	for (int c = 0; c < ROWS; c++)
	{
		for (int r = 0; r < COLS; r++)
		{
			cout << gameBoard[c][r];
		}
		cout << endl;
	}
}

void getUserInput(string gameBoard[ROWS][COLS])
{
	int input1 = 0;
	int input2 = 0;

	cin >> input1;
	if (input1 <= COLS && input1 >= 0)
	{
		input1 -= 1;
		cin >> input2;
		if (input2 <= ROWS && input1 >= 0)
		{
			input2 -= 1;
			if (gameBoard[input1][input2] == "[ ]")
			{
				cout << playerTurn << " marked column " << input1 + 1 << "," << " row " << input2 + 1 << "." << endl << endl;
				gameBoard[input1][input2] = playerTurn;
				getWinner(gameBoard);
				if (winner == " ")
				{
					runGame();
				}
			}
			else
			{
				getWinner(gameBoard);
				cout << "That location has already been marked. Please try another coordinate." << endl;
				getUserInput(gameBoard);
			}
		}
	}

	if (input1 || input2 > 3)
	{
		cout << "Invalid entry, please try again." << endl;
		getUserInput(gameBoard);
	}
}

bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COLS])//starter
{
	return 0; //currently handled in getUserInput()
}

string getWinner(string gameBoard[ROWS][COLS])
{
	if (winner == " ") 
	{
		//check rows
		if (gameBoard[0][0] == playerTurn && gameBoard[0][1] == playerTurn && gameBoard[0][2] == playerTurn)
		{
			winner = playerTurn;
		}
		if (gameBoard[1][0] == playerTurn && gameBoard[1][1] == playerTurn && gameBoard[1][2] == playerTurn)
		{
			winner = playerTurn;
		}
		if (gameBoard[2][0] == playerTurn && gameBoard[2][1] == playerTurn && gameBoard[2][2] == playerTurn)
		{
			winner = playerTurn;
		}
		//check cols
		if (gameBoard[0][0] == playerTurn && gameBoard[1][0] == playerTurn && gameBoard[2][0] == playerTurn)
		{
			winner = playerTurn;
		}
		if (gameBoard[0][1] == playerTurn && gameBoard[1][1] == playerTurn && gameBoard[2][1] == playerTurn)
		{
			winner = playerTurn;
		}
		if (gameBoard[0][2] == playerTurn && gameBoard[1][2] == playerTurn && gameBoard[2][2] == playerTurn)
		{
			winner = playerTurn;
		}
		//check diag
		if (gameBoard[0][0] == playerTurn && gameBoard[1][1] == playerTurn && gameBoard[2][2] == playerTurn)
		{
			winner = playerTurn;
		}
		if (gameBoard[2][0] == playerTurn && gameBoard[1][1] == playerTurn && gameBoard[0][2] == playerTurn)
		{
			winner = playerTurn;
		}
	}
	if (winner != " ")
	{
		cout << "The winner is " << winner << "!" << endl;
	}
	else cout << "no winner yet" << endl;
	if (winner == " " && boardFull == true)//belongs to cat if no one won
	{
		cout << "The cat won!" << endl;
	}
	return winner;
}

bool isBoardFull(string gameBoard[ROWS][COLS])//starter
{
	if (turn == 10) //only 9 spaces to fill, so the board will always be full on the 9th turn. (turn starts at turn 1, thus ending at 10)
	{
		boardFull = true;
		printCurrentBoard(gameBoard);
		cout << boardFull << "test" << endl; //test line
	}
	//cout << boardFull << "test" << endl; //test line
	return boardFull;
}
