#include "util.h"
#include "domicilio.h"


domicilioObjeto::domicilioObjeto(string calleNuevo, int numeroNuevo, string localidadNuevo)
{
	this->calle = calleNuevo;
	this->numero = numeroNuevo;
	this->localidad = localidadNuevo;
}

domicilioObjeto::~domicilioObjeto()
{

}

void domicilioObjeto::setCalle(string calleNuevo)
{
	(this->calle, calleNuevo);
}

void domicilioObjeto::setNumero(int numeroNuevo)
{
	this->numero = numeroNuevo;
}

void domicilioObjeto::setLocalidad(string localidadNuevo)
{
	(this->localidad, localidadNuevo);
}

string domicilioObjeto::getCalle()
{
	return this->calle;
}

int domicilioObjeto::getNumero()
{
	return this->numero;
}

string domicilioObjeto::getLocalidad()
{
	return this->localidad;
}

void domicilioObjeto::mostrar()
{
	cout << "Domicilio: " << this->getCalle() << ", " << this->getNumero() << ", " << this->getLocalidad() << endl;
}