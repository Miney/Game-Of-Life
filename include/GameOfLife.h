/**
 * @file
 *
 * The game of life model component, which compromises
 * the Cell and GameOfLiife class definitions.
 *
 * @author Rodrigo Bonifacio (rbonifacio[at]cic.unb.br)
 * @date 05/2011
 */
#ifndef GAME_OF_LIFE
#define GAME_OF_LIFE

#include "Statistics.h"
#include "Cell.h"
#include "../include/Visual.h"
#include "../include/Strategy.h"

#include <vector>
#include <list>


//! EnumState enumeration.
/*! GameOfLife class definition
 *
 *  Modularizes the behavior of a game
 *  of life. In this version, just one algorithm
 *  for evolving the environment for a next generation is allowed.
 *  To solve this provlem, we could evolve this design using either
 *  the Strategy or Template Method design patterns
 *  (both).
 *
 *  This version is not well designed, since it keeps
 *  a reference to one instance of the Statistics class. It
 *  would be nice to see an implementation of this class
 *  being a subject participant of the Observer pattern,
 *  whereas the Statics class could be one subscriber
 *  participant of the Observer pattern.
 */
 class Subject{
//    std::vector<Observer > listaObservadores;

    private:
        typedef std::list<Observer*> ObsList;
        typedef ObsList::iterator ObsListIter;
        ObsList myObservers;

	public:
		void attach(Observer* observador){
            myObservers.push_back(observador);
        }


		void notify(int state){

            for (ObsListIter i (myObservers.begin()); i != myObservers.end(); ++i) {
                (*i)->update(state);
            }
        }

 };

enum gameVariations{
    Connway
};

class GameOfLife : Subject{
 private:
  int width, height;
  Observer* statistics;
  Strategy *strategy;
  Cell** cells;
  void killEnvironment();
  bool shouldRevive(int w, int h);
  bool shouldKill(int w, int h);

 public:

  std::list<std::vector<int> > listaGeracoes;

  /*! Constructor, taking the number of columns and rows */
  GameOfLife(int w, int h);

  /*! Returns the number of cells in the ALIVE state */
  int aliveCells();

  /*! Given the position of a cell, returns the number of alive neighbors */
  int aliveNeighborCells(int w, int h);

  /*! Checks whether a cell is alive */
  bool isCellAlive(int w, int h);

  /*! Makes a given cell alive */
  void makeCellAlive(int w, int h);

  /*! Kills a given cell */
  void makeCellDead(int w, int h);

  /*! Leads the game state to a next generation */
  void nextGeneration();

  /*! Leads the game state to the last generation */

  void lastGeneration();

  void saveGeneration();

  /*! Access method to the number of columns */
  int getWidth() const { return width; }

  /*! Access method to the number of rows */
  int getHeight() const { return height; }

  void setStrategy(int type);
};

#endif
