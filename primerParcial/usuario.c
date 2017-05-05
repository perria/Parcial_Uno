#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuario.h"


#define CPRODUCTO 1000

/**
 * Inicializa el estado en "0".
 * @param lista el array se pasa como parametro.
 */


void inicioEstadoU(EUsuario registro[])
{
    int i;
    for(i=0; i<100; i++)
    {
        registro[i].estado=0;
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 int menu(char mensaje[],char error[])
{
    int op,aux;
    printf("%s",mensaje);
    aux=scanf("%d",&op);
    fflush(stdin);
    while(aux==0 ||(op<1||op>11))
    {
        printf("%s",error);
        fflush(stdin);
        aux=scanf("%d",&op);
    }
    return op;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


 void altaUsuario(EUsuario registro[])
{
    int i,aux, auxid;
    for(i=0; i<100; i++)
    {
        if(registro[i].estado==0)
        {
            registro[i].estado=1;
            printf("Ingrese nombre de usuario: ");
            fflush(stdin);
            gets(registro[i].nombre);
            printf("Ingrese una contraseña de cuatro numeros:");
            fflush(stdin);
            aux=scanf("%d",&registro[i].password);
            while(aux==0 || (registro[i].password<1000 || registro[i].password>10000))
            {
                printf("Ingrese contraseña nuevamente: ");
                fflush(stdin);
                aux=scanf("%d",&registro[i].password);
            }


            break;
        }
    }
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int bajaUsuario(EUsuario registro[])
{
    int i,flag=0;
    int borrar;
    char pregBorrar;
    printf("Ingrese ID de la persona a borrar: ");
    fflush(stdin);
    scanf("%d",&borrar);
    for(i=0; i<100; i++)
    {
        if(registro[i].idUsuario==borrar)
        {
            printf("Esta seguro que desea borrar a %s (s/n)\n",registro[i].nombre);
            pregBorrar=getche();
            printf("\n");
            if(pregBorrar == 's')
            {
                registro[i].estado=0;

            }
            else
            {
                printf("Accion cancelada\n");
            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("No existe persona con ese ID!\n");

    }
    return registro[i].estado;
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


int usuario_append(EUsuario* pUsuario, char nombre[], int password, int length)
{

    int retorno=-1;
    int id,index;
    if(pUsuario != NULL && 100 > 0)
    {
        index = usuario_findEmptyPlace(pUsuario, length);
        if(index != -1)
        {
            id = usuario_findNextId(pUsuario, length);
            strcpy((pUsuario+index)->nombre,nombre);
            (pUsuario+index)->password = password;
            (pUsuario+index)->idUsuario = id;
            (pUsuario+index)->estado =  1;
            retorno=0;
        }
    }
    return retorno;
}


/** \brief  Busca en el array la primer posicion libre
 * \param EUsuario* pUsuario Puntero al array de abonados
 * \param 100 int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (index del lugar libre) si Ok
 *
 */
int usuario_findEmptyPlace(EUsuario* pUsuario, int length)
{
    int i;
    int retorno=-1;
    if(pUsuario != NULL && 100 > 0)
    {
        for(i=0;i<100;i++)
        {
            if((pUsuario+i)->estado == 0)
            {
                retorno = i;
                break;
            }
        }

    }
    return retorno;
}

/** \brief  Busca en el array el id mas alto entre los usados y los borrados
 * \param sAbonado* pUsuario Puntero al array de abonados
 * \param 100 int Longitud del array
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL] - (proximo ID) si Ok
 *
 */
int usuario_findNextId(EUsuario* pUsuario, int length)
{
    int i, maxId=-1;
    int retorno=-1;
    if(pUsuario != NULL && 100 > 0)
    {
        for(i=0;i<100;i++)
        {
            if((pUsuario+i)->estado == 1 || (pUsuario+i)->estado == 0)
            {
                if((pUsuario+i)->idUsuario > maxId || maxId == -1)
                    maxId = (pUsuario+i)->idUsuario;
            }
        }
        retorno = maxId+1;
    }
    return retorno;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void listarUsuarios(EUsuario registro[])
{
    EUsuario auxStruct;
    int i,j;
    int s=1;

    while(s)
    {
        s=0;
        for(i=1; i<100; i++)
        {
            if(stricmp(registro[i].nombre,registro[i-1].nombre)<0)
            {
                auxStruct = registro[i];
                registro[i]= registro[i-1];
                registro[i-1]= auxStruct;
                s=1;
            }
        }
    }

    for(i=0; i<100; i++)
    {
        if(registro[i].estado==1)
        {
            printf("%s---%d---%d\n",registro[i].nombre,registro[i].idUsuario);
        }
    }
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 /** \brief Modifica el nombre y la contraseña de un usuario existente
 *
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \param idAbonado int ID del abonado
 * \param nombre int Nombre del abonado
 * \param apellido int Apellido del abonado
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o si la longitud del nombre/apellido es < 1] - (0) si Ok
 *
 */
int modificarUsuario(EUsuario* pUsuario, int length, int idUsuario, char* nombre, int password)
{
    int retorno=-1, i;
    EUsuario* pAuxUsuario;

    if(pUsuario != NULL && length > 0)
    {
        pAuxUsuario = usuario_find(pUsuario, length,idUsuario);
        if(pAuxUsuario != NULL)
        {
            strcpy(pAuxUsuario->nombre,nombre);
            pAuxUsuario[i].password = password;
            retorno=0;
        }
    }
    return retorno;
}


/** \brief Busca en la lista un abonado que coincida con el Id recibido
 *
 * \param sAbonado* pAbonados Puntero al array de abonados
 * \param length int Longitud del array
 * \param idAbonado int ID del abonado
 * \return int Return (-1) si hay un Error [Longitud invalida o puntero NULL o sin no se encontro el abonado] - (0) si Ok
 *
 */
EUsuario* usuario_find(EUsuario* pUsuario, int length, int idUsuario)
{
    EUsuario* pRetorno = NULL;
    int i;
    if(pUsuario != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if((pUsuario+i)->idUsuario == idUsuario && (pUsuario+i)->estado == 1)
            {
                pRetorno = (pUsuario+i);
                break;
            }
        }
    }
    return pRetorno;
}

