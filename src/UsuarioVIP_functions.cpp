#include "UsuarioVIP_functions.h"
using namespace std;

bool AnadirUsuarioVIP(vector<UsuarioVIP> & VIPs, const UsuarioVIP & nuevo_usuario){    
    // FIXME: Mejorar manejo de errores. No se deben incluir entradas/salidas junto a operaciones
    if (nuevo_usuario.GetTipoSuscripcion() != 1 && nuevo_usuario.GetTipoSuscripcion() != 3){
        cerr <<"El tipo de suscripción no está disponible según tu plan (1 ó 3 meses)\n";
        return false;
    }

    if (nuevo_usuario.GetName() == ""){
        cerr <<"El nombre del usuario no puede estar vacío\n";
        return false;
    }

    VIPs.push_back(nuevo_usuario);
    return true;
}

// Unused function
bool EliminarUsuarioVIP(vector<UsuarioVIP> & VIPs, const string usuario){ 
   if (usuario == ""){
        cerr <<"El usuario a eliminar no debe tener un nombre vacío\n";
        return false;
    }

    for (size_t i; i<VIPs.size(); i++)
        if (VIPs[i].GetName() == usuario){
            VIPs.erase(VIPs.begin() + i);
            break;
        }
    
    return true;
}

bool EliminarUsuarioVIP(vector<UsuarioVIP> & VIPs, const size_t posicion){ 
   if (posicion < 0 && posicion > VIPs.size()){
       throw out_of_range("Posición inválida");
    }

    VIPs.erase(VIPs.begin() + posicion);

    return true;
}

void DisplayUsers(const vector<UsuarioVIP> & VIPs){
    cout <<"\n\n\n\n";
    if (VIPs.size() != 0){
        cout <<setw(33)<<left<<setfill(' ')<<"   Usuario"<<"Suscripcion         ";  
        cout <<"  Fecha"<<endl;

        cout.width(62);
        cout.fill('-');
        cout<<"-"<<endl;

        for (size_t i=0; i<VIPs.size(); i++){
            cout <<i+1<<"- ";
            cout <<setw(30)<<left<<setfill(' ')<<VIPs[i].GetName()<<"     "<<VIPs[i].GetTipoSuscripcion()<<"               ";
            cout <<right<<VIPs[i].GetFechaLimite().tm_mday<<"/"
                        <<VIPs[i].GetFechaLimite().tm_mon <<"/"
                        <<VIPs[i].GetFechaLimite().tm_year<<endl;
        }

        cout.width(62);
        cout.fill('-');
        cout<<"-"<<endl;
    }
    else
        cout << endl << "No hay usuarios almacenados en la base de datos"<< endl;
}

// Unused function
void ClearScreen(){
    cout << string(100, '\n');
}

bool AutoEliminador(vector<UsuarioVIP> & VIPs){
    // Comprobación de usuarios
    bool mensaje_bienvenida = true;
    tm now = getLocalTime();

    for (size_t i=0; i < VIPs.size(); i++){
        if (now > VIPs[i].GetFechaLimite() ){
            if (mensaje_bienvenida){
                cout <<"A los siguientes usuarios se les ha pasado su periodo VIP:" <<endl;
                mensaje_bienvenida = false;
            }
            
            cout <<"\t"<<VIPs[i].GetName() << " - " << VIPs[i].GetFechaLimite().tm_mday<<"/" 
                 << VIPs[i].GetFechaLimite().tm_mon  << "/"
                 << VIPs[i].GetFechaLimite().tm_year << endl;
        }        
    }

    if (mensaje_bienvenida){
        cout <<"Todos los usuarios tienen sus suscripciones en orden. "<<endl;
        return false;
    }       
    else {
        // Eliminación de usuarios

        cout <<"¿Quieres eliminar automáticamente a dichos usuarios? (Y/n): ";

        char respuesta;
        do {
            cin >>respuesta;
        } while (respuesta != 'y' && respuesta != 'Y' && respuesta != 'n' && respuesta != 'N');
        
        if (respuesta == 'y' || respuesta == 'Y'){

            for (size_t i=0; i < VIPs.size(); i++){
                if (now > VIPs[i].GetFechaLimite() ){
                    EliminarUsuarioVIP(VIPs, i+1);
                    --i;
                }
            }
            cout << "Se han eliminado los usuarios anteriores"<<endl;
            return true;
        }
        else {
            cout <<"No se han eliminado los usuarios" <<endl;
            return false;
        }
    }
}

////////////////////////////////////////////////////////////////////
bool FileExists(const string & fileName){
    ifstream infile(fileName);
    return infile.good();
}

ifstream::pos_type FileSize(const string & filename){
    ifstream in(filename, ifstream::ate | ifstream::binary);
    return in.tellg(); 
}

bool SaveFile(const vector<UsuarioVIP> & VIPs, const string & nomArchivo){
    ofstream fichero;
    fichero.open(nomArchivo);

    if (fichero){
        for (auto persona: VIPs)
            fichero <<persona.toCSV();

        fichero.close();
        return true;
    }
    else
        throw runtime_error("El fichero no se ha podido abrir");
}

bool LoadFile(vector<UsuarioVIP> & VIPs, const string & nomArchivo){
    ifstream fichero;
    string linea;
    
    fichero.open(nomArchivo.c_str());
    UsuarioVIP nuevo_usuario;

    if(fichero.good()){
        while (!fichero.eof()){
            getline(fichero, linea);

            if (!fichero.eof()){
                nuevo_usuario.fromCSV(linea);
                VIPs.push_back(nuevo_usuario);
            }
        }

        fichero.close();
        return true;
    }
    else
        throw runtime_error("El fichero no se ha podido abrir");
}

////////////////////////////////////////////////////////////////////

tm getLocalTime(){
    time_t      t1  = time(0);           // get time now
    struct tm* now  = localtime( & t1 ); // convert to local time
    

    now->tm_mon  += 1;
    now->tm_year += 1900;

    struct tm copy = *now;               // make a local copy.
    return copy;
}

long int tm_to_int(const tm fecha){
    return fecha.tm_year * 10000 + fecha.tm_mon * 100 + fecha.tm_mday; 
}

bool operator==(const tm & fecha1,const tm & fecha2){
    if (fecha1.tm_year == fecha2.tm_year && 
        fecha1.tm_mon  == fecha2.tm_mon  &&
        fecha1.tm_mday == fecha2.tm_mday)
        return true;
    else
        return false;
}

bool operator!=(const tm & fecha1,const tm & fecha2){
    if (fecha1.tm_year == fecha2.tm_year && 
        fecha1.tm_mon  == fecha2.tm_mon  &&
        fecha1.tm_mday == fecha2.tm_mday)
        return false;
    else
        return true;
}

bool operator>(const tm & fecha1, const tm & fecha2){
    if (tm_to_int(fecha1) > tm_to_int(fecha2))
        return true;
    else
        return false;
}

bool operator>=(const tm & fecha1,const tm & fecha2){
    if (tm_to_int(fecha1) >= tm_to_int(fecha2))
        return true;
    else
        return false;
}

bool operator<(const tm & fecha1,const tm & fecha2){
    if (tm_to_int(fecha1) < tm_to_int(fecha2))
        return true;
    else
        return false;
}

bool operator<=(const tm & fecha1,const tm & fecha2){
    if (tm_to_int(fecha1) <= tm_to_int(fecha2))
        return true;
    else
        return false;
}


bool sortByName(const UsuarioVIP &lhs, const UsuarioVIP &rhs){
    string primero = lhs.GetName();
    string segundo = rhs.GetName();
    
    for (auto & c: primero) c = toupper(c);
    for (auto & c: segundo) c = toupper(c);
    
    return primero < segundo;
}

bool sortByDate(const UsuarioVIP &lhs, const UsuarioVIP &rhs){
    return tm_to_int(lhs.GetFechaLimite()) < tm_to_int(rhs.GetFechaLimite());
}