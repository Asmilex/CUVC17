#include "UsuarioVIP_functions.h"
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
	// Recuperción de Usuarios
	vector<UsuarioVIP> VIPs;

	if (FileExists() && FileSize() > 0)
		LoadFile(VIPs);
	// Fin de recuperación de datos 

	cout <<"Bienvenido, admin." <<endl;
	if (VIPs.size() != 0)
		AutoEliminador(VIPs);

	int opcion;    
	while (true){
		DisplayUsers(VIPs);

		cout << "   1) Añadir Usuario" << endl;
		cout << "   2) Eliminar usuario manualmente"<<endl;
		cout << "   3) Ordenar por nombre"<<endl;
		cout << "   4) Ordenar por fecha"<<endl;
		cout << "   5) Salir" << endl;
		cin  >> opcion;

		switch(opcion){
			case 1:{
				string user;
				int suscripcion;

				cout << "   Nombre del usuario: ";
				cin  >> user;

				cout << "   Tipo de suscripción: ";
				cin  >> suscripcion;

				UsuarioVIP nuevo_usuario(user, suscripcion);

				if(AnadirUsuarioVIP(VIPs, nuevo_usuario)){
					cout << "\nUsuario añadido correctamente\n";
					SaveFile(VIPs);
				}
				else
					cerr << "\nNo se ha podudo añadir el usuario\n";
			} break;

			case 2:{
				int opcion;

				cout <<"   Introduce el número del usuario a eliminar: ";
				cin >>opcion;

				if (opcion > 0 && opcion <= VIPs.size() && EliminarUsuarioVIP(VIPs, opcion)){
					cout <<"\nUsuario eliminado correctamente\n";
					SaveFile(VIPs);
				}
				else
					cout <<"\nNo se ha podido eliminar el usuario\n";
				
			} break;
			case 3:{
				sort(VIPs.begin(), VIPs.end(), sortByName);
				SaveFile(VIPs);
			} break;

			case 4:{
				sort(VIPs.begin(), VIPs.end(), sortByDate);
				SaveFile(VIPs);
			} break;

			case 5:{
				if (VIPs.size() != 0)
					SaveFile(VIPs);
				return 0;
			}
		}
	}
}



