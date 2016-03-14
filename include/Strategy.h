#include <vector>

class Strategy{
    public:
        std::vector<int> tabuleiroAtual;

        virtual bool shouldRevive(int w, int h) = 0;
        virtual bool shouldKill (int w, int h) = 0;

        void adicionaCelula(int novaCelula);
        int aliveNeighborCells (int w, int h);
        bool isCellAlive(int w, int h);
        bool isAlive(int ID);
        bool isSameCell(int w, int h, int i, int j);
        void clearVector();

};

class Conways : public Strategy{
    bool shouldRevive(int w, int h);
    bool shouldKill (int w, int h);
};

class  HighLife : public Strategy{
    bool shouldRevive(int w, int h);
    bool shouldKill (int w, int h);
};

