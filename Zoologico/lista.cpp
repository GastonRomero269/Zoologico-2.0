#include "util.h"
#include "lista.h"

PtrLista crearLista()
{
    PtrLista lista = (PtrLista)obtenerMemoria(sizeof(Lista));
    lista->primerElemento = NULL;
    return lista;
}

PtrLista destruirLista(PtrLista lista, bool remover)
{
    if (remover)
    {
        while (!listaVacia(lista)) 
        {
            removerDeLista(lista, 0);
        }
    }
    free(lista);
    return NULL;
}

bool listaVacia(PtrLista lista)
{
    return (lista->primerElemento == NULL);
}


PtrNodo getNodoLista(PtrLista lista, int posicion) 
{
    PtrNodo nodo = lista->primerElemento;
    int posicionActual = 0;
    if (nodo != NULL) 
    {
        while (posicionActual < posicion && getNodoSiguiente(nodo) != NULL) 
        {
            posicionActual++;
            nodo = getNodoSiguiente(nodo);
        }
    }
    return nodo;
}

PtrDato getDatoLista(PtrLista lista, int posicion)
{
    PtrDato dato = NULL;
    PtrNodo nodo = getNodoLista(lista, posicion);
    if (nodo != NULL) 
    {
        dato = getDato(nodo);
    }
    return dato;
}

PtrDato getCabecera(PtrLista lista) 
{
    PtrDato dato = NULL;
    if (lista->primerElemento != NULL) 
    {
        dato = getDato(lista->primerElemento);
    }
    return dato;
}

PtrLista getResto(PtrLista lista) 
{
    PtrLista resto = crearLista();
    if (lista->primerElemento != NULL) 
    {
        resto->primerElemento = getNodoSiguiente(lista->primerElemento);
    }
    return resto;
}

int longitudLista(PtrLista lista)
{
    int longitud = 0;
    PtrNodo nodo = lista->primerElemento;
    while (nodo != NULL)
    {
        nodo = getNodoSiguiente(nodo);
        longitud++;
    }
    return longitud;
}

void agregarDatoLista(PtrLista lista, PtrDato dato)
{
    PtrNodo nuevoNodo = crearNodo(dato);
    setNodoSiguiente(nuevoNodo, lista->primerElemento);
    lista->primerElemento = nuevoNodo;
}

bool insertarDatoLista(PtrLista lista, PtrDato dato, int posicion)
{
    PtrNodo nodo = getNodoLista(lista, posicion);
    bool resultado = false;
    if (nodo != NULL)
    {
        PtrNodo nuevoNodo = crearNodo(dato);
        setNodoSiguiente(nuevoNodo, getNodoSiguiente(nodo));
        setNodoSiguiente(nodo, nuevoNodo);
        resultado = true;
    }
    return resultado;
}



void agregarLista(PtrLista estaLista, PtrLista otraLista)
{
    if (estaLista->primerElemento == NULL) 
    {
        estaLista->primerElemento = otraLista->primerElemento;
    }
    else
    {
        PtrNodo nodo = estaLista->primerElemento;
        while (getNodoSiguiente(nodo) != NULL)
        {
            nodo = getNodoSiguiente(nodo);
        }
        setNodoSiguiente(nodo, otraLista->primerElemento);
    }

}


PtrDato removerDeLista(PtrLista lista, int posicion) 
{
    PtrDato dato = NULL;
    PtrNodo nodoEliminar = NULL;
    if (lista->primerElemento != NULL) 
    {
        if (posicion == 0)
        { 
            nodoEliminar = lista->primerElemento;
            dato = getDato(nodoEliminar);
            lista->primerElemento = getNodoSiguiente(lista->primerElemento);
            destruirNodo(nodoEliminar);
        }
        else 
        {
            PtrNodo nodo = getNodoLista(lista, posicion - 1);
            if (nodo != NULL)
            {
                nodoEliminar = getNodoSiguiente(nodo);
                if (nodoEliminar != NULL)
                {
                    dato = getDato(nodoEliminar);
                    setNodoSiguiente(nodo, getNodoSiguiente(nodoEliminar));
                    destruirNodo(nodoEliminar);
                }
            }
        }
    }
    return dato;
}

void imprimirLista(PtrLista lista)
{
    PtrLista listaAux = crearLista();
    agregarLista(listaAux, lista);
    while (!listaVacia(listaAux))
    {
        printf("%s  ", (char*)getCabecera(listaAux));
        PtrLista listaADestruir = listaAux;
        listaAux = getResto(listaAux);
        listaADestruir = destruirLista(listaADestruir, false);
    }
    listaAux = destruirLista(listaAux, false);
    printf("\n");
}