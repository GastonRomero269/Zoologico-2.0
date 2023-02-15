#pragma once
#ifndef ANIMAL_H_INCLUDED
#define ANIMAL_H_INCLUDED

#include "util.h"

class animalObjeto
{
	private:
		int edad;
		float peso;
		float altura;
		string especie;
		string raza;
		string categoria;
		string biologia;
		string genero;
	public:
		animalObjeto(int edadNuevo, float pesoNuevo, float alturaNuevo, string especieNuevo, string razaNuevo, string categoriaNuevo, string biologiaNuevo, string generoNuevo);
		~animalObjeto();
		void setEdad(int edadNuevo);
		void setPeso(float pesoNuevo);
		void setAltura(float alturaNuevo);
		void setEspecie(string especieNuevo);
		void setRaza(string razaNuevo);
		void setCategoria(string categoriaNuevo);
		void setBiologia(string biologiaNuevo);
		void setGenero(string generoNuevo);
		int getEdad();
		float getPeso();
		float getAltura();
		string getEspecie();
		string getRaza();
		string getCategoria();
		string getBiologia();
		string getGenero();
		void mostrar();
};

using PtrAnimal = animalObjeto*;


#endif //ANIMAL_H_INCLUDED