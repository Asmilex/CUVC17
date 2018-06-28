#include "UsuarioVIP.h"
#include <sstream>
#include <iostream>

using namespace std;

    UsuarioVIP::UsuarioVIP(std::string name, int suscripcion):
    _nombre(name),
    _tipo_suscripcion(suscripcion)
    {
        ModifyFechaLimite(suscripcion);
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

	void UsuarioVIP::ModifyFechaLimite(int suscripcion){
        tm *tmp;
        time_t fecha;
        time(&fecha);
        tmp = localtime(&fecha);

        this->_limite.tm_mday = tmp->tm_mday;
        this->_limite.tm_mon  = tmp->tm_mon  + 1 + suscripcion;
        this->_limite.tm_year = tmp->tm_year + 1900;
    }

    ////////////////////////////////////////////////////////////////////
    std::string UsuarioVIP::toCSV(){
        
        std::stringstream aux;
        aux << this->_nombre << ";" << this->_tipo_suscripcion << ";" << this->_limite.tm_mday << "/" << this->_limite.tm_mon << "/" << this->_limite.tm_year << endl;
        
        return aux.str();
        
    }
    
    void UsuarioVIP::fromCSV(std::string &cadena){        
        stringstream ss(cadena);
        getline(ss, _nombre,';');
        getline(ss, _tipo_suscripcion,';');
        getline(ss, _limite.tm_mday,'/');
        getline(ss, _limite.tm_mon,'/');
        ss.ignore();
        getline(ss, _limite.tm_year);
    }

    void UsuarioVIP::UpdateFechaLimite(int suscripcion){
        _limite.tm_mon  += suscripcion;
    }
    ////////////////////////////////////////////////////////////////////

    bool AnadirUsuarioVIP(UsuarioVIP *& VIPs, int dim, UsuarioVIP nuevo_usuario){
        AmpliarMemoria(VIPs, dim, 1);

        VIPs[dim-1] = nuevo_usuario;
        
        return true;
    }

    bool EliminarUsuarioVIP(UsuarioVIP *& VIPs, int dim, std::string usuario){
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

    void AmpliarMemoria(UsuarioVIP *& VIPs, int dim, int ampliacion){
        if (ampliacion <= 0){
            throw std::out_of_range("Aumento negativo imposible");
        }
        UsuarioVIP * temporal = new UsuarioVIP [dim + ampliacion];

        for (unsigned int i; i<dim; i++)
            temporal[i] = VIPs[i];
            
        dim += ampliacion;
        delete [] VIPs;

        VIPs = temporal;
    }
