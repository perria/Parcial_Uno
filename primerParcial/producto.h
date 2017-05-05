
#include <stdio.h>
#include <stdlib.h>
//#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int precio;
    int stock;
    int estado;
    int idUsuario;
    int idProducto;

}EProducto;

int publicarProducto(EProducto registro[]);
int cancelarPublicacion(EProducto* pProducto, int length);
int producto_close(EProducto* pProducto, int length, int idProducto, int estado);
EProducto* producto_find(EProducto* pProducto, int length, int idProducto);

