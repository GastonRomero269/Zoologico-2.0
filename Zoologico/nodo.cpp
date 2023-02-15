#include "util.h"
#include "nodo.h"

PtrNodo crearNodo(PtrDato dato) 
{
    PtrNodo nodo = (PtrNodo)obtenerMemoria(sizeof(Nodo));
    nodo->dato = dato;
    nodo->nodoSiguiente = NULL;
    return nodo;
}


PtrNodo destruirNodo(PtrNodo nodo) 
{
    free(nodo);
    return NULL;
}

void setDato(PtrNodo nodo, PtrDato dato) 
{
    nodo->dato = dato;
}

PtrDato getDato(PtrNodo nodo) 
{
    return nodo->dato;
}

void setNodoSiguiente(PtrNodo esteNodo, PtrNodo nodoSiguienteNuevo)
{
    esteNodo->nodoSiguiente = nodoSiguienteNuevo;
}

PtrNodo getNodoSiguiente(PtrNodo nodo) 
{
    return nodo->nodoSiguiente;
}
