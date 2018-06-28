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

        if (suscripcion == 1 || suscripcion == 3){
            this->_limite.tm_mday = tmp->tm_mday;
            this->_limite.tm_mon  = tmp->tm_mon  + 1 + suscripcion;
            this->_limite.tm_year = tmp->tm_year +1900;
        }
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
    }

	void UsuarioVIP::setFechaLimite(int suscripcion){


    }
    void UsuarioVIP::setFechaLimite(tm fecha){


    }
    ////////////////////////////////////////////////////////////////////

	void UsuarioVIP::ActualizarSuscripcion(int suscription){


    }

    std::string UsuarioVIP::toCSV(){
        
        std::stringstream aux;
        aux << this->_nombre << ";" << this->_tipo_suscripcion << ";" << this->_limite.tm_mday << "/" << this->_limite.tm_mon << "/" << this->_limite.tm_year << endl;
        
        return aux.str();
        
    }
    ////////////////////////////////////////////////////////////////////

    bool AnadirUsuarioVIP(UsuarioVIP *& VIPs){


    }

    bool EliminarUsuarioVIP(UsuarioVIP *& VIPs, std::string usuario){


    }
    void AmpliarMemoria(UsuarioVIP *& VIPs, int dimension){


    }
