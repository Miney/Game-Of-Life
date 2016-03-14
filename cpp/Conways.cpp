#include "../include/Strategy.h"
#include <iostream>

bool Conways::shouldRevive(int w, int h){
  int aliveNeighbors = aliveNeighborCells(w,h);

  //std::cout<<"numero vizinhos vivos :"<<aliveNeighbors<<std::endl;

  return ((!isCellAlive(w,h)) && (aliveNeighbors == 3));
}

bool Conways::shouldKill(int w, int h){
  int aliveNeighbors = aliveNeighborCells(w,h);

  //std::cout<<"numero vizinhos vivos :"<<aliveNeighbors<<std::endl;

  return (isCellAlive(w,h) && (aliveNeighbors != 2 && aliveNeighbors != 3));

}


