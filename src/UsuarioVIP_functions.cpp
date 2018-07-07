#include "UsuarioVIP_functions.h"
#include <fstream>
#include <iostream>
#include <iomanip> //flags para cout
using namespace std;

//TODO: Comprobar que los usuarios no se pasen del día
bool AnadirUsuarioVIP(std::vector<UsuarioVIP> & VIPs,const UsuarioVIP nuevo_usuario){    
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

bool EliminarUsuarioVIP(std::vector<UsuarioVIP> & VIPs, const std::string usuario){ 
   if (usuario == ""){
        cerr <<"El usuario a eliminar no debe tener un nombre vacío\n";
        return false;
    }

    for (int i; i<VIPs.size(); i++)
        if (VIPs[i].GetName() == usuario){
            VIPs.erase(VIPs.begin() + i);
            break;
        }
    
    return true;
}

bool EliminarUsuarioVIP(std::vector<UsuarioVIP> & VIPs, int posicion){ 
   if (posicion <= 0 && posicion > VIPs.size()){
       throw out_of_range("Posición inválida");
    }

    VIPs.erase(VIPs.begin() + (--posicion));

    return true;
}

void DisplayUsers(const std::vector<UsuarioVIP> & VIPs){
    cout <<"\n\n\n\n";
    if (VIPs.size() != 0){
        cout <<setw(33)<<left<<setfill(' ')<<"   Usuario"<<"Suscripcion         ";  
        cout <<"  Fecha"<<endl;

        cout.width(62);
        cout.fill('-');
        cout<<"-"<<endl;

        for (int i=0; i<VIPs.size(); i++){
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

void ClearScreen(){
    cout << string(100, '\n');
}

bool LimitChecker(const std::vector<UsuarioVIP> & VIPs){
    
}

////////////////////////////////////////////////////////////////////
bool FileExists(const std::string & fileName){
    ifstream infile(fileName);
    return infile.good();
}

ifstream::pos_type FileSize(const string & filename){
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg(); 
}

bool SaveFile(const std::vector<UsuarioVIP> & VIPs, const std::string & nomArchivo){
    ofstream fichero;

    fichero.open(nomArchivo);

    if (fichero){
        for (unsigned int i=0; i<VIPs.size(); i++)
            fichero <<VIPs[i].toCSV();

        fichero.close();
        return true;
    }
    else
        throw std::runtime_error("El fichero no se ha podido abrir");
}


//FIXME: No recupera el último usuario
bool LoadFile(std::vector<UsuarioVIP> & VIPs, const std::string & nomArchivo){
    ifstream fichero;
    string linea;
    
    fichero.open(nomArchivo.c_str());
    UsuarioVIP nuevo_usuario;

    if(fichero.good()){
        for(int i = 0; i < !fichero.eof(); i++){
            getline(fichero, linea);
            nuevo_usuario.fromCSV(linea);

            VIPs.push_back(nuevo_usuario);
        }

        fichero.close();
        return true;
    }
    else
        //TODO: Manejo de errores
        throw runtime_error("El fichero no se ha podido abrir");
}

////////////////////////////////////////////////////////////////////

tm getLocalTime(){
    time_t      t1  = time(0);           // get time now
    struct tm* now  = localtime( & t1 ); // convert to local time
    

    now->tm_mon  += 1;
    now->tm_year += 1900;

    struct tm  copy = *now;              // make a local copy.
    return copy;
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

bool operator>(const tm & fecha1,const tm & fecha2){
    if (fecha1.tm_year <= fecha2.tm_year)
        return false;
    else if (fecha1.tm_mon <= fecha2.tm_mon)
        return false;
    else if (fecha1.tm_mday <= fecha2.tm_mday)
        return false;
    else
        return true;
}

bool operator>=(const tm & fecha1,const tm & fecha2){
    if (fecha1.tm_year < fecha2.tm_year)
        return false;
    else if (fecha1.tm_mon < fecha2.tm_mon)
        return false;
    else if (fecha1.tm_mday < fecha2.tm_mday)
        return false;
    else
        return true;
}

bool operator<(const tm & fecha1,const tm & fecha2){
    if (fecha1.tm_year >= fecha2.tm_year)
        return false;
    else if (fecha1.tm_mon >= fecha2.tm_mon)
        return false;
    else if (fecha1.tm_mday >= fecha2.tm_mday)
        return false;
    else
        return true;

}

bool operator<=(const tm & fecha1,const tm & fecha2){
    if (fecha1.tm_year > fecha2.tm_year)
        return false;
    else if (fecha1.tm_mon > fecha2.tm_mon)
        return false;
    else if (fecha1.tm_mday > fecha2.tm_mday)
        return false;
    else
        return true;
}