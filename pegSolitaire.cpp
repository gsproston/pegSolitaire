/* 
Author: George Sproston
Created: 2017/09/12
Updated: 2017/09/12
Solved a game of peg solitaire
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

void printBoard(int board[7][7]) {
	// we know the array is of size 7x7
	for (int y=0; y<7; y++) {
		// cycles through the columns
		for (int x=0; x<7; x++) {
			if (board[y][x] == -1) {
				cout << "  ";
			} else {
				cout << board[y][x] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

bool finished(int board[7][7]) {
  // first check that there is a peg in the centre
  // done first for optimisation reasons
  if (board[3][3] != 1) {
    return false;
  }
  // make sure there are no other pegs
  for (int y=0; y<7; y++) {
    for (int x=0; x<7; x++) {
      if (y==3 && x==3) {
        // skip this, as it's the centre
        continue;
      } else if (board[y][x] == 1) {
        // another peg has been found!
        return false;
      }
    }
  }
  return true;
}

bool move(int board[7][7]) {
  // first check to see if the game has finished
  if (finished(board)) {
    return true;
  }

  // check for all pegs on the board
  for (int y=0; y<7; y++) {
    for (int x=0; x<7; x++) {
      if (board[y][x] == 1) {
        // only consider further if it's a peg

        // consider moving up
        if (y >= 2 && board[y-1][x] == 1 && board[y-2][x] == 0) {
          // copy over the board
          int board2[7][7];
          memcpy(board2,board,sizeof(board2));
          board2[y][x] = 0;
          board2[y-1][x] = 0;
          board2[y-2][x] = 1;
          if (move(board2)) {
            printBoard(board2);
            return true;
          }
        }

        // consider moving down
        if (y <= 4 && board[y+1][x] == 1 && board[y+2][x] == 0) {
          // copy over the board
          int board2[7][7];
          memcpy(board2,board,sizeof(board2));
          board2[y][x] = 0;
          board2[y+1][x] = 0;
          board2[y+2][x] = 1;
          if (move(board2)) {
            printBoard(board2);
            return true;
          }
        }

        // consider moving left
        if (x >= 2 && board[y][x-1] == 1 && board[y][x-2] == 0) {
          // copy over the board
          int board2[7][7];
          memcpy(board2,board,sizeof(board2));
          board2[y][x] = 0;
          board2[y][x-1] = 0;
          board2[y][x-2] = 1;
          if (move(board2)) {
            printBoard(board2);
            return true;
          }
        }

        // consider moving left
        if (x <= 4 && board[y][x+1] == 1 && board[y][x+2] == 0) {
          // copy over the board
          int board2[7][7];
          memcpy(board2,board,sizeof(board2));
          board2[y][x] = 0;
          board2[y][x+1] = 0;
          board2[y][x+2] = 1;
          if (move(board2)) {
            printBoard(board2);
            return true;
          }
        }
      }
    }
  }
  return false;
}

void main() {
  // first, get the board
	int board[7][7] = {
		{-1,-1,1,1,1,-1,-1},
		{-1,-1,1,1,1,-1,-1},
		{1,1,1,1,1,1,1},
		{1,1,1,0,1,1,1},
		{1,1,1,1,1,1,1},
		{-1,-1,1,1,1,-1,-1},
		{-1,-1,1,1,1,-1,-1}};

  freopen("log.txt","w",stdout);
  cout << "Log File\n\n";
  move(board);
  printBoard(board);
  fclose(stdout);
}