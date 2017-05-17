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

typedef struct {

    char nombre[50];
    int password;
    int estado;
    int idUsuario;
    int idProducto;

}EUsuario;

void altaUsuario(EUsuario registro[]);
void inicioEstado(EProducto registro[]);
void inicioEstadoU(EUsuario registro[]);
 int menu(char mensaje[],char error[]);
int generarID(EUsuario* registro,int size);
void listarUsuarios(EUsuario registro[]);
int browseIndex(EUsuario* registro, int size, int idUsuario);
int modificarUsuario(EUsuario* registro, int size, int idUsuario, char* nombre, int password);
int bajaUsuario(EUsuario registro[]);
int publicarProducto(EProducto registro[]);
int modificarPublicacion(EProducto* registro, int size, int idProducto, char* nombre, int precio, int stock);
void listarPublicaciones(EProducto registro[]);

