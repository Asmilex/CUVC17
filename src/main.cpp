#include "UsuarioVIP_functions.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>

using namespace std;

BOOL CtrlHandler( 	DWORD fdwCtrlType, 
					const UsuarioVIP * VIPs, const unsigned int dim)
{    
	switch( fdwCtrlType ){ 
    // Handle the CTRL-C signal. 
    case CTRL_C_EVENT: 
		printf( "Ctrl-C event\n\n" );
      	Beep( 750, 300 ); 
      	return( TRUE );

    // CTRL-CLOSE: confirm that the user wants to exit. 
    case CTRL_CLOSE_EVENT: 
		Beep( 600, 200 );
		
		if (VIPs != nullptr) {
			SaveFile(VIPs, dim);
			delete [] VIPs;
		}
		
		return( TRUE ); 

    // Pass other signals to the next handler. 
    case CTRL_BREAK_EVENT: 
		Beep( 900, 200 ); 
		printf( "Ctrl-Break event. Saving and existing \n\n" );
		SaveFile(VIPs, dim);
		delete [] VIPs;
		return FALSE; 

    case CTRL_LOGOFF_EVENT: 
		Beep( 1000, 200 ); 
		printf( "Ctrl-Logoff event\n\n" );
		return FALSE; 

    case CTRL_SHUTDOWN_EVENT: 
		Beep( 750, 500 ); 
		printf( "Ctrl-Shutdown event\n\n" );
		return FALSE; 

    default: 
      	return FALSE; 
  } 
} 

int main(){
    if( SetConsoleCtrlHandler( (PHANDLER_ROUTINE) CtrlHandler, TRUE ) ){ 
			printf( "\nThe Control Handler is installed.\n" ); 
			printf( "\n -- Now try pressing Ctrl+C or Ctrl+Break, or" ); 
			printf( "\n    try logging off or closing the console...\n" ); 
			printf( "\n(...waiting in a loop for events...)\n\n" ); 

		//Recuperción de Usuarios
		UsuarioVIP * VIPs = nullptr;
		unsigned int dim = 0;

		// Tamaño > 0 para evitar crasheos por si el archivo estuviera vacío 
		if (FileExists() && FileSize() > 0){
			LoadFile(VIPs, dim);
		}

		int opcion;    
		while (true){
			DisplayUsers(VIPs, dim);
			
			cout << "1) Añadir Usuario" << endl;
			cout << "2) Salir" << endl;
			cin >> opcion;
			
			switch(opcion){
				case 1:{
					string user;
					int suscripcion;

					cout <<"Nombre del usuario: ";
					cin >>user;

					cout <<endl<<"Tipo de suscripción: ";
					cin >>suscripcion;

					UsuarioVIP nuevo_usuario(user, suscripcion);

					if(AnadirUsuarioVIP(VIPs, dim, nuevo_usuario))
						cout <<"Usuario añadido correctamente\n";
					else
						cerr <<"No se ha podudo añadir el usuario\n";
				}
					break;

				case 2:{
					if (VIPs != nullptr){
						SaveFile(VIPs, dim);
						delete [] VIPs;
					}
					return 0;
				}
				default:{
					do{
						cout <<"Pusla la tecla correcta, mamón"<<endl;
						cin >>opcion;

					} while (opcion != 1 || opcion != 2)
				}
					break;
			}
			
		}
		//Cuando lo probé, con la siguiente linea funcionaba. Supongo que no pasa nada por comentarla
		//while( 1 ){ } 
    }  
    else{
        printf( "\nERROR: Could not set control handler"); 
        return 1;
    }
}



