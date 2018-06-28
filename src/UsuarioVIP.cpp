#include "UsuarioVIP.h"

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

    UsuarioVIP::UsuarioVIP(std::string name, int suscripcion, tm limit){


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

    void UsuarioVIP::UpdateFechaLimite(int suscripcion){
        _limite.tm_mon  += suscripcion;
    }

    ////////////////////////////////////////////////////////////////////

	void UsuarioVIP::UpdateSuscripcion(int suscription){


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