#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"
#include "usuario.h"

void inicioEstado(EProducto registro[])
{
    int i;
    for(i=0; i<100; i++)
    {
        registro[i].estado=0;
    }
}



int publicarProducto(EProducto registro[])
{
    int retorno=-1, i, idper;


        printf("Ingrese ID de la persona: ");
        fflush(stdin);
        scanf("%d",&idper);

        if(registro[i].idUsuario==idper)
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

    return retorno;
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int cancelarPublicacion(EProducto* pProducto, int length)
{
    int id, tiempo,estado;
    EProducto* pAuxProducto;

    int retorno=-1;



        pAuxProducto = producto_find(pProducto, length, id);
        if(pAuxProducto == NULL)
        {
            printf("el producto no existe\n");

        }
        else
        {

                    producto_close(pProducto, length,id, estado);

        }

    return retorno;
}



EProducto* producto_find(EProducto* pProducto, int length, int idProducto)
{
    EProducto* pRetorno = NULL;
    int i;
    if(pProducto != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if((pProducto+i)->idProducto == idProducto && (pProducto+i)->estado == 1)
            {
                pRetorno = (pProducto+i);
                break;
            }
        }
    }
    return pRetorno;
}


int producto_close(EProducto* pProducto, int length, int idProducto, int estado)
{
    int retorno=-1;
    EProducto* pAuxProducto;

    if(pProducto != NULL && length > 0)
    {
        pAuxProducto = producto_find(pProducto, length,idProducto);
        if(pAuxProducto != NULL)
        {
             pAuxProducto->estado = estado;
            retorno=0;
        }
    }
    return retorno;
}

