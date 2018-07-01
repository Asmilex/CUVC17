#include "UsuarioVIP_functions.h"
#include <fstream>
#include <iostream>
#include <iomanip> //flags para cout
using namespace std;


//TODO: Comprobar que los usuarios no se pasen del día

bool AnadirUsuarioVIP(UsuarioVIP * VIPs, int dim, UsuarioVIP nuevo_usuario){
    AmpliarMemoria(1, VIPs, dim);

    VIPs[dim-1] = nuevo_usuario;
    
    return true;
}

bool EliminarUsuarioVIP(UsuarioVIP * VIPs, int dim, std::string usuario){
    UsuarioVIP * temporal = new UsuarioVIP [dim-1];

    unsigned int iterador_temp = 0;
    
    for (unsigned int i; i<dim; i++)
        if (VIPs[i].GetName() != usuario){
            temporal[iterador_temp] = VIPs[i];
            iterador_temp++;
        }
    
    dim--;
    delete [] VIPs;

    VIPs = temporal;
}

void DisplayUsers(UsuarioVIP * VIPs, int dim){
    if (VIPs != nullptr){
        cout <<setw(30)<<left<<setfill(' ')<<"Usuario"<<"Suscripcion         ";  
        cout <<"Fecha"<<endl;

        cout.width(58);
        cout.fill('-');
        cout<<"-"<<endl;

        for (int i=0; i<dim; i++){
            cout <<setw(30)<<left<<setfill(' ')<<VIPs[i].GetName()<<"     "<<VIPs[i].GetTipoSuscripcion()<<"            ";
            cout <<right<<VIPs[i].GetFechaLimite().tm_mday<<"/"
                        <<VIPs[i].GetFechaLimite().tm_mon <<"/"
                        <<VIPs[i].GetFechaLimite().tm_year<<endl;
        }
    }
    else
        cout << endl << "No hay usuarios almacenados en la base de datos"<< endl;
}

bool LimitChecker(UsuarioVIP * VIPs, int dim){
    if (VIPs == nullptr)
        return false;
    
    for (unsigned int i=0; i < dim; i++){
        if (VIPs[i].GetFechaLimite() > getLocalTime())
            cout <<"FIXME";

    }

}
////////////////////////////////////////////////////////////////////

void AmpliarMemoria(int ampliacion, UsuarioVIP * VIPs, int dim){
    if (ampliacion <= 0){
        throw out_of_range("Aumento negativo o nulo imposible");
    }

    UsuarioVIP * temporal = new UsuarioVIP [dim + ampliacion];

    if (VIPs != nullptr){
        for (unsigned int i; i<dim; i++)
            temporal[i] = VIPs[i];
        
        delete [] VIPs;
    }

    dim += ampliacion;

    VIPs = temporal;
}

////////////////////////////////////////////////////////////////////
bool FileExists(const std::string fileName){
    ifstream infile(fileName);
    return infile.good();
}

int SaveFile(const UsuarioVIP * VIPs, const unsigned int dim, const string nomArchivo){
    ofstream fichero;

    fichero.open(nomArchivo);

    if (fichero){
        fichero << dim;

        for (unsigned int i=0; i<dim; i++)
            fichero <<VIPs[i].toCSV();

        fichero.close();
    }
    else
        throw std::runtime_error("El fichero no se ha podido abrir");
}

ifstream::pos_type FileSize(string filename){
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg(); 
}

//TODO: La devolución la has puesto como entera a posta, o ha sido un error?
int LoadFile(UsuarioVIP * VIPs, unsigned int & dim, const string nomArchivo){
    ifstream fichero;
    string linea;
    
    fichero.open(nomArchivo.c_str());
    
    if(fichero.good()){
        fichero >> dim;
        
        AmpliarMemoria(dim);

        for(int i = 0; i < dim; i++){
            getline(fichero, linea);
            
            if(fichero.eof()) 
                break;
            
            VIPs[i].fromCSV(linea);
        }
        fichero.close();
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

bool operator==(tm fecha1, tm fecha2){
    if (fecha1.tm_year == fecha2.tm_year && 
        fecha1.tm_mon  == fecha2.tm_mon  &&
        fecha1.tm_mday == fecha2.tm_mday)
        
        return true;
    else
        return false;

}

bool operator!=(tm fecha1, tm fecha2){
    if (fecha1.tm_year == fecha2.tm_year && 
        fecha1.tm_mon  == fecha2.tm_mon  &&
        fecha1.tm_mday == fecha2.tm_mday)
        
        return false;
    else
        return true;
}

bool operator>(tm fecha1, tm fecha2){
    if (fecha1.tm_year <= fecha2.tm_year)
        return false;
    else if (fecha1.tm_mon <= fecha2.tm_mon)
        return false;
    else if (fecha1.tm_mday <= fecha2.tm_mday)
        return false;
    else
        return true;
}

bool operator>=(tm fecha1, tm fecha2){
    if (fecha1.tm_year < fecha2.tm_year)
        return false;
    else if (fecha1.tm_mon < fecha2.tm_mon)
        return false;
    else if (fecha1.tm_mday < fecha2.tm_mday)
        return false;
    else
        return true;
}

bool operator<(tm fecha1, tm fecha2){
    if (fecha1.tm_year >= fecha2.tm_year)
        return false;
    else if (fecha1.tm_mon >= fecha2.tm_mon)
        return false;
    else if (fecha1.tm_mday >= fecha2.tm_mday)
        return false;
    else
        return true;

}

bool operator<=(tm fecha1, tm fecha2){
    if (fecha1.tm_year > fecha2.tm_year)
        return false;
    else if (fecha1.tm_mon > fecha2.tm_mon)
        return false;
    else if (fecha1.tm_mday > fecha2.tm_mday)
        return false;
    else
        return true;

}