#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "paises.h"
#include "LinkedList.h"
#include "validacion.h"
#include "controller.h"


int main()
{
    srand(time(NULL));
    int option = 0;
    char salir='n';
    int orden=-1;
    int contador;
    char path[30];

    LinkedList* listaPaises = ll_newLinkedList();
    if(listaPaises == NULL)
    {
        printf("No hay espacio en la memoria del sistema");
        system("pause");
        exit(1);
    }

    do
    {
        contador =ll_len(listaPaises);
        option = menu();
        switch(option)
        {
        case 1:
            printf("Ingrese el path del archivo a leer: ");
            scanf("%s", path);
//            controller_loadFromText("vacunas.csv", listaPaises);
            contador = controller_loadFromText(path, listaPaises);

            if(contador > 0)
            {
                printf("Se cargo el archivo de texto\n");
            }
            else
            {
                printf("No se puede cargar paises\n");
            }

            break;

        case 2:
            controller_ListPaises(listaPaises);
            break;

        case 3:
            if(contador==0)
            {
                printf("No hay paises cargados\n");
            }
            else
            {
                listaPaises = ll_map(listaPaises, mapEstadisticas);
                if(listaPaises!= NULL)
                {
                    printf("Datos Asignados!\n");
                }
            }
            break;

        case 4:
            if(contador==0)
            {
                printf("No hay paises cargados\n");
            }
            else
            {
                LinkedList* paisesExitosos = ll_newLinkedList();
                if(paisesExitosos == NULL)
                {
                    printf("No hay espacio en la memoria del sistema");
                    system("pause");
                    exit(1);
                }
                paisesExitosos = ll_filter(listaPaises, filterExitosos);
                if(controller_saveAsText("paisesExitosos", paisesExitosos)==1)
                {
                    printf("Paises filtrados con exito!\n");
                }
            }

            break;

        case 5:
            if(contador==0)
            {
                printf("No hay paises cargados\n");
            }
            else
            {
                LinkedList* paisesAlHorno = ll_newLinkedList();
                if(paisesAlHorno == NULL)
                {
                    printf("No hay espacio en la memoria del sistema\n");
                    system("pause");
                    exit(1);
                }
                paisesAlHorno = ll_filter(listaPaises, filterHorno);
                if(controller_saveAsText("paisesAlHorno", paisesAlHorno)==1)
                {
                    printf("Paises filtrados con exito!\n");
                }
            }

            break;

        case 6:
            if(contador==0)
            {
                printf("No hay paises cargados\n");
            }
            else
            {
               printf("Como desea ordenar la lista?\n");
               printf("0. Descendente\n");
               printf("1. Ascendente\n");
               scanf("%d", &orden);

                if(ll_sort(listaPaises, pais_compararVacunados1, orden)==0)
                {
                    printf("Paises ordenados correctamente\n");
                }
            }
            break;

        case 7:
            if(contador==0)
            {
                printf("No hay paises cargados\n");
            }
            else
            {
               masCastigado(listaPaises);
            }
            break;

        case 8:
            printf("Seguro desea salir?\n");
            fflush(stdin);
            salir = getchar();
            while(validarSN(salir)==-1)
            {
                printf("Por favor ingrese s/n\n");
                fflush(stdin);
                scanf("%c", &salir);
            }
            break;


        default:
            printf("Opcion incorrecta!\n");

        }
        system("pause");
        system("cls");
    }
    while(salir != 's');
    return 0;
}

