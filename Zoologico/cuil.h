#pragma once
#ifndef CUIL_H_INCLUDED 
#define CUIL_H_INCLUDED

#include "util.h"

class cuilObjeto
{
	private:
		string cuil;
	public:
		cuilObjeto(string dniNuevo);
		~cuilObjeto();
		void setCuil(string cuilNuevo);
		void setGenero(string generoNuevo);
		void setDni(string dniNuevo);
		void setCodigo(string codigoNuevo);
		string getGenero();
		string getDni();
		string getCodigo();
		string getCuil();
		void mostrar();
		bool cuilValido();
};

using PtrCuil = cuilObjeto*;


#endif //CUIL_H_INCLUDED