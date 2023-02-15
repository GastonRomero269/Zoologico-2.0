#include "util.h"
#include "archivos.h"
#include "persona.h"

/*
void leerArchivos()
{
	string cadena;
	ifstream file;
	file.open("basura.dat");

	while (file.eof())
	{
		getline(file, nombre);
		getline(file, apellido);
	}

	file.close();
}
*/

/*
void guardarArchivos()
{
	string cadena;
	ofstream file;
	file.open("basura.dat");
	file << nombre << endl;
	file << apellido << endl;

	file.close();
}

void resumen()
{

	string lectura;
	PtrDomicilio dom = new domicilioObjeto("Hello", 1400, "hola");
	ofstream file;
	file.open("info.txt", ios::in);
	lectura = dom->getCalle();
	file << lectura << endl;
	file << dom->getNumero() << endl;
	lectura = dom->getLocalidad();
	file << lectura << endl;
	file.close();

	ifstream file1;
	file1.open("info.txt", ios::out);
	getline(file1, lectura);
	while (!file1.eof())
	{
		cout << lectura << endl;
		getline(file1, lectura);
	}
	file1.close();

}
*/





