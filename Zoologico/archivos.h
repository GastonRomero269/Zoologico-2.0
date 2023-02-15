#pragma once
#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include "util.h"

class cuilEstatico
{
	private :
		string cuil;
	public:
		cuilEstatico(string cuilEstaticoNuevo);
		~cuilEstatico();
		void setCuil(string cuilEstaticoNuevo);
		string getCuil(string cuilEstaticoNuevo);
};




#endif //ARCHIVOS_H_INCLUDED