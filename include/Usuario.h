#ifndef VIP_C17
#define VIP_C17

#include <string>

using namespace std;

struct Fecha{
	int ano;
	int mes;
	int dia;
};

class Usuario{
private:
	std::string _nombre;
	int _tipo_suscripcion;
	Fecha _limite;

public:
	Usuario();
	Usuario(std::string name, int suscripcion, Fecha limit);
	Usuario(std::string name, int suscripcion);

	////////////////////////////////////////////////////////////////////
	/**
	 * @brief: Devuelve el nombre del usuario
	 * @return: nombre del usuario
	 */
	std::string GetName() const;
	/**
	 * @brief: Devuelve la fecha en la que expirará la suscripción
	 * @return: Fecha límite
	 */
	Fecha GetFechaLimite() const;
	/**
	 * @brief: Devuelve el tipo de suscripción que tiene el usuario
	 * @return: meses que contrató el usuario
	 */
	int GetTipoSuscripcion() const;

	////////////////////////////////////////////////////////////////////
	/**
	 * @brief: modifica el nombre de usuario
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
 * @brief: Añade un usuario a la lista de activos
 * @return: true si ha funcionado, else false
 */
bool AnadirUsuario(Usuario *& VIPs);

#endif