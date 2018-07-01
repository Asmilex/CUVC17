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

	////////////////////////////////////////////////////////////////////
	/**
	 * @brief: modifica la fecha limite atendiendo a la hora actual
	 * @param suscripcion: meses añadidos a la fecha límite. Si es 0, se usa la hora local
	 */
	void UpdateFechaLimite_local(int suscripcion=0);

	/**
	 * @brief: modifica la fecha límite, actualizándola según la nueva suscripción
	 * @param suscripcion: meses añadidos a la fecha límite
	 */
	void UpdateFechaLimite_suscription(int suscripcion);
	
	/**
	 * @brief: modifica la fecha limite, introduciendo manualmente las fechas
	 * @pre: tienen un formato válido
	 */
	void UpdateFechaLimite_manual(int ano, int mes, int dia);
	////////////////////////////////////////////////////////////////////
    
    /**
     * @brief: devuelve datos como string en formato CSV
     * @return: string con los datos separados por ;
     */
    std::string toCSV() const;
    
    /**
     * @brief: Recupera datos en formato CSV
     * 
     */
    void fromCSV(const std::string &cadena);

	////////////////////////////////////////////////////////////////////
};

#endif
