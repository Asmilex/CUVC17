#ifndef VIP_C17_functions 
#define VIP_C17_functions

#include "UsuarioVIP.h"
#include <algorithm>
#include <fstream>
#include <iomanip> //flags para cout
#include <iostream>
#include <vector>

/**
 * @brief: Añade un UsuarioVIP a la lista de activos
 * @return: true si ha funcionado, else false
 */
bool AnadirUsuarioVIP(std::vector<UsuarioVIP> & VIPs,const UsuarioVIP & nuevo_usuario);

/**
 * @brief: Elimina un UsuarioVIP a la lista de activos
 * @return: true si ha funcionado, else false
 */
bool EliminarUsuarioVIP(std::vector<UsuarioVIP> & VIPs, const std::string usuario);
bool EliminarUsuarioVIP(std::vector<UsuarioVIP> & VIPs, const size_t posicion);

/**
 * @brief: muestra los usuarios en pantalla
 */
void DisplayUsers(const std::vector<UsuarioVIP> & VIPs);

/**
 * @brief: función patética que limpia la pantalla
 */
void ClearScreen();

/**
 * @brief: comprueba qué usuarios se han pasado de su fecha límite
 * Los que se hayan pasado, mueren
 * @return: si se han borrado usuarios
 */
bool AutoEliminador(std::vector<UsuarioVIP> & VIPs);

////////////////////////////////////////////////////////////////////
/**
 * @brief: comprueba si existe el ficher
 * @return: true si existe, false en caso contrario
 */
bool FileExists(const std::string & fileName="./UsuariosVIP.cuvc");

/**
 * @brief: devuelve el tamaño del archivo pasado
 */

std::ifstream::pos_type FileSize(const std::string & filename="./UsuariosVIP.cuvc");
/**
 * @brief: guarda los datos de los usuarios en un archivo de texto
 * @return: 
 */
bool SaveFile(const std::vector<UsuarioVIP> & VIPs, const std::string & nomArchivo="./UsuariosVIP.cuvc");

/**
 * @brief: recupera los datos de los usuarios a partir del archivo proporcionado
 * @return: 
 */
bool LoadFile(std::vector<UsuarioVIP> & VIPs, const std::string & nomArchivo="./UsuariosVIP.cuvc");

////////////////////////////////////////////////////////////////////
std::tm getLocalTime();

/**
 * @brief coge una fecha y la convierte a una estructura del tipo YYYYMMDD (Year - Month - Day)
 * @return codificación
 */
long int tm_to_int(const tm fecha);

// Operator overloading. Bastante lógico lo que hacen
bool operator==(const tm & fecha1,const tm & fecha2);	
bool operator!=(const tm & fecha1,const tm & fecha2);
bool operator> (const tm & fecha1,const tm & fecha2);
bool operator>=(const tm & fecha1,const tm & fecha2);
bool operator< (const tm & fecha1,const tm & fecha2);
bool operator<=(const tm & fecha1,const tm & fecha2);

/**
 * @brief: converts string to lowercase
 * @return: same string on lowercase
 */

std::string str_tolower(std::string estrin);
#endif