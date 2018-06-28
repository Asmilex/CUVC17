#include <iostream>
#include "UsuariosVIP.h"
#include <fstream>

using namespace std;

//TODO
int recuperaMutantesCSV(Mutante* v[], unsigned int tamv, std::string nomArchivo) {
    std::ifstream fichero;
    std::string linea;
    fichero.open(nomArchivo.c_str());
    if(fichero.good()){
        for(int i = 0; i < tamv; i++){
            std::getline(fichero, linea);
            if(fichero.eof()) break;
            v[i] = new Mutante();
            v[i]->fromCSV(linea);
            
        }
        fichero.close();
        
    }
    
}

int main(){
    int opcion;
    
    
    
    do{
        cout << "1. Mostrar Usuarios" << endl();
        cout << "2. Añadir Usuario" << endl();
        cout << "3. Eliminar Usuario" << endl();
        cout << "4. Actualizar listado de Usuarios" << endl();
        cout << "5. Salir" << endl();
        cin >> opcion;
        
        switch(opcion){
            case 1:break;
            case 2:
                break;
            case 3:break;
            case 4:break;
        }
        
    }while(opcion>=1 &&  opcion<=4);
    
}
