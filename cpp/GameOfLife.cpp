#include <iostream>
#include <list>

using namespace std;

#include "../include/GameOfLife.h"


GameOfLife::GameOfLife(int w, int h) {
  width = w;
  height = h;

  cells = new Cell*[w*h];

  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      cells[i*width + j] = new Cell();
    }
  }

  killEnvironment();

  statistics = new Statistics();
  attach(statistics);


  strategy = new Conways();
}

void GameOfLife::killEnvironment() {
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      cells[i*width + j]->kill();
    }
  }
}

int GameOfLife::aliveCells() {
  int r = 0;

  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      if(cells[i*width + j]->isAlive()) {
        r++;
      }
    }
  }
  return r;
}


bool GameOfLife::isCellAlive(int w, int h) {
  if(w < 0 || w >= width) return false;
  if(h < 0 || h >= height) return false;

  return  cells[h * width + w]->isAlive();
}


void GameOfLife::makeCellAlive(int w, int h) {
  if(w < 0 || w >= width) return;
  if(h < 0 || h >= height) return;

  Cell* c = cells[h * width + w];

  if(!c->isAlive()) {
    cells[h * width + w]->revive();
  }

    notify(1);
}


void GameOfLife::makeCellDead(int w, int h) {
  if(w < 0 || w >= width) return;
  if(h < 0 || h >= height) return;

  Cell* c = cells[h * width + w];

  if(c->isAlive()) {
    cells[h * width + w]->kill();
  }

  notify(0);
}

void GameOfLife::nextGeneration() {
  list<Cell*> mustRevive;
  list<Cell*> mustDie;

  saveGeneration();

  cout<<"Adicionando novas celulas da geracao"<<endl;

  for(int i=0; i< height; i++){
    for(int j = 0; j< width; j++){
      if(cells[i*width+j]->isAlive()){
        strategy->adicionaCelula(1);
      }
      else{
        strategy->adicionaCelula(0);
      }
    }
  }



  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      if(strategy->shouldRevive(j,i)) {
      	mustRevive.push_back(cells[i*width+j]);
      }
      else if (strategy->shouldKill(j,i)) {
      	mustDie.push_back(cells[i*width+j]);
      }
    }
  }

  for (list<Cell*>::iterator it = mustRevive.begin(); it != mustRevive.end(); it++) {
    (*it)->revive();
    notify(1);
  }

  for (list<Cell*>::iterator it = mustDie.begin(); it != mustDie.end(); it++) {
    (*it)->kill();
     notify(0);
  }

  strategy->clearVector();
}
///para essas funcoes os inteiros 1 e zero serao tratados 1 como sendo vivo e 0 como morto
void GameOfLife::lastGeneration(){
    vector<int> temp;
    temp = listaGeracoes.back();
    listaGeracoes.pop_back();

    for(int i=0; i< height; i++){
        for(int j=0;j<width;j++){
            if(temp[i*width+j]==1){
                cells[i*width+j]->revive();
            }
            else if(temp[i*width+j]==0){
                cells[i*width+j]->kill();
            }
        }
    }
}

void GameOfLife::saveGeneration(){
    vector<int>newGeneration;

    for(int i=0; i< height; i++){
        for(int j = 0; j< width; j++){
            if(cells[i*width+j]->isAlive()){
                newGeneration.push_back(1);
            }
            else{
                newGeneration.push_back(0);
            }
        }
    }
    listaGeracoes.push_back(newGeneration);
}

void GameOfLife::setStrategy(int type){
    switch(type){
        case 1:
            strategy = new Conways();
            break;
        case 2:
            strategy = new HighLife();
            break;
        default:
            strategy = new Conways();
            break;
    }
}


 /* Usando o TM, deveriamos tornar shouldRevive e
  * shouldKill abstratos.
  */

/*
 * Uma celula morta deve ressuscitar caso
 * tenha tres celulas vizinhas vivas.

 */
/*bool GameOfLife::shouldRevive(int w, int h) {
  int aliveNeighbors = aliveNeighborCells(w,h);

  return ((!isCellAlive(w,h)) && (aliveNeighbors == 3));
}*/

/*
 * Uma celula viva deve morrer caso
 * tenha duas ou tres celulas vizinhas vivas.
 */
/*bool GameOfLife::shouldKill(int w, int h) {
  int aliveNeighbors = aliveNeighborCells(w,h);

  return (isCellAlive(w,h) && (aliveNeighbors != 2 && aliveNeighbors != 3));
}*/

/*void setStrategy(int type);*/
