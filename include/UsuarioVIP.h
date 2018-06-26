#ifndef VIP_C17
#define VIP_C17

#include <string>

using namespace std;

struct Fecha{
	int ano;
	int mes;
	int dia;
};

class UsuarioVIP{
private:
	std::string _nombre;
	int _tipo_suscripcion;
	Fecha _limite;

public:
	UsuarioVIP();
	UsuarioVIP(std::string name, int suscripcion, Fecha limit);
	UsuarioVIP(std::string name, int suscripcion);

	////////////////////////////////////////////////////////////////////
	/**
	 * @brief: Devuelve el nombre del UsuarioVIP
	 * @return: nombre del UsuarioVIP
	 */
	std::string GetName() const;
	/**
	 * @brief: Devuelve la fecha en la que expirará la suscripción
	 * @return: Fecha límite
	 */
	Fecha GetFechaLimite() const;
	/**
	 * @brief: Devuelve el tipo de suscripción que tiene el UsuarioVIP
	 * @return: meses que contrató el UsuarioVIP
	 */
	int GetTipoSuscripcion() const;

	////////////////////////////////////////////////////////////////////
	/**
	 * @brief: modifica el nombre de UsuarioVIP
	 */
	void setName();
	
	/**
	 * @brief: modifica el tipo de suscripción
	 */
	void setSuscripcion();

	/**
	 * @brief: modifica la fecha limite
	 */
	void setFechaLimite();

	////////////////////////////////////////////////////////////////////
	/**
	 * @brief: mejora la suscripcion y actualiza la fecha límite
	 */
	void ActualizarSuscripcion(int suscription);
};


/**
 * @brief: Añade un UsuarioVIP a la lista de activos
 * @return: true si ha funcionado, else false
 */
bool AnadirUsuarioVIP(UsuarioVIP *& VIPs);

/**
 * @brief: Elimina un UsuarioVIP a la lista de activos
 * @return: true si ha funcionado, else false
 */
bool EliminarUsuarioVIP(UsuarioVIP *& VIPs, std::string usuario);
/**
 * 
 */
void AmpliarMemoria(UsuarioVIP *& VIPs, int dimension);

#endif