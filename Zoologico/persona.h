#pragma once
#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include "util.h"
#include "domicilio.h"
#include "cuil.h"


class persona
{
	private:
		string nombre;
		string apellido;
		int edad;
		int antiguedad;
		PtrDomicilio domicilio;
		PtrCuil cuil;
	public:
		persona(string nombreNuevo, string apellidoNuevo, int edadNueva, int antiguedad, string calleNuevo, int numeroNuevo, string localidadNuevo, string cuilNuevo);
		~persona();
		void setEdad(int edadNueva);
		void setAntiguedad(int antiguedadNueva);
		void setNombre(string nombreNuevo);
		void setApellido(string apellidoNuevo);
		void setCuil(PtrCuil cuilNuevo);
		void setDomicilio(PtrDomicilio domicilioNuevo);
		int getEdad();
		int getAntiguedad();
		string getNombre();
		string getApellido();
		PtrDomicilio getDomicilio();
		PtrCuil getCuil();
		void mostrar();
};

using PtrPersona = persona*;


#endif //PERSONA_H_INCLUDED