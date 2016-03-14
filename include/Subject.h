//#include "../include/Observer.h"
#include <vector>
class Observer;

class Subject{
	std::vector<Observer> listaObservadores;

	public:
		void attach(Observer *observador);

		void notify(int state);
};

/*class Subject{
    public:
        virtual ~Subject();

        virtual void adicionaObserver(Observer* observer);
        virtual void removeObserver(Observer* observer);
        virtual void NotifyState(int state);


        Subject();


        std::vector<Observer *> observers_list;
};*/
