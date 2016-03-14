//#include <iostream>
//#include <cstdio>
//#include <string>

//using namespace std;

#include "../include/GameOfLife.h"
#include "../include/GameBoard.h"
#include "../include/Controller.h"


const int rows = 10;
const int cols = 10;

int main() {
  showGameIntro();

  GameOfLife game(cols, rows);
  GameBoard board(rows, cols);
  Controller controller(game, board);

  controller.startGame();

}


