#include "UsuarioVIP.h"
#include "UsuarioVIP_functions.h"

using namespace std;

UsuarioVIP::UsuarioVIP (std::string name, int suscripcion):
    _nombre(name),
    _tipo_suscripcion(suscripcion)
{
    UpdateFechaLimite_local(suscripcion);
};

UsuarioVIP::UsuarioVIP(std::string name, int suscripcion, tm limit):
    _nombre(name),
    _tipo_suscripcion(suscripcion),
    _limite(limit)
{
};
////////////////////////////////////////////////////////////////////

string UsuarioVIP::GetName() const          {return this->_nombre;}

tm UsuarioVIP::GetFechaLimite() const       {return this->_limite;}

int UsuarioVIP::GetTipoSuscripcion() const  {return this->_tipo_suscripcion;}

////////////////////////////////////////////////////////////////////

void UsuarioVIP::setName(std::string nombre){
    this->_nombre = nombre;
};

void UsuarioVIP::setSuscripcion(int suscripcion){
    this->_tipo_suscripcion = suscripcion;
    this->UpdateFechaLimite_suscription(suscripcion);
};

////////////////////////////////////////////////////////////////////

void UsuarioVIP::UpdateFechaLimite_local(int suscripcion){
    tm *tmp;
    time_t fecha;
    time(&fecha);
    tmp = localtime(&fecha);

    this->_limite.tm_mday = tmp->tm_mday;
    this->_limite.tm_mon  = tmp->tm_mon  + 1 + suscripcion;
    this->_limite.tm_year = tmp->tm_year + 1900;
};

void UsuarioVIP::UpdateFechaLimite_suscription(int suscripcion){
    _limite.tm_mon += suscripcion;
};

void UsuarioVIP::UpdateFechaLimite_manual(int ano, int mes, int dia){
    this->_limite.tm_mday = dia;
    this->_limite.tm_mon  = mes;
    this->_limite.tm_year = ano;
};

////////////////////////////////////////////////////////////////////
string UsuarioVIP::toCSV() const{
    std::stringstream aux;

    // Ej:           nombre;1;27/10/2019
    aux << this->_nombre << ";" << this->_tipo_suscripcion << ";" << this->_limite.tm_mday << "/" 
        << this->_limite.tm_mon << "/" << this->_limite.tm_year << endl;

    return aux.str();
}

void UsuarioVIP::fromCSV(const string &cadena){
    stringstream ss;
    ss.str(cadena);

    string temp;

    getline(ss, this->_nombre,';');
    getline(ss, temp,';');
    this->_tipo_suscripcion = stoi(temp);

    getline(ss, temp,'/');
    this->_limite.tm_mday = stoi(temp);

    getline(ss, temp,'/');
    this->_limite.tm_mon = stoi(temp);

    getline(ss, temp);
    this->_limite.tm_year = stoi(temp);
}

////////////////////////////////////////////////////////////////////

UsuarioVIP& UsuarioVIP::operator=(const UsuarioVIP & nuevo_usuario){
    this->_nombre           = nuevo_usuario._nombre;
    this->_limite           = nuevo_usuario._limite;
    this->_tipo_suscripcion = nuevo_usuario._tipo_suscripcion;

    return *this;
}
