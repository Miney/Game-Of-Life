#include <iostream>
#include "../include/Statistics.h"

using namespace std;



void Statistics::survive() {
  cout << "Number of cells revived: " << ++survivors << endl;
}

void Statistics::kill() {
  cout << "Number of cells killed: " << ++killed << endl;
}

void Statistics::update(int state){
    if(state == 1){
        this->survive();
        //this.survivors++
    }
    else if (state == 0){
        this->kill();
        //this.killed++;
    }
}
