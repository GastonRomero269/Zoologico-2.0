#include "util.h"
#include "fecha.h"

fechaObjeto::fechaObjeto(int diaNuevo, int mesNuevo, int anioNuevo, int horaNuevo, int minutosNuevo)
{
	this->dia = diaNuevo;
	this->mes = mesNuevo;
	this->anio = anioNuevo;
	this->hora = horaNuevo;
	this->minutos = minutosNuevo;
}

fechaObjeto::fechaObjeto()
{
	int fecha = 0;
	int hora = 0;
	bool valido = true;
	do
	{
		limpiadoGeneral();
		if ( !valido )
		{
			cout << "Usted ha ingresado una fecha incorrecta." << endl;
			cout << "Debera ingresar nuevamente la fecha." << endl << endl;
		}
		cout << "Ingrese la fecha en el formato: 10122022 = ";
		cin >> fecha;
		cout << "Ingrese la hora en el formato: 1645 = ";
		cin >> hora;
		this->dia = (fecha / 1000000);
		this->mes = (fecha / 10000) % 1000;
		this->anio = (fecha % 10000);
		this->hora = (hora / 100);
		this->minutos = (hora % 100);
		valido = fechaValida();

	} while ( !valido );
}

fechaObjeto::~fechaObjeto()
{

}

void fechaObjeto::setDia(int diaNuevo)
{
	this->dia = diaNuevo;
}

void fechaObjeto::setMes(int mesNuevo)
{
	this->mes = mesNuevo;
}

void fechaObjeto::setAnio(int anioNuevo)
{
	this->anio = anioNuevo;
}

void fechaObjeto::setHora(int horaNuevo)
{
	this->hora = horaNuevo;
}

void fechaObjeto::setMinutos(int minutosNuevo)
{
	this->minutos = minutosNuevo;
}

int fechaObjeto::getDia()
{
	return this->dia;
}

int fechaObjeto::getMes()
{
	return this->mes;
}

int fechaObjeto::getAnio()
{
	return this->anio;
}

int fechaObjeto::getHora()
{
	return this->hora;
}

int fechaObjeto::getMinutos()
{
	return this->minutos;
}

void fechaObjeto::mostrar()
{
	cout << getDia() << "/" << getMes() << "/" << getAnio() << " " << getHora() << ":" << getMinutos() << endl;
}

bool fechaObjeto::fechaValida()
{
	int dia = this->getDia();
	int mes = this->getMes();
	switch (mes)
	{
		case 1:
			if ( dia > 0 && dia <= 31 )
			{
				return true;
			}
			break;
		case 2:
			if ( bisiesto( this->getAnio() ) )
			{
				if ( dia > 0 && dia <= 29 )
				{
					return true;
				}
			}
			else
			{
				if ( dia > 0 && dia <= 28 )
				{
					return true;
				}
			}
			break;
		case 3:
			if ( dia > 0 && dia <= 31 )
			{
				return true;
			}
			break;
		case 4:
			if ( dia > 0 && dia <= 30 )
			{
				return true;
			}
			break;
		case 5:
			if ( dia > 0 && dia <= 30 )
			{
				return true;
			}
			break;
		case 6:
			if ( dia > 0 && dia <= 30 )
			{
				return true;
			}
			break;
		case 7:
			if ( dia > 0 && dia <= 31 )
			{
				return true;
			}
			break;
		case 8:
			if ( dia > 0 && dia <= 31 )
			{
				return true;
			}
			break;
		case 9:
			if ( dia > 0 && dia <= 30 )
			{
				return true;
			}
			break;
		case 10:
			if ( dia > 0 && dia <= 31 )
			{
				return true;
			}
			break;
		case 11:
			if ( dia > 0 && dia <= 30 )
			{
				return true;
			}
			break;
		case 12:
			if ( dia > 0 && dia <= 31 )
			{
				return true;
			}
			break;
	}
	return false;
}

bool fechaObjeto::bisiesto(int anio)
{
	if ( anio % 400 == 0 )
	{
		if ( anio % 100 == 0 )
		{
			return true;
		}
	}
	return false;
}