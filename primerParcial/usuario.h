#include <stdio.h>
#include <stdlib.h>
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int password;
    int estado;
    int idUsuario;
    int idProducto;

}EUsuario;


void inicioEstadoU(EUsuario registro[]);
int menu(char mensaje[],char error[]);
void altaUsuario(EUsuario registro[]);
 int usuario_append(EUsuario* pUsuario, char nombre[], int password, int length);
 int bajaUsuario(EUsuario registro[]);
 int usuario_findEmptyPlace(EUsuario* pUsuario, int length);
 int usuario_findNextId(EUsuario* pUsuario, int length);
 void listarUsuarios(EUsuario registro[]);
 int modificarUsuario(EUsuario* pUsuario, int length, int idUsuario, char* nombre, int password);
 EUsuario* usuario_find(EUsuario* pUsuario, int length, int idUsuario);
 char getNumeroAleatorio(int desde , int hasta, int iniciar);











#endif // FUNCIONES_H_INCLUDED
