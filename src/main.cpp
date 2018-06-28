#include <iostream>
#include "UsuariosVIP.h"

using namespace std;


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
            case 2:break;
            case 3:break;
            case 4:break;
        }
        
    }while(opcion>=1 &&  opcion<=4);
    
}
