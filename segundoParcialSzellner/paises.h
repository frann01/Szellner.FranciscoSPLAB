#include "LinkedList.h"
#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED

typedef struct
{

    int id;
    char nombre[128];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;

}ePaises;

#endif // PAISES_H_INCLUDED

int menu();
int filterExitosos(void* pais);
int filterHorno(void* pais);
int mapEstadisticas(void* pais);
int pais_compararVacunados1(void* valor1, void* valor2);
int masCastigado(LinkedList* this);
int paises_setNombre(ePaises* this,char* pais);
int pais_setId(ePaises* this,int id);
int pais_setvac2Dosis(ePaises* this,int vac);
int pais_setvac1Dosis(ePaises* this,int vac);
int pais_setSinVacunar(ePaises* this,int sinvac);
ePaises* pais_new();
ePaises* pais_newParametros(char* idStr,char* nombreStr,char* Vac1Str, char* vac2Str, char* sinVacStr);
int mostrarPais(ePaises* e);
int pais_getNombre(ePaises* this,char* pais);
int pais_getId(ePaises* this,int* id);
int pais_getVac1(ePaises* this,int* vac);
int pais_getVac2(ePaises* this,int* vac);
int pais_getSinVac(ePaises* this,int* sinvac);
