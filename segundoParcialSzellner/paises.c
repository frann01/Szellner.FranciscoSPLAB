#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "paises.h"
#include "LinkedList.h"

/** \brief Presenta el menu
 *
 * \return int
 *
 */
int menu()
{
    int respuesta;
    printf("1. Leer un archivo\n");
    printf("2. mostrar Lista\n");
    printf("3. Asignar datos \n");
    printf("4. Filtrar por países exitosos\n");
    printf("5. Filtrar por países en el horno\n");
    printf("6. Ordenar por nivel de vacunación\n");
    printf("7. Mostrar más castigado\n");
    printf("8. Salir\n");
    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%d", &respuesta);
    fflush(stdin);
    return respuesta;
}


/** \brief Asigna el nombre a un pais
 *
 * \param this ePaises*
 * \param pais char*
 * \return int
 *
 */
int paises_setNombre(ePaises* this,char* pais)
{
    int todoOk=1;
    if(this!=NULL && pais!=NULL && strlen(pais)<128 && strlen(pais)>2)
    {
        strcpy(this->nombre, pais);
        todoOk=0;
    }
    return todoOk;
}

/** \brief Asigna el Id a un pais
 *
 * \param this ePaises*
 * \param id int
 * \return int
 *
 */
int pais_setId(ePaises* this,int id)
{
    int todoOk=1;
    if(this!=NULL)
    {
        this->id=id;
        todoOk=0;
    }
    return todoOk;
}

/** \brief Asigna los vac1Dosis a un pais
 *
 * \param this ePaises*
 * \param vac int
 * \return int
 *
 */
int pais_setvac1Dosis(ePaises* this,int vac)
{
    int todoOk=1;
    if(this!=NULL)
    {
        this->vac1dosis=vac;
        todoOk=0;
    }
    return todoOk;
}


/** \brief Asigna el vac2Dosis a un pais
 *
 * \param this ePaises*
 * \param vac int
 * \return int
 *
 */
int pais_setvac2Dosis(ePaises* this,int vac)
{
    int todoOk=1;
    if(this!=NULL)
    {
        this->vac2dosis=vac;
        todoOk=0;
    }
    return todoOk;
}


/** \brief Asigna el sinVacunar a un pais
 *
 * \param this ePaises*
 * \param sinvac int
 * \return int
 *
 */
int pais_setSinVacunar(ePaises* this,int sinvac)
{
    int todoOk=1;
    if(this!=NULL)
    {
        this->sinVacunar=sinvac;
        todoOk=0;
    }
    return todoOk;
}


/** \brief Crea el espacio para un pais en memoria dinamica
 *
 * \return ePaises*
 *
 */
ePaises* pais_new()
{
    ePaises* p =(ePaises*) malloc(sizeof(ePaises));
    if(p!= NULL)
    {
        p->id=0;
        p->vac1dosis=0;
        p->vac2dosis=0;
        p->sinVacunar=0;
        strcpy(p->nombre, " ");
    }
    return p;
}

/** \brief Crea un pais con todos sus datos asignados
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param Vac1Str char*
 * \param vac2Str char*
 * \param sinVacStr char*
 * \return ePaises* Devuelve Null en caso de error o la direccion del elemento si todoOk
 *
 */
ePaises* pais_newParametros(char* idStr,char* nombreStr,char* Vac1Str, char* vac2Str, char* sinVacStr)
{
    ePaises* p = pais_new();

    if(p!= NULL)
    {

        if(!(pais_setId(p, atoi(idStr))==0
                && pais_setvac1Dosis(p, atoi(Vac1Str))==0
                && paises_setNombre(p, nombreStr)== 0
                && pais_setvac2Dosis(p, atoi(vac2Str))==0
                && pais_setSinVacunar(p, atoi(sinVacStr))==0))
        {

            p = NULL;
        }
    }
    return p;
}


/** \brief Presenta un pais individual con sus datos
 *
 * \param e ePaises*
 * \return int 1 en caso de error 0 en caso de todoOk
 *
 */
int mostrarPais(ePaises* e)
{
    int todoOk=1;
    int id;
    char nombre[20];
    int vac1;
    int vac2;
    int sinvac;

    if(e!=NULL &&
            pais_getId(e, &id)==0 &&
            pais_getNombre(e, nombre)==0 &&
            pais_getVac1(e, &vac1)==0 &&
            pais_getVac2(e, &vac2)==0 &&
            pais_getSinVac(e, &sinvac)==0)
    {
        printf(" %d       %15s           %d           %d            %d\n",
               id,
               nombre,
               vac1,
               vac2,
               sinvac);
        todoOk=0;
    }
    return todoOk;
}

/** \brief Asigna el nombre de un pais a una variable
 *
 * \param this ePaises*
 * \param pais char*
 * \return int
 *
 */
int pais_getNombre(ePaises* this,char* pais)
{
    int todoOk=1;
    if(this!=NULL && pais !=NULL)
    {
        strcpy(pais, this->nombre);
        todoOk=0;
    }
    return todoOk;
}


/** \brief Asigna el id de un pais a una variable
 *
 * \param this ePaises*
 * \param id int*
 * \return int
 *
 */
int pais_getId(ePaises* this,int* id)
{
    int todoOk=1;
    if(this!=NULL && id !=NULL)
    {
        *id = this->id;
        todoOk=0;
    }
    return todoOk;
}

/** \brief Asigna los vac1dosis de un pais a una variable
 *
 * \param this ePaises*
 * \param vac int*
 * \return int
 *
 */
int pais_getVac1(ePaises* this,int* vac)
{
    int todoOk=1;
    if(this!=NULL && vac !=NULL)
    {
        *vac = this->vac1dosis;
        todoOk=0;
    }
    return todoOk;
}

/** \brief Asigna los vac2dosis de un pais a una variable
 *
 * \param this ePaises*
 * \param vac int*
 * \return int
 *
 */
int pais_getVac2(ePaises* this,int* vac)
{
    int todoOk=1;
    if(this!=NULL && vac !=NULL)
    {
        *vac = this->vac2dosis;
        todoOk=0;
    }
    return todoOk;
}

/** \brief Asigna los sinvacunar de un pais a una variable
 *
 * \param this ePaises*
 * \param sinvac int*
 * \return int
 *
 */
int pais_getSinVac(ePaises* this,int* sinvac)
{
    int todoOk=1;
    if(this!=NULL && sinvac !=NULL)
    {
        *sinvac = this->sinVacunar;
        todoOk=0;
    }
    return todoOk;
}

/** \brief Asigna porcentajes aleatorios a los campos de un pais
 *
 * \param pais void*
 * \return int
 *
 */
int mapEstadisticas(void* pais)
{
    int retorno=0;
    int vac1;
    int vac2;
    int sinvac;

    if(pais != NULL  )
    {
        ePaises* aux = (ePaises*) pais;
        vac1 = rand() % (60 - 1 +1) + 1;
        vac2 = rand() % (40 - 1 +1) + 1;
        sinvac=100-(vac1+vac2);
        if(pais_setvac1Dosis(aux, vac1)==0 &&
                pais_setvac2Dosis(aux, vac2)==0&&
                pais_setSinVacunar(aux, sinvac)==0)
        {
            retorno=1;
        }
    }
    return retorno;
}


/** \brief Filtra si un pais tiene mas de 30% de vacunados con 2 dosis
 *
 * \param pais void*
 * \return int
 *
 */
int filterExitosos(void* pais)
{
    int retorno=0;
    if(pais != NULL  )
    {
        ePaises* aux = (ePaises*) pais;
        if(aux->vac2dosis > 30)
        {
            retorno=1;
        }
    }
    return retorno;
}

/** \brief Filtra paises con mas % de no vacunados que vacunados
 *
 * \param pais void*
 * \return int
 *
 */
int filterHorno(void* pais)
{
    int retorno=0;
    if(pais != NULL  )
    {
        ePaises* aux = (ePaises*) pais;
        if(aux->sinVacunar > (aux->vac1dosis + aux->vac2dosis))
        {
            retorno=1;
        }
    }
    return retorno;
}

/** \brief Compara dos cantidades de vacunados
 *
 * \param valor1 void*
 * \param valor2 void*
 * \return int SI el primer valor es mayor que el segundo devuelve 1, si el segundo es mayor -1 y si son iguales 0
 *
 */
int pais_compararVacunados1(void* valor1, void* valor2)
{
    int retorno;
    int resultado;
    ePaises* aux1 = (ePaises*)valor1;
    ePaises* aux2 = (ePaises*)valor2;

    if(aux1 != NULL && aux2 != NULL)
    {
        resultado = aux1->vac1dosis - aux2->vac1dosis;

        if(resultado > 0)
        {
            retorno = 1;
        }
        else
        {
            if(resultado < 0)
            {
                retorno = -1;
            }
            else
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}

/** \brief Busca los paises con mayor cantidad de no vacunados y los muestra
 *
 * \param this LinkedList*
 * \return int
 *
 */
int masCastigado(LinkedList* this)
{
    int retorno=0;
    int tam;
    int porcentajeCastigado;
    int bandera=0;
    ePaises* aux=NULL;


    if(this!=NULL)
    {
        tam=ll_len(this);
        for(int i=0; i< tam-1; i++)
        {
            aux=ll_get(this, i);

            if(bandera == 0 || aux->sinVacunar > porcentajeCastigado)
            {
                porcentajeCastigado = aux->sinVacunar;
                bandera=1;
                retorno=1;
            }
            aux=NULL;
        }
    }
    printf("Los paises con mayor cantidad de no vacunados son \n");
    for(int i=0; i< tam-1; i++)
    {
        aux=ll_get(this, i);
        if(aux->sinVacunar == porcentajeCastigado)
        {
            printf("%s ", aux->nombre);
        }
    }
    printf("con %d porciento de no vacunados \n", porcentajeCastigado);
    printf("\n");
    return retorno;
}
