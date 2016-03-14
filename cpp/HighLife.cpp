#include "../include/Strategy.h"

bool HighLife::shouldKill(int w, int h){

  int aliveNeighbors = aliveNeighborCells(w,h);

  //std::cout<<"numero vizinhos vivos :"<<aliveNeighbors<<std::endl;

  return (isCellAlive(w,h) && (aliveNeighbors != 2 && aliveNeighbors != 3));

}

bool HighLife::shouldRevive(int w, int h){
  int aliveNeighbors = aliveNeighborCells(w,h);

  //std::cout<<"numero vizinhos vivos :"<<aliveNeighbors<<std::endl;
  if((!isCellAlive(w,h)) && (aliveNeighbors == 3)){
    return true;
  }

  else if((!isCellAlive(w,h)) && (aliveNeighbors == 6)){
    return true;
  }

  return false;
}
