#include "util.h"
#include "persona.h"

persona::persona(string nombreNuevo, string apellidoNuevo, int edadNuevo, int antiguedadNuevo, string calleNuevo, int numeroNuevo, string localidadNuevo, string cuilNuevo)
{
	(this->nombre, nombreNuevo);
	(this->apellido, apellidoNuevo);
	this->edad = edadNuevo;
	this->antiguedad = antiguedadNuevo;
	domicilio = new domicilioObjeto(calleNuevo, numeroNuevo, localidadNuevo);
	cuil = new cuilObjeto(cuilNuevo);
}

persona::~persona()
{
	delete domicilio;
	delete cuil;
}

void persona::setEdad(int edadNuevo)
{
	this->edad = edadNuevo;
}


void persona::setAntiguedad(int antiguedadNuevo)
{
	this->antiguedad = antiguedadNuevo;
}

void persona::setNombre(string nombreNuevo)
{
	(nombre, nombreNuevo);
}

void persona::setApellido(string apellidoNuevo)
{
	(apellido, apellidoNuevo);
}

void persona::setDomicilio(PtrDomicilio domicilioNuevo)
{
	delete this->domicilio;
	this->domicilio = domicilioNuevo;
}

void persona::setCuil(PtrCuil cuilNuevo)
{
	delete this->cuil;
	this->cuil = cuilNuevo;
}

int persona::getEdad()
{
	return this->edad;
}


int persona::getAntiguedad()
{
	return this->antiguedad;
}

string persona::getNombre()
{
	return nombre;
}

string persona::getApellido()
{
	return apellido;
}

PtrDomicilio persona::getDomicilio()
{
	return this->domicilio;
}

PtrCuil persona::getCuil()
{
	return this->cuil;
}

void persona::mostrar()
{
	cout << "Edad: " << endl;
}