#include "UsuarioVIP_functions.h"
#include <iostream>
#include <fstream>
//#include <windows.h>
#include <stdio.h>

using namespace std;

/** Descomenta esta función y el condicional del main para compilar para Windows
 

BOOL CtrlHandler( 	DWORD fdwCtrlType, 
					const UsuarioVIP * VIPs, const unsigned int dim)
{    
	switch( fdwCtrlType ){ 
    // Handle the CTRL-C signal. 3
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
*/
int main(){
    //if( SetConsoleCtrlHandler( (PHANDLER_ROUTINE) CtrlHandler, TRUE ) )
	{ 
		//Recuperción de Usuarios
		vector<UsuarioVIP> VIPs;

		// Tamaño > 0 para evitar crasheos por si el archivo estuviera vacío 
		if (FileExists() && FileSize() > 0){
			LoadFile(VIPs);
		}

	    cout <<"Bienvenido, admin." <<endl;
		if (VIPs.size() != 0)
			AutoEliminador(VIPs);

		int opcion;    
		while (true){
			DisplayUsers(VIPs);
			
			cout << "  1) Añadir Usuario" << endl;
			cout << "  2) Eliminar usuario manualmente"<<endl;
			cout << "  3) Salir" << endl;
			cin >> opcion;
			
			switch(opcion){
				case 1:{
					string user;
					int suscripcion;

					cout <<"\tNombre del usuario: ";
					cin >>user;

					cout <<"\tTipo de suscripción: ";
					cin >>suscripcion;

					UsuarioVIP nuevo_usuario(user, suscripcion);

					if(AnadirUsuarioVIP(VIPs, nuevo_usuario))
						cout <<"\nUsuario añadido correctamente\n";
					else
						cerr <<"\nNo se ha podudo añadir el usuario\n";
				}
					break;
				case 2:{
					int opcion;

					cout <<"\tIntroduce el número del usuario a eliminar: ";
					cin >>opcion;

					if (opcion > 0 && opcion <= VIPs.size() && EliminarUsuarioVIP(VIPs, opcion))
						cout <<"\nUsuario eliminado correctamente\n";
					else
						cout <<"\nNo se ha podido eliminar el usuario\n";
				}
					break;
				case 3:{
					if (VIPs.size() != 0)
						SaveFile(VIPs);
					return 0;
				}

				default:{
					do{
						cout <<"Pulsa la tecla correcta, mamón: ";
						cin >>opcion;
					} while (opcion != 1 || opcion != 2);
				}
					break;
			}
			
		}
		//Cuando lo probé, con la siguiente linea funcionaba. Supongo que no pasa nada por comentarla
		//while( 1 ){ } 
    }  
    //else{
    //    printf( "\nERROR: Could not set control handler"); 
    //    return 1;
    //}
}



