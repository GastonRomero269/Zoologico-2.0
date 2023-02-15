#pragma once
#ifndef DOMICILIO_H_INCLUDED 
#define DOMICILIO_H_INCLUDED

#include "util.h"

class domicilioObjeto
{
	private:
		string calle;
		int numero;
		string localidad;
	public:
		domicilioObjeto(string calleNuevo, int numero, string localidad);
		~domicilioObjeto();
		void setCalle(string calleNuevo);
		void setNumero(int numeroNuevo);
		void setLocalidad(string localidadNuevo);
		string getCalle();
		int getNumero();
		string getLocalidad();
		void mostrar();
};

using PtrDomicilio = domicilioObjeto*;




#endif //DOMICILIO_H_INCLUDED