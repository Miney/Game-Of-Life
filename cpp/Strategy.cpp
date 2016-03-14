#include "../include/Strategy.h"


void Strategy::adicionaCelula(int novaCelula){
    tabuleiroAtual.push_back(novaCelula);
}

int Strategy::aliveNeighborCells(int w, int h){
    if(w < 0 || w >= 10) return 0;
    if(h < 0 || h >= 10) return 0;

    int r = 0;

    for(int i = h-1; i <= h+1; i++) {
        for(int j = w-1; j <= w+1; j++) {

          if(isSameCell(w, h, i, j)== false && isCellAlive(j, i) == true){
                  r++;
          }
        }
    }
    return r;

}

bool Strategy::isCellAlive(int w, int h){
  if(w < 0 || w >= 10) return false;
  if(h < 0 || h >= 10) return false;
  int ID = h*10 + w;
  return  isAlive(ID);
}

bool Strategy::isAlive(int ID){
    if(tabuleiroAtual[ID] == 1){
        return true;
    }
    return false;
}

bool Strategy::isSameCell(int w, int h, int i, int j){
    if(h==i && w==j){
        return true;
    }
    return false;
}

void Strategy::clearVector(){
    tabuleiroAtual.erase(tabuleiroAtual.begin(), tabuleiroAtual.end());
}

