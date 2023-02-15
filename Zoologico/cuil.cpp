#include "util.h"
#include "cuil.h"

cuilObjeto::cuilObjeto(string dniNuevo)
{
	(this->cuil, dniNuevo);
}

cuilObjeto::~cuilObjeto()
{

}

void cuilObjeto::setGenero(string generoNuevo)
{
	this->cuil[0] = generoNuevo[0];
	this->cuil[1] = generoNuevo[1];
}

void cuilObjeto::setDni(string dniNuevo)
{
	this->cuil[2] = dniNuevo[0];
	this->cuil[3] = dniNuevo[1];
	this->cuil[4] = dniNuevo[2];
	this->cuil[5] = dniNuevo[3];
	this->cuil[6] = dniNuevo[4];
	this->cuil[7] = dniNuevo[5];
	this->cuil[8] = dniNuevo[6];
	this->cuil[9] = dniNuevo[7];
}

void cuilObjeto::setCodigo(string codigoNuevo)
{
	this->cuil[10] = codigoNuevo[0];
}

void cuilObjeto::setCuil(string cuilNuevo)
{
	(this->cuil, cuilNuevo);
}

string cuilObjeto::getGenero()
{
	string generoDevolver;
	generoDevolver.resize(2);
	generoDevolver[0] = this->cuil[0];
	generoDevolver[1] = this->cuil[1];
	return generoDevolver;
}

string cuilObjeto::getDni()
{
	string dniDevolver;
	dniDevolver.resize(8);
	dniDevolver[0] = this->cuil[2];
	dniDevolver[1] = this->cuil[3];
	dniDevolver[0] = this->cuil[4];
	dniDevolver[1] = this->cuil[5];
	dniDevolver[0] = this->cuil[6];
	dniDevolver[1] = this->cuil[7];
	dniDevolver[0] = this->cuil[8];
	dniDevolver[1] = this->cuil[9];
	return dniDevolver;
}

string cuilObjeto::getCodigo()
{
	string codigoDevolver;
	codigoDevolver.resize(1);
	codigoDevolver[0] = this->cuil[10];
	return codigoDevolver;
}

string cuilObjeto::getCuil()
{
	return this->cuil;
}

void cuilObjeto::mostrar()
{
	cout << this->getGenero() << "-" << this->getDni() << "-" << this->getCodigo() << endl;
}

bool cuilObjeto::cuilValido()
{
	string cuilCopia;
	cuilCopia.resize(12);
	cuilCopia = this->cuil;
	int sumatoria = 0;
	int division = 0;
	int resto = 0;
	int zFinal = 0;

	sumatoria += static_cast <int> ( ( cuilCopia[0] ) - 48 ) * 5;
	sumatoria += static_cast <int> ( ( cuilCopia[1] ) - 48 ) * 4;
	sumatoria += static_cast <int> ( ( cuilCopia[2] ) - 48 ) * 3;
	sumatoria += static_cast <int> ( ( cuilCopia[3] ) - 48 ) * 2;
	sumatoria += static_cast <int> ( ( cuilCopia[4] ) - 48 ) * 7;
	sumatoria += static_cast <int> ( ( cuilCopia[5] ) - 48 ) * 6;
	sumatoria += static_cast <int> ( ( cuilCopia[6] ) - 48 ) * 5;
	sumatoria += static_cast <int> ( ( cuilCopia[7] ) - 48 ) * 4;
	sumatoria += static_cast <int> ( ( cuilCopia[8] ) - 48 ) * 3;
	sumatoria += static_cast <int> ( ( cuilCopia[9] ) - 48 ) * 2;

	division = sumatoria / 11 ;
	resto = sumatoria - ( division * 11 );
	zFinal = 11 - resto;

	switch ( zFinal )
	{
		case 0:
			zFinal = 0;
			break;
		case 1:
			if ( this->getGenero().compare("20") == 0 )
			{
				zFinal = 9;
				this->setGenero("23");
			}
			if (this->getGenero().compare("27") == 0)
			{
				zFinal = 4;
				this->setGenero("23");
			}
			if (this->getGenero().compare("30") == 0)
			{
				zFinal = zFinal;
			}
			break;
		default:
			cout << "Ha ocurrido una falla en la verificacion." << endl << endl;
			break;
	}

	int zReal = static_cast <int> ( ( this->getCodigo()[0] ) - 48);

	if (zFinal == zReal)
	{
		return true;
	}
	else 
	{
		return false;
	}
}