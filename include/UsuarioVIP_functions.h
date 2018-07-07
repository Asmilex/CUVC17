#ifndef VIP_C17_functions 
#define VIP_C17_functions

#include "UsuarioVIP.h"
#include <fstream>
#include <vector>

/**
 * @brief: Añade un UsuarioVIP a la lista de activos
 * @return: true si ha funcionado, else false
 */
bool AnadirUsuarioVIP(std::vector<UsuarioVIP> & VIPs,const UsuarioVIP nuevo_usuario);

/**
 * @brief: Elimina un UsuarioVIP a la lista de activos
 * @return: true si ha funcionado, else false
 */
bool EliminarUsuarioVIP(std::vector<UsuarioVIP> & VIPs, const std::string usuario);

/**
 * @brief: muestra los usuarios en pantalla
 */
void DisplayUsers(const std::vector<UsuarioVIP> & VIPs);

/**
 * @brief: comprueba qué usuarios se han pasado de su fecha límite
 * Los que se hayan pasado, mueren
 */
bool LimitChecker(const std::vector<UsuarioVIP> & VIPs);

////////////////////////////////////////////////////////////////////
/**
 * @brief: comprueba si existe el ficher
 * @return: true si existe, false en caso contrario
 */
bool FileExists(const std::string & fileName="./UsuariosVIP.txt");

/**
 * @brief: devuelve el tamaño del archivo pasado
 */

std::ifstream::pos_type FileSize(const std::string & filename="./UsuariosVIP.txt");
/**
 * @brief: guarda los datos de los usuarios en un archivo de texto
 * @return: 
 */
bool SaveFile(const std::vector<UsuarioVIP> & VIPs, const std::string & nomArchivo="./UsuariosVIP.txt");

/**
 * @brief: recupera los datos de los usuarios a partir del archivo proporcionado
 * @return: 
 */
bool LoadFile(std::vector<UsuarioVIP> & VIPs, const std::string & nomArchivo="./UsuariosVIP.txt");

////////////////////////////////////////////////////////////////////
std::tm getLocalTime();

bool operator==(const tm & fecha1,const tm & fecha2);	
bool operator!=(const tm & fecha1,const tm & fecha2);
bool operator> (const tm & fecha1,const tm & fecha2);
bool operator>=(const tm & fecha1,const tm & fecha2);
bool operator< (const tm & fecha1,const tm & fecha2);
bool operator<=(const tm & fecha1,const tm & fecha2);

#endif