#include "util.h"
#pragma warning(disable : 4996)

PtrDato obtenerMemoria(size_t tamanio) 
{
    PtrDato punteroGenerico = malloc(tamanio);
    if (punteroGenerico == NULL)
    {
        cout << "Memoria insuficiente" << endl;
        exit(1);
    }
    return punteroGenerico;
}


void limpiadoGeneral()
{
    fflush(stdin);
    system("cls");
    fflush(stdin);
}

char* stringDinamico(char* literal)
{
    char* buffer = (char*)obtenerMemoria(sizeof(char) * strlen(literal) + 1);
    strcpy(buffer, literal);
    return buffer;
}