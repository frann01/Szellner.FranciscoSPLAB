#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "paises.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los paises desde el archivo ingresado (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_FromText(FILE* pFile, LinkedList* pArrayList)
{
    int contador = 0;
    char buffer[4][128];
    ePaises* aux;
    if(pFile != NULL && pArrayList != NULL)
    {
        while(!feof(pFile))
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]) == 5)
            {

                aux = (ePaises*) pais_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

                if(strcmp(buffer[1], "pais")!=0 && aux != NULL && ll_add(pArrayList, (ePaises*)aux) == 0)
                {
                    contador++;
                }
            }
        }
    }

    return contador;
}
