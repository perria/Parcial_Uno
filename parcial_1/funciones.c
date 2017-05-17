#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"


#define CPRODUCTO 1000

void altaUsuario(EUsuario registro[])
{
    int i,aux, auxid;
    for(i=0; i<100; i++)
    {
        if(registro[i].estado==0)
        {
            registro[i].estado=1;
            auxid=generarID(registro,100);
            registro[i].idUsuario=auxid;
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

void inicioEstado(EProducto registro[])
{
    int i;
    for(i=0; i<100; i++)
    {
        registro[i].estado=0;
    }
}


int generarID(EUsuario* registro,int size)
{
    int i,j;
    int result=1;

    if(registro==NULL||size<1)
    {
        result=0;
    }

    else
    {
        for(i=0,j=1;i<size;i++)
        {
            if(registro[i].estado==1)
            {
                registro[i].idUsuario=j;
                j++;
            }
        }
    }
    return result;
}


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

int browseIndex(EUsuario* registro, int size, int idUsuario)
{
    int i;
    int result;

    if(registro==NULL||size<1)
    {
        printf("Error en buscar indice");
        result=-1;
    }

    else
    {
        result=-1;

        for(i=0;i<size;i++)
        {
            if(registro[i].estado==0)
                continue;

            if(registro[i].idUsuario==idUsuario)
            {
                result=i;
            }
        }
    }
    return result;
}

int modificarUsuario(EUsuario* registro, int size, int idUsuario, char* nombre, int password)
{
    int retorno=-1, i, mod, aux;
    EUsuario* pAuxUsuario;

    printf("Ingrese ID de la persona a modificar: ");
    fflush(stdin);
    scanf("%d",&mod);


   for(i=0;i<100;i++)
   {

    //if(registro != NULL && size > 0)
    if(registro[i].idUsuario==mod)
    {
        /*pAuxUsuario = browseIndex(registro,100,idUsuario);
        if(pAuxUsuario != NULL)
        {
            strcpy(pAuxUsuario->nombre,nombre);
            pAuxUsuario[i].password = password;
            retorno=0;
        }*/
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
    return retorno;
}


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

int publicarProducto(EProducto registro[])
{
    int retorno=-1, i, idper,auxid;


        printf("Ingrese ID de la persona: ");
        fflush(stdin);
        scanf("%d",&idper);

        for(i=0;i<100;i++)
        {

        if(registro[i].idUsuario==idper)
        {
            registro[i].estado=1;
            auxid=generarID(registro,1000);
            registro[i].idProducto=auxid;
            printf("Ingrese nombre de producto: ");
            fflush(stdin);
            gets(registro[i].nombre);
            printf("Ingrese precio:");
            fflush(stdin);
            scanf("%d",&registro[i].precio);
            printf("Ingrese stock:");
            fflush(stdin);
            scanf("%d",&registro[i].stock);

        }
        }

    return retorno;
}

int modificarPublicacion(EProducto* registro, int size, int idProducto, char* nombre, int precio, int stock)
{
    int retorno=-1, i, mod, aux, modp;
    EUsuario* pAuxUsuario;

    printf("Ingrese ID usuario: ");
    fflush(stdin);
    scanf("%d",&mod);


   for(i=0;i<100;i++)
   {

    if(registro[i].idUsuario==mod)
    {
        printf("Ingrese ID de producto");
        fflush(stdin);
        scanf("%d",&modp);
        for(i=0;i<1000;i++)
        {
            if(registro[i].idProducto==modp)
            {
            printf("Ingrese nombre de producto: ");
            fflush(stdin);
            gets(registro[i].nombre);
            printf("Ingrese precio:");
            fflush(stdin);
            scanf("%d",&registro[i].precio);
            printf("Ingrese stock:");
            fflush(stdin);
            scanf("%d",&registro[i].stock);
            }
        }


            break;
    }
   }
    return retorno;
}


void listarPublicaciones(EProducto registro[])
{
    EProducto auxStruct;
    int i,j;
    int s=1;

    while(s)
    {
        s=0;
        for(i=1; i<1000; i++)
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
            printf("%s---%d---%d\n",registro[i].nombre,registro[i].idProducto);
        }
    }
}
