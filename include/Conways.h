class Strategy;

class Conways : public Strategy{
    bool shouldRevive(int w, int h);
    bool shouldKill (int w, int h);
};
