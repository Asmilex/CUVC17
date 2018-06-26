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
	std::string Nombre;
	int tipo_suscripcion;
	Fecha limite;
public:
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

};

#endif