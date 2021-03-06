//Copyleft Ammo-Srush
//Open Source 
//Tic-Tac-Toy
#include <iostream>
using namespace std;

//Lets Get Started

const int ROW  = 3;
const int COLS = 3;

// Functions prototypes
void displayBoard(char [][COLS]);
void playerTurn(char [][COLS] , char);
bool gameOver(char [][COLS]);
bool playWins(char [][COLS] , char);
bool playCanWin(char [][COLS] , char);
void displayWinner(char [][COLS]);

int main ()
{
	char gameBoard[ROW][COLS]=
	                         {{'*','*','*'},
	                          {'*','*','*'}};

	do
	{ 
	   //Call displayBoard
           displayBoard(gameBoard);

	   //Call playerTurn
	   playerTurn(gameBoard , 'X');

	   //Call displayBoard again
	   displayBoard(gameBoard);

           //If the the game is not over, let
	   //player 2 have a turn.
	   if(!gameOver(gameBoard))
		   playerTurn(gameBoard , 'O');

	}while (!gameOver(gameBoard));

	//Call displayBoard
	displayBoard(gameBoard);

	//Call displayWinner
	displayWinner(gameBoard);

	return 0;
}

//function 1
void displayBoard(char board[][COLS])
{
	//Display the column headings.
	cout << "     Columns\n";
	cout << "      1  2  3\n";

	//Display the rows.
	for(int row = 0; row < ROW; row++)
	{
	   //Row label
	   cout << "Row " << (row+1) << ":  ";

	   //Row contents.
		for(int col = 0; col < COLS; col++)
		{
		   cout << board[row][col] <<  "  ";
		}
	   cout << endl;
	}
}

//function 2
void playerTurn(char board[][COLS] , char symbol)
{
	//The isAvailable flag is set to true when the
	//player selects a location in the board that
	//is availabel.
	bool isAvailable = false;
	
	int row;
	int col;
	
	cout << "Player " << symbol << "s' turn.\n";
	cout << "Enter a row and column to place an " << symbol << ".\n";
	
	//Get and validate the location.
	while (!isAvailable)
	{
	     //Get the row.
	     cout << "Row: "; cin >> row;
		
	     //Validate the row.
	     while (row < 1 || row > ROW)
	     {
		  cout << "Invalid Row!\n";
		  cout << "Row: "; cin >> row;
	     }
             
	     //Get the column.
	     cout << "Column: "; cin >> col;
		
	     //Validate the column.
	     while (col < 1 || col > COLS)
	     {
		  cout << "Invalid Column!\n";
		  cout << "Column: "; cin >> col;
	     }
	     //Determine whether the selected
	     //Call is available.
	     if(board[row - 1][col - 1] == '*')
		isAvailable = true;
	     else
                cout << "That location is not available. " << "Select another location.\n";
		
	}
	
	//place the player's symbol on thw board
	//at the selected location
	board[row - 1][col -1] = symbol;
}

//function 3
bool gameOver(char board[][COLS])
{
       //if either player has already won, game over.
       if(playWins(board , 'X') || playWins(board , 'O'))
	    return true;
       else if (playCanWin(board , 'X') || playCanWin(board , 'O'))
	    return false;
       else
	    return true;
		
}

//function 4
bool playWins(char board[][COLS] , char symbol)
{
       //check the first horizontal row.
       if (board[0][0] == symbol && board[0][1] == symbol && board[0][2] == symbol)
	     return true;
	
       //check the second horizontal row.
       if (board[1][0] == symbol && board[1][1] == symbol && board[1][2] == symbol)
	     return true;
	
       //check the third horizontal row.
       if (board[2][0] == symbol && board[1][1] == symbol && board[1][0] == symbol)
	     return true;
	
       //check the first column.
       if (board[0][0] = symbol && board[1][0] == symbol && board[2][0] == symbol)
	     return true;
	
       //check the second colum.
       if (board [0][1] == symbol && board[1][1] == symbol && board[2][1] == symbol)
	     return true;
	
       //check the third column.
       if (board[0][2] == symbol && board[1][2] == symbol && board[2][2] == symbol)
	     return true;
	
       //chack the daigonal.
       if (board [0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol)
	     return true;
	
       //If we make is this far the player did not win
       return false;
}

//function 5
bool playCanWin(char board[][COLS] , char symbol)
{
	//check the firs horizantl row for a possibility
	if ((board[0][0] == symbol || board[0][0] == '*') &&
		(board[0][1] == symbol || board[0][1] == '*') &&
        (board[0][2] == symbol || board[0][2] == '*'))
        return true;

    //check the second horizontal row for a possibility.
    if ((board[1][0] == symbol || board[1][0] == '*') &&
    	(board[1][1] == symbol || board[1][1] == '*') &&
    	(board[1][2] == symbol || board[1][2] == '*'))
    	return true;

    //check the third horizontal row for a possibiliaty.
    if ((board[2][0] == symbol || board[2][0] == '*') &&
    	(board[2][1] == symbol || board[2][1] == '*') &&
    	(board[2][2] == symbol || board[2][2] == '*'))
    	return true;

    //check the first column for a possibility.
    if ((board[0][0] == symbol || board[0][0] == '*') &&
    	(board[1][0] == symbol || board[1][0] == '*') &&
    	(board[2][0] == symbol || board[2][0] == '*'))
    	return true;

    //check the second column for a possibility.
    if ((board[0][1] == symbol || board[0][1] == '*') &&
    	(board[1][1] == symbol || board[1][1] == '*') &&
        (board[2][1] == symbol || board[2][1] == '*'))
        return true;

    //check the third column for a possibility.
    if ((board[0][2] == symbol || board[0][2] == '*') &&
    	(board[1][2] == symbol || board[1][2] == '*') && 
    	(board[2][2] == symbol || board[2][2] == '*'))
    	return true;

    //check the diagonal for a possibility.
    if ((board[0][0] == symbol || board[0][0] == '*') &&
    	(board[1][1] == symbol || board[1][1] == '*') &&
    	(board[2][2] == symbol || board[2][2] == '*'))
    	return true;

    //if we make it this far, the player cannot win.
    return false;
}

//function 6
void displayWinner(char board[][COLS])
{
	if (playWins(board , 'X'))
		cout << "Player 1 (X) WINS!!!!!\n\n";
	else if (playWins(board , 'O'))
		cout << "Player 2 (O) WINS!!!!!\n\n";
	else
		cout << "Game Over... it's a TIE.\n\n";
}
