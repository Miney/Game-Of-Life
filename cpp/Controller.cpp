#include <iostream>

using namespace std;

#include "../include/Controller.h"

void Controller::startGame() {

  while(true) {
    showOptionsMenu();

    int menu = 0;

    cin >> menu;
    switch(menu) {
     case 1: revive(); break;
     case 2: kill(); break;
     case 3: nextGeneration(); break;
     case 4: lastGeneration(); break;
     case 5: changeStrategy(); break;
     case 6: return;
     default: opcaoInvalida();
    }
  }
}

void Controller::revive() {
  int cols = game.getWidth();
  int rows = game.getHeight();
  int c, r = 0;

  c = getColumn(cols);

  if(cols == -1) return;

  r = getRow(rows);

  if(rows == -1) return;

   game.makeCellAlive(c, r);
   board.update(game);
}

void Controller::kill(){
    int cols = game.getWidth();
    int rows = game.getHeight();
    int c, r = 0;

    c = getColumn(cols);

    if(cols == -1) return;

    r = getRow(rows);

    if(rows == -1) return;

    game.makeCellDead(c, r);
    board.update(game);

}

void Controller::nextGeneration() {
  game.nextGeneration();
  board.update(game);
}

void Controller::lastGeneration(){
    if(!game.listaGeracoes.empty()){
        game.lastGeneration();
    }
    else{
        listaVazia();
    }
    board.update(game);
}

void Controller::changeStrategy(){
    int type;
    showStrategyOptions();
    cin>>type;
    game.setStrategy(type);
}
