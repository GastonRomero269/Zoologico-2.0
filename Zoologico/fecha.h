#pragma once
#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class fechaObjeto
{
private:
	int dia;
	int mes;
	int anio;
	int hora;
	int minutos;
public:
	fechaObjeto(int diaNuevo, int mesNuevo, int anioNuevo, int horaNuevo, int minutosNuevo);
	fechaObjeto();
	~fechaObjeto();
	void setDia(int diaNuevo);
	void setMes(int mesNuevo);
	void setAnio(int anioNuevo);
	void setHora(int horaNuevo);
	void setMinutos(int minutosNuevo);
	int getDia();
	int getMes();
	int getAnio();
	int getHora();
	int getMinutos();
	void mostrar();
	bool fechaValida();
	bool bisiesto(int anio);
};

using PtrFecha = fechaObjeto*;

#endif // FECHA_H_INCLUDED