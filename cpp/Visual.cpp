#include "../include/Visual.h"

using namespace std;

void showGameIntro(){
    cout << " _____                      _____  __ _      _  __     "       << endl;
    cout << "|  __ \\                    |  _  |/ _| |    (_)/ _|    "      << endl;
    cout << "| |  \\/ __ _ _ __ ___   ___| | | | |_| |     _| |_ ___ "      << endl;
    cout << "| | __ / _` | '_ ` _ \\ / _ \\ | | |  _| |    | |  _/ _ \\"    << endl;
    cout << "| |_\\ \\ (_| | | | | | |  __| \\_/ / | | |____| | ||  __/"    << endl;
    cout << " \\____/\\__,_|_| |_| |_|\\___|\\___/|_| \\_____/|_|_| \\___|" << endl << endl << endl;

    cout << "Bem vindo, essa eh a versao C++ do jogo GameOfLife " << endl;
    cout << "escrita por Rodrigo Bonifacio (CiC, UnB) como um desafio " << endl;
    cout << "para ensinar padroes de projetos." << endl << endl;
    cout << "De forma proposital, existem falhas no design dessa aplicacao." << endl;
    cout << "O objetivo eh fazer com que os alunos resolvam, de uma forma " << endl;
    cout << "dirigida e usando padroes de projeto, as principais falhas " << endl;
    cout << "de design. Pressione alguma tecla para comecar: " ;
    getchar();
}

void showOptionsMenu(){
    cout << "Select one option: " << endl << endl;
    cout << "[1] Cell revive " << endl;
    cout << "[2] Cell kill " << endl;
    cout << "[3] Next generation " << endl;
    cout << "[4] Last Generation " << endl;
    cout << "[5] Change Strategy " << endl;
    cout << "[6] Halt " << endl << endl;
    cout << "Opcao: " ;
}



void opcaoInvalida(){
    cout << endl << "Opcao invalida. Tente novamente." << endl << endl;
}

void listaVazia(){
    cout << endl << "Ultima Geracao Disponivel." << endl << endl;
}


int getColumn(int max){
    int c;
    do{
        cout << "Enter the cell collumn number (0 -- " << (max-1) << "): " ;
        cin >> c;
    }while(c>=max);
    return c;
}

int getRow(int max){
  int r;
  do{
     cout << "Enter the cell row number (0 -- " << (max-1) << "): " ;
     cin >> r;
  }while(r>=max);
  return r;
}

void showStrategyOptions(){
    cout<<"[1] Conways"<<endl;
    cout<<"[2] HighLife"<<endl;
}
