#include "../include/Subject.h"

void Subject::attach(Observer *observador){
	listaObservadores.push_back(observador);
}

void Subject::notify(int state){
	for(int i = 0; i < listaObservadores.size(); i++){
        listaObservadores[i]->update(state);
        //temp = listaObservadores[i];
        //temp->update(state);
        //listaObservadores[i].notify(state);
	}

	///loop de notificacao de toda a lista de observers
}
/*
void Subject::notify(int state){
	for(int i = 0; i < sizeof(listaObservadores); i++){
        listaObservadores[i].update(state);
	}
}
*/


/*void Subject::adicionaObserver(Observer* observer){
    //ObserversList.push_back(&observer);
    observers_list.push_back(observer);
}

void Subject::removeObserver(Observer* observer){
    /*Observer temp;
    for(int i=0; i< sizeof(observers_list); i++){
        if(temp==observer){
            observers_list.erase(i);
        }
    }*/
    //observers_list.remove(observer);
//}
/*
void Subject::NotifyState(int state){

    /*for(int i=0; i<sizeof(observers_list); i++){
        observers_list[i].update(state);
    }
    /*ListIterator<Observer*> i(_observers);

    for(i.First(); !i.IsDone(); i.Next()){
        i.CurrentItem()->Update(this);
    }*/
//}
