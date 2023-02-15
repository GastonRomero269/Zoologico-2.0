#pragma once
#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "util.h"
#include "nodo.h"

typedef struct Lista 
{
    PtrNodo primerElemento;

} Lista;

typedef Lista* PtrLista;

PtrLista crearLista();

PtrLista destruirLista(PtrLista lista, bool remover);

bool listaVacia(PtrLista lista);

PtrDato getDatoLista(PtrLista lista, int posicion);

PtrDato getCabecera(PtrLista lista);

PtrLista getResto(PtrLista lista);

int longitudLista(PtrLista lista);

void agregarDatoLista(PtrLista lista, PtrDato dato);

bool insertarDatoLista(PtrLista lista, PtrDato dato, int posicion);

void agregarLista(PtrLista estaLista, PtrLista otraLista);

PtrDato removerDeLista(PtrLista lista, int posicion);

PtrDato getDatoLista(PtrLista lista, int posicion);

void imprimirLista(PtrLista lista);

#endif //LISTA_H_INCLUDED