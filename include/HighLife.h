#include "Strategy.h"

class  HighLife: public Strategy{
    bool shouldRevive(int w, int h);
    bool shouldKill (int w, int h);
};
