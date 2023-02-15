#pragma once
#ifndef CENTRO_H_INCLUDED
#define CENTRO_H_INCLUDED

#include "util.h"
#include "lista.h"
#include "animal.h"
#include "persona.h"

class centro
{
	private:
		string nombre;
		PtrLista empleados;
		PtrLista animales;
	public:
		centro(string nombreNuevo, PtrLista listaPersonalNuevo, PtrLista listaAnimalesNuevo);
		~centro();
		string getNombre();
		void setNombre(string nombreNuevo);
		void agregarAnimal(PtrAnimal animalNuevo);
		void agregarEmpleado(PtrPersona empleadoNuevo);
		PtrAnimal removerAnimal(int posicion);
		PtrPersona removerEmpleado(int posicion);
		PtrAnimal getAnimal(int posicion);
		PtrPersona getEmpleado(int posicion);
		void setAnimal(PtrAnimal animalNuevo, int posicion);
		void setEmpleado(PtrPersona empleadoNuevo, int posicion);
		void mostrarAnimales();
		void mostrarEmpelados();
		void ordenarAnimalesEdad();
		void ordenarAnimalesPeso();
		void ordenarAnimalesAltura();
		void ordenarAnimalesEspecie();
		void ordenarAnimalesRaza();
		void ordenarAnimalesCategoria();
		void ordenarAnimalesBiologia();
		void ordenarAnimalesGenero();
		void ordenarEmpleadosNombre();
		void ordenarEmpleadosApellido();
		void ordenarEmpleadosAmbos();
		void ordenarEmpleadosCuil();
		PtrAnimal buscarAnimalManual();
		PtrPersona buscarEmpleadoManual();
		void filtrarAnimalAltura(int alturaBuscada);
		void filtrarAnimalEdad(int edadBuscada);
		void filtrarAnimalPeso(int pesoBuscada);
		void filtrarAnimalEspecie(string especieBuscada);
		void filtrarAnimalRaza(string razaBuscada);
		void filtrarAnimalCategoria(string categoriaBuscada);
		void filtrarAnimalBiologia(string biologiaBuscada);
		void filtrarAnimalGenero(string generoBuscada);
		void filtrarEmpleadoEdad(int edadBuscado);
		void filtrarEmpleadoAntiguedad(int antiguedadBuscado);
		void filtrarEmpleadoNombre(string nombreBuscado);
		void filtrarEmpleadoApellido(string apellidoBuscado);
		void filtrarEmpleadoCalle(string calleBuscado);
		void filtrarEmpleadoNumero(int numeroBuscado);
		void filtrarEmpleadoLocalidad(string localidadBuscado);
		void filtrarEmpleadoCuil(string cuilBuscado);
};

using PtrCentro = centro*;


#endif //CENTRO_H_INCLUDED