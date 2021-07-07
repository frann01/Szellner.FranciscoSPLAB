#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include "paises.h"
#include "parser.h"


/** \brief Carga los datos de los paises desde el archivo ingreasado (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayList)
{
    int counter = 0;
    FILE* file = NULL;

    if(pArrayList != NULL)
    {
        file = fopen(path, "r");
        if(file != NULL)
        {
            counter = parser_FromText(file, pArrayList);
        }
    }

    fclose(file);
    return counter;
}



/** \brief Listar paises
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListPaises(LinkedList* pArrayList)
{
    int todoOk=1;
    int tam=0;
    Node* puntero= NULL;

    if(pArrayList!=NULL)
    {
        tam = ll_len(pArrayList);
        puntero = pArrayList->pFirstNode;
        printf(" ID         nombre           1 Vacuna    2 Vacunas         Sin Vacunar \n");
        printf("----------------------------------------------------------------------\n");
        if(puntero!=NULL)
        {
            mostrarPais(puntero->pElement);
            for(int i =0; i<tam-1; i++)
            {
                puntero = puntero->pNextNode;
                mostrarPais(puntero->pElement);
                todoOk=0;
            }
            printf("\n\n");
        }

    }
    if(tam<1)
    {
        printf("No hay articulos cargados! \n");
    }
    return todoOk;
}

/** \brief Guarda unlinkedList en un archivo de texto
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    FILE* file = NULL;
    int retorno = 0;
    int tam;
    int i;
    ePaises* aux;

    if(pArrayList != NULL)
    {
        tam = ll_len(pArrayList);

        file = fopen(path, "w");

        if(file != NULL && tam > 0 && fprintf(file, "id,nombre,vac1dosis,vac2dosis,sinVacunar\n") != -1)
        {
            for(i = 0; i < tam; i++)
            {
                aux = (ePaises*)ll_get(pArrayList, i);
                if(aux == NULL || fprintf(file, "%d,%s,%d,%d,%d\n", aux->id, aux->nombre, aux->vac1dosis, aux->vac2dosis, aux->sinVacunar) == -1)
                {
                    break;
                }
            }
        }

        if(i > 0 && i == tam)
        {
            retorno = 1;
        }

        fclose(file);
    }
    return retorno;
}

