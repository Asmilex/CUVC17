#ifndef VIP_C17_functions 
#define VIP_C17_functions

#include "UsuarioVIP.h"
#include <fstream>

/**
 * @brief: Añade un UsuarioVIP a la lista de activos
 * @return: true si ha funcionado, else false
 */
bool AnadirUsuarioVIP(UsuarioVIP * VIPs, int dim, UsuarioVIP nuevo_usuario);

/**
 * @brief: Elimina un UsuarioVIP a la lista de activos
 * @return: true si ha funcionado, else false
 */
bool EliminarUsuarioVIP(UsuarioVIP * VIPs, int dim, std::string usuario);

/**
 * @brief: muestra los usuarios en pantalla
 */
void DisplayUsers(UsuarioVIP * VIPs, int dim);

/**
 * @brief: comprueba qué usuarios se han pasado de su fecha límite
 * Los que se hayan pasado, mueren
 */
bool LimitChecker(UsuarioVIP * VIPs, int dim);


////////////////////////////////////////////////////////////////////
void ReservarMemoria(UsuarioVIP * VIPs, int dim);


/**
 * @brief: amplia la lista de usuarios
 * @throw: std::out_of_range si se intenta aumentar memoria de forma negativa
 */
void AmpliarMemoria(int ampliacion, UsuarioVIP * VIPs, int dim);

////////////////////////////////////////////////////////////////////
/**
 * @brief: comprueba si existe el ficher
 * @return: true si existe, false en caso contrario
 */
bool FileExists(const std::string fileName="./UsuariosVIP.txt");

/**
 * @brief: devuelve el tamaño del archivo pasado
 */

std::ifstream::pos_type FileSize(std::string filename="./UsuariosVIP.txt");
/**
 * @brief: guarda los datos de los usuarios en un archivo de texto
 * @return: 
 */
bool SaveFile(const UsuarioVIP * VIPs, const unsigned int dim, const std::string nomArchivo="./UsuariosVIP.txt");

/**
 * @brief: recupera los datos de los usuarios a partir del archivo proporcionado
 * @return: 
 */
bool LoadFile(UsuarioVIP * VIPs, unsigned int & dim, const std::string nomArchivo="./UsuariosVIP.txt");

////////////////////////////////////////////////////////////////////
std::tm getLocalTime();

bool operator==(const tm & fecha1,const tm & fecha2);	
bool operator!=(const tm & fecha1,const tm & fecha2);
bool operator> (const tm & fecha1,const tm & fecha2);
bool operator>=(const tm & fecha1,const tm & fecha2);
bool operator< (const tm & fecha1,const tm & fecha2);
bool operator<=(const tm & fecha1,const tm & fecha2);

#endif