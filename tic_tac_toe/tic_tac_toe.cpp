// Tic-Tac-Toe Game

#include <iostream>
#include <string>

// Print out the board
void outputBoard(char** board) {
	for (unsigned int i = 0; i < 3; i++) {
		for (unsigned int j = 0; j < 3; j++) {
			if (j != 2) {
				std::cout << ' ' << board[i][j] << " |";
			} else {
				std::cout << ' ' << board[i][j] << ' ';
			}
		}
		if (i != 2) {
			std::cout << std::endl << "-----------" << std::endl;
		} else {
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

// Check if coordinates are valid for the board
bool checkCoordinates(int x, int y, char** board) {
	if (x > 3 || x < 0 || y > 3 || y < 0) {
		return false;
	} else if (board[y][x] != ' ') {
		return false;
	}
	return true;
}

// Check if a player has gotten 3 in a row or if the game is a draw
bool checkBoard(char** board) {
	// Check rows
	for (unsigned int i = 0; i < 3; i++) {
		int count = 1;
		for (unsigned int j = 0; j < 2; j++) {
			if (board[i][j] == board[i][j+1] && board[i][j] != ' ') {
				count++;
			} else {
				break;
			}
		}
		if (count == 3) {
			return true;
		}
	}

	// Check columns
	for (unsigned int j = 0; j < 3; j++) {
		int count = 1;
		for (unsigned int i = 0; i < 2; i++) {
			if (board[i][j] == board[i+1][j] && board[i][j] != ' ') {
				count++;
			} else {
				break;
			}
		}
		if (count == 3) {
			return true;
		}
	}

	// Check diagonals
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
		return true;
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') {
		return true;
	}

	return false;
}

int main() {

	// Game basics information
	std::cout << "---------------------------" << std::endl;
	std::cout << "| Welcome to Tic-Tac-Toe! |" << std::endl;
	std::cout << "---------------------------" << std::endl << std::endl;

	std::cout << "Background: " << std::endl << 
	"1. The board consists of 9 spots where either an X or O can be placed." << std::endl << 
	"2. The game is for two players, each player being assigned to X or O." << std::endl << 
	"3. The goal is to get three of your X's or O's in a row." << std::endl << std::endl << 
	"Have fun!" << std::endl << std::endl;

	// Create the empty board
	char** board = new char*[3];
	for (unsigned int i = 0; i < 3; i++) {
		board[i] = new char[3];
		for (unsigned int j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}

	// Game input information
	std::cout << "To make a move, type in the x and y coordinate where you want to put your X or O." <<
	std::endl << "(The coordinates start at (0,0) in the top left corner.)" << std::endl << std::endl;

	// Begin loop for the game (use bool value to check if a player has won or if the game is a draw)
	bool done = false;
	int moves = 0;
	while (!done) {
		outputBoard(board);
		bool valid = false;

		// Read in the move for X
		int x1, y1;
		while (!valid) {
			std::cout << "Player 1 (X), type in your move..." << std::endl;
			std::cout << "x coordinate?" << std::endl;
			std::cin >> x1;
			std::cout <<  "y coordinate?" << std::endl;
			std::cin >> y1;
			std::cout << std::endl;
			valid = checkCoordinates(x1, y1, board);
			if (!valid) {
				std::cout << '(' << x1 << ',' << y1 << ") is not a valid point on the board or has"
				<< " already been taken!" << std::endl << std::endl;
			}
		}
		board[y1][x1] = 'X';

		if (checkBoard(board)) {
			done = true;
			std::cout << std::endl << "******************************" << std::endl;
			std::cout << "Player 1 (X) has won the game!" << std::endl << std::endl;
			outputBoard(board);
			std::cout << "******************************" << std::endl;
			break;
		}

		moves++;
		outputBoard(board);

		// Check if the game is a draw
		if (moves == 9 && !checkBoard(board)) {
			done = true;
			std::cout << std::endl << "*******************" << std::endl;
			std::cout << "The game is a draw!" << std::endl << std::endl;
			outputBoard(board);
			std::cout << "*******************" << std::endl;
			break;
		}

		// Read in the move for O
		valid = false;
		int x2, y2;
		while (!valid) {
			std::cout << "Player 2 (O), type in your move..." << std::endl;
			std::cout << "x coordinate?" << std::endl;
			std::cin >> x2;
			std::cout <<  "y coordinate?" << std::endl;
			std::cin >> y2;
			std::cout << std::endl;
			valid = checkCoordinates(x2, y2, board);
			if (!valid) {
				std::cout << '(' << x2 << ',' << y2 << ") is not a valid point on the board or has"
				<< " already been taken!" << std::endl << std::endl;
			}
		}
		board[y2][x2] = 'O';

		if (checkBoard(board)) {
			done = true;
			std::cout << std::endl << "******************************" << std::endl;
			std::cout << "Player 2 (O) has won the game!" << std::endl << std::endl;
			outputBoard(board);
			std::cout << "******************************" << std::endl;
			break;
		}

		moves++;
	}

	// Clean up memory
	for (unsigned int i = 0; i < 3; i++) {
		delete [] board[i];
	}
	delete [] board;

	return 0;
}