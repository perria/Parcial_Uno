#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"
#include "producto.h"

#define CPRODUCTO 1000

int main()
{
    char seguir='s';
    int opcion=0;
    int i,j, idUsuario,  password;
    char nombre;

    EUsuario registro[100],auxStruct;

    inicioEstado(registro);

    while(seguir=='s')
    {
        opcion = menu("1- Alta usuario\n2- Modificar usuario \n3- Baja usuario\n4- Publicar producto\n5- Modificar publicacion\n6- Cancelar publicacion\n7- Comprar producto\n8- Listar publicaciones de usuario\n9- Listar publicaciones\n10- Listar usuarios\n","Error ingrese nuevamente una opcion entre 1 y 5: ");

        switch(opcion)
        {
           case 1:
                altaUsuario(registro);
                break;
           case 2:
               modificarUsuario(registro, 100, idUsuario, nombre, password);
                break;
           case 3:
                bajaUsuario(registro);
                break;
           case 4:
                publicarProducto(registro);
                break;
            case 5:
                modificarPublicacion(registro);
                break;
            case 6:
                cancelarPublicacion(registro, 100);
                break;
            case 7:
                comprarProducto(registro);
                break;
            case 8:
                listarPubliUsuario(registro);
                break;
            case 9:
                listarPublicaciones(registro);
                break;
            case 10:
                listarUsuarios(registro);
                break;
            case 11:
                seguir = 'n';
                break;
        }
    }


    return 0;
}
