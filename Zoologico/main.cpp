#include "util.h"
#include "centro.h"
#include "persona.h"
#include "animal.h"
#include "fecha.h"


void menu(PtrLista Zoologico);

int main()
{
	PtrLista Zoologico = new Lista();
	int main = 0;
	cout << "1. Ingresar como invitado." << endl;
	cout << "2. Ingresar como anfitrion." << endl;
	cout << "3. Ingresar a la sala de pruebas." << endl << endl;
	cout << "0. Cerrar la sesion." << endl;
	cin >> main;

	do
	{
		switch (main)
		{
			case 1:
				menu(Zoologico);
				break;
			case 2:

				menu(Zoologico);
				break;
			case 3:

				menu(Zoologico);
				break;
			case 0:
				break;
			default:
				cout << "Eleccion incorrecta." << endl;
				break;
		}
	} while (main < 0 || main > 3);

	if (main != 0)
	{
		menu(Zoologico);
	}

	delete Zoologico;
	return 0;
}

void menu(PtrLista Zoologico)
{
	int Respuesta1 = 0;
	int Respuesta2 = 0;
	int Respuesta3 = 0;
	cout << "1. Creacion." << endl;
	cout << "2. Visualizacion." << endl << endl;
	cout << "3. Busqueda." << endl << endl;
	cout << "4. Ordenar." << endl << endl;
	cout << "5. Guardar." << endl << endl;
	cout << "0. Volver al menu anterior." << endl;
	cin >> Respuesta1;
	
	do
	{
		switch (Respuesta1)
		{
			case 1:
				cout << "1. Crear animal." << endl;
				cout << "2. Crear empleado." << endl << endl;
				cout << "0. Volver." << endl;
				cin >> Respuesta2;

				switch (Respuesta2)
				{
					case 1:
						break;
					case 2:
						break;
					case 0:
						break;
					default:
						cout << "Eleccion incorrecta." << endl;
						break;
				}
				break;
			case 2:
				cout << "1. Filtrar animal." << endl;
				cout << "2. Filtrar empleado." << endl << endl;
				cout << "0. Volver." << endl;
				cin >> Respuesta2;

				switch (Respuesta2)
				{
					case 1:
						break;
					case 2:
						break;
					case 0:
						break;
					default:
						cout << "Eleccion incorrecta." << endl;
						break;
				}
				break;
			case 3:
				cout << "1. Buscar animal." << endl;
				cout << "2. Buscar empleado." << endl << endl;
				cout << "0. Volver." << endl;
				cin >> Respuesta2;

				switch (Respuesta2)
				{
					case 1:
						break;
					case 2:
						break;
					case 0:
						break;
					default:
						cout << "Eleccion incorrecta." << endl;
						break;
				}
				break;
			case 4:
				cout << "1. Ordenar animal." << endl;
				cout << "2. Ordenar empleado." << endl << endl;
				cout << "0. Volver." << endl;
				cin >> Respuesta2;

				switch (Respuesta2)
				{
					case 1:
						break;
					case 2:
						break;
					case 0:
						break;
					default:
						cout << "Eleccion incorrecta." << endl;
						break;
				}
				break;
			case 5:

				break;
			case 0:
				Respuesta1 = 0;
				Respuesta2 = 0;
				Respuesta3 = 0;
				break;
			default:
				cout << "Eleccion incorrecta." << endl;
				break;
		}
	} while (Respuesta1 != 0 || Respuesta2 != 0 || Respuesta3 != 0);
}
