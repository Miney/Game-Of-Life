/*! Define the valid states of a cell. */
enum EnumState {DEAD, ALIVE};

/*! Cell class definition
 *
 *  The cell class represents a Cell
 *  in the game of life. Each cell has a
 *  state and methods for killing or
 *  reviving.
 */
class Cell {
    private:
        EnumState state;
    public:
        Cell();
    /*! Changes the state of a cell to DEAD */
    void kill();

    /*! Changes the state of a cell to ALIVE */
    void revive();

    /*! Verifies whether a cell is alive or not */
    bool isAlive();
};
