#include "UsuarioVIP_functions.h"
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
	vector<UsuarioVIP> VIPs;
	
	// Recuperción de Usuarios
	if (FileExists() && FileSize() > 0)
		LoadFile(VIPs);

	cout <<"Bienvenido, admin." <<endl;
	
	if (VIPs.size() != 0)
		AutoEliminador(VIPs);

	unsigned opcion;    
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
				unsigned suscripcion;

				cout << "   Nombre del usuario: ";
				cin  >> user;

				cout << "   Tipo de suscripción: ";
				cin  >> suscripcion;

				UsuarioVIP nuevo_usuario(user, suscripcion);

				if (AnadirUsuarioVIP(VIPs, nuevo_usuario)){
					cout << "\nUsuario añadido correctamente\n";
					SaveFile(VIPs);
				}
				else
					cerr << "\nNo se ha podudo añadir el usuario\n";
			} break;

			case 2:{
				size_t opcion;

				cout << "   Introduce el número del usuario a eliminar: ";
				cin  >> opcion;

				// Opcion: {1..n} => {0..n-1} al pasarlo a función
				if (opcion > 0 && opcion <= VIPs.size() && EliminarUsuarioVIP(VIPs, opcion - 1)){
					cout <<"\nUsuario eliminado correctamente\n";
					SaveFile(VIPs);
				}
				else
					cout <<"\nNo se ha podido eliminar el usuario\n";
			} break;
			
			case 3:{
				// Lambda expression
				auto sort_by_name = [](const UsuarioVIP &lhs, const UsuarioVIP &rhs){
				    string primero = lhs.GetName();
    				string segundo = rhs.GetName();
    
    				for (auto& c: primero) c = toupper(c);
					for (auto& c: segundo) c = toupper(c);
    
    				return primero < segundo;	
				};

				sort(VIPs.begin(), VIPs.end(), sort_by_name);
				SaveFile(VIPs);
			} break;

			case 4:{
				auto sort_by_date = [](const UsuarioVIP& lhs, const UsuarioVIP& rhs)
					{return tm_to_int(lhs.GetFechaLimite()) < tm_to_int(rhs.GetFechaLimite() );};

				sort(VIPs.begin(), VIPs.end(), sort_by_date);
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



