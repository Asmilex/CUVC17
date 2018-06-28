#ifndef VIP_C17
#define VIP_C17

#include <string>
#include <ctime>

using namespace std;


class UsuarioVIP{
private:
	std::string _nombre;
	int _tipo_suscripcion;
	tm _limite;

public:
	UsuarioVIP(std::string name="", int suscripcion=1);
	UsuarioVIP(std::string name, int suscripcion, tm limit);

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
	tm GetFechaLimite() const;
	/**
	 * @brief: Devuelve el tipo de suscripción que tiene el UsuarioVIP
	 * @return: meses que contrató el UsuarioVIP
	 */
	int GetTipoSuscripcion() const;

	////////////////////////////////////////////////////////////////////
	/**
	 * @brief: modifica el nombre de UsuarioVIP
	 */
	void setName(std::string nombre);
	
	/**
	 * @brief: modifica el tipo de suscripción
	 */
	void setSuscripcion(int suscripcion);

	/**
	 * @brief: modifica la fecha limite
	 */
	void ModifyFechaLimite(int suscripcion=0);

	////////////////////////////////////////////////////////////////////
	
	
	void UpdateFechaLimite(int suscripcion);
    /**
     * @brief: devuelve datos como string en formato CSV
     */
    std::string toCSV();
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
bool EliminarUsuarioVIP(UsuarioVIP *& VIPs, int dim, std::string usuario);
/**
 * @brief: amplia la lista de usuarios
 */
void AmpliarMemoria(UsuarioVIP *& VIPs, int dimension, int ampliacion);

#endif
