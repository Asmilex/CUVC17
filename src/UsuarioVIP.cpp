#include "UsuarioVIP.h"
#include <sstream>

using namespace std;

    UsuarioVIP::UsuarioVIP(std::string name, int suscripcion):
    _nombre(name),
    _tipo_suscripcion(suscripcion)
    {
        tm *tmp;
        time_t fecha;
        time(&fecha);
        tmp = localtime(&fecha);

        this->_limite.tm_mday = tmp->tm_mday;
        this->_limite.tm_mon  = tmp->tm_mon  + 1 + suscripcion;
        this->_limite.tm_year = tmp->tm_year +1900;
        
    }

    UsuarioVIP::UsuarioVIP(std::string name, int suscripcion, tm limit):
    _nombre(name),
    _tipo_suscripcion(suscripcion),
    _limite(limit)
    {
    }
    ////////////////////////////////////////////////////////////////////

    string UsuarioVIP::GetName() const{
        return this->_nombre;
    }

	tm UsuarioVIP::GetFechaLimite() const{
        return this->_limite;
    }

	int UsuarioVIP::GetTipoSuscripcion() const{
        return this->_tipo_suscripcion;
    }

    ////////////////////////////////////////////////////////////////////

	void UsuarioVIP::setName(std::string nombre){
        this->_nombre = nombre;
    }

	void UsuarioVIP::setSuscripcion(int suscripcion){
        this->_tipo_suscripcion = suscripcion;
        this->UpdateFechaLimite(suscripcion);
    }

	//void UsuarioVIP::setFechaLimite(int suscripcion){}
    //void UsuarioVIP::setFechaLimite(tm fecha){

    ////////////////////////////////////////////////////////////////////
    std::string UsuarioVIP::toCSV(){
        
        std::stringstream aux;
        aux << this->_nombre << ";" << this->_tipo_suscripcion << ";" << this->_limite.tm_mday << "/" << this->_limite.tm_mon << "/" << this->_limite.tm_year << endl;
        
        return aux.str();
        
    }
    
    void UsuarioVIP::fromCSV(std::string &cadena){
        
        std::stringstream ss(cadena);
        std::getline(ss,_nombre,';');
        std::getline(ss,_tipo_suscripcion,';');
        std::getline(ss,_limite.tm_mday,'/');
        std::getline(ss,_limite.tm_mon,'/');
        ss.ignore();
        std::getline(ss,_limite.tm_year);
        
    }

    void UsuarioVIP::UpdateFechaLimite(int suscripcion){
        _limite.tm_mon  += suscripcion;
    }
    ////////////////////////////////////////////////////////////////////

    bool AnadirUsuarioVIP(UsuarioVIP *& VIPs, int dim, UsuarioVIP nuevo_usuario){
        AmpliarMemoria(VIPs, 1);

        VIPs[dim-1] = nuevo_usuario;
        
        return true;
    }

    bool EliminarUsuarioVIP(UsuarioVIP *& VIPs, std::string usuario){


    }
    void AmpliarMemoria(UsuarioVIP *& VIPs, int dimension){


    }
