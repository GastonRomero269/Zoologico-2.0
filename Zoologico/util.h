#pragma once
#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <cstdbool>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <fstream>

using namespace std;

typedef void* PtrDato;
typedef char* PtrCadena;

PtrDato obtenerMemoria(size_t tamanio);

string reconversionString(string n, string m);

void limpiadoGeneral();

char* stringDinamico(char* literal);

#endif // UTIL_H_INCLUDED