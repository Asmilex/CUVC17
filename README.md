# Controlador de Usuarios VIP de Comunidad 17 (CUVC17)
Base de datos extremadamente ligera escrita en C++. Añade usuarios con permisos especiales (como VIPs en servidores) y controla la fecha de caducidad de dicho servicio. Originalmente producido para controlar la base de datos de [Comunidad 17](https://steamcommunity.com/groups/Comunidad17)
## Dependencias:
### Building
- `Cmake`
- (Windows only)`MinGW`, añadido a `PATH`

## Instrucciones para compilar 
## Windows:
0. Edita el archivo CMakeLists.txt, quitándole la almohadilla `#` en las líneas 4 y 5
1. `cmake . -G "MinGW Makefiles"`
2. `make`
## Linux: 
1. `cmake` 
2. `make`
