#pragma once
#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "util.h"

typedef struct Nodo 
{
    void* dato; 
    struct Nodo* nodoSiguiente; 

} Nodo;

typedef Nodo* PtrNodo;

PtrNodo crearNodo(PtrDato dato);

PtrNodo destruirNodo(PtrNodo nodo);

void setDato(PtrNodo nodo, PtrDato dato);

PtrDato getDato(PtrNodo nodo);

void setNodoSiguiente(PtrNodo esteNodo, PtrNodo siguienteNodo);

PtrNodo getNodoSiguiente(PtrNodo nodo);


#endif // NODO_H_INCLUDED