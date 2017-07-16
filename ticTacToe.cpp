#include <iostream>
#include <map>
#include <utility>
using namespace std;
void showInstructions();
int check(int i, int j);

int board[100][100];
int n = 3;
int input;
map<int, pair<int, int> > gameMap; 
int winDiagonal = 0, winAntiDiagonal = 0, winHorizontal = 0, wintVertical = 0, flag = 1;

int main() {

	//Initial condition of the board
	for(int i=0; i<n;i++) {
		for(int j=0; j<n;j++){
			board[i][j] = n*i+j;
			gameMap.insert(pair <int, pair<int, int> > (n*i+j, make_pair(i,j)));
		}

	}
	showInstructions(); //Show initial state

	while (flag == 1 ) {
	cout << "Enter place: ";
	cin >> input;
	board[gameMap.find(input)->second.first][gameMap.find(input)->second.second] = 21;
	flag = check(gameMap.find(input)->second.first, gameMap.find(input)->second.second);
	showInstructions();
	}
	cout << "Win";
	return 0;
}

void showInstructions() {
	cout << "----------------------------\n";
	cout << "\t\tTic Tac Toe\n";
	cout << "----------------------------\n\n";
	cout << "Instructions:\n";
	cout << "Player 1: X \nPlayer 2: O\n\n\n";

	//Board
	cout << "     |     |     " << endl;
	cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;

	cout << "     |     |     " << "\n\n\n\n";
}

int check(int i, int j) {

	// case 1: Diagonal
	if(i == j) {
		winDiagonal += 1;
	} 
	//case 2: AntiDiagonal
	if (i+j == n-1) {
		winAntiDiagonal += 1;
	}
	
	if (winDiagonal == n || winAntiDiagonal == n) {
		cout << "Win";
		return -1;
	}
	else
		return 1;

}