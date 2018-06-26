#include <time.h>
#include "include/UsuarioVIP.h"

using namespace std;
	UsuarioVIP::UsuarioVIP(std::string name, int suscripcion, Fecha limit){


    }
    ////////////////////////////////////////////////////////////////////

    string UsuarioVIP::GetName() const{
        return this->_nombre;
    }

	Fecha UsuarioVIP::GetFechaLimite() const{
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
    void UsuarioVIP::setFechaLimite(Fecha fecha){


    }
    ////////////////////////////////////////////////////////////////////

	void UsuarioVIP::ActualizarSuscripcion(int suscription){


    }

    ////////////////////////////////////////////////////////////////////

    bool AnadirUsuarioVIP(UsuarioVIP *& VIPs){


    }

    bool EliminarUsuarioVIP(UsuarioVIP *& VIPs, std::string usuario){


    }
    void AmpliarMemoria(UsuarioVIP *& VIPs, int dimension){


    }