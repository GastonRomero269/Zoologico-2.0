#include "util.h"
#include "centro.h"

centro::centro(string nombreNuevo, PtrLista listaPersonalNuevo, PtrLista listaAnimalesNuevo)
{
	this->nombre.resize(nombreNuevo.length());
	this->nombre.swap(nombreNuevo);
	this->empleados = listaPersonalNuevo;
	this->animales = listaAnimalesNuevo;
}

centro::~centro()
{

}

void centro::setNombre(string nombreNuevo)
{
	this->nombre.swap(nombreNuevo);
}

string centro::getNombre()
{
	return this->nombre;
}

void centro::agregarAnimal(PtrAnimal animalNuevo)
{
	agregarDatoLista(animales, static_cast<PtrAnimal>(animalNuevo));
}

void centro::agregarEmpleado(PtrPersona empleadoNuevo)
{
	agregarDatoLista(empleados, static_cast<PtrPersona>(empleadoNuevo));
}

PtrAnimal centro::removerAnimal(int posicion)
{
	return static_cast<PtrAnimal>(removerDeLista(animales, posicion));
}

PtrPersona centro::removerEmpleado(int posicion)
{
	return static_cast<PtrPersona>(removerDeLista(empleados, posicion));
}

PtrAnimal centro::getAnimal(int posicion)
{
	return static_cast<PtrAnimal>(getDatoLista(animales, posicion));
}

PtrPersona centro::getEmpleado(int posicion)
{
	return static_cast<PtrPersona>(getDatoLista(empleados, posicion));
}

void centro::setAnimal(PtrAnimal animalNuevo, int posicion)
{
	PtrAnimal animalEliminar = static_cast<PtrAnimal>(removerDeLista(animales, posicion));
	delete animalEliminar;
	insertarDatoLista(animales, animalNuevo, posicion);
}

void centro::setEmpleado(PtrPersona empleadoNuevo, int posicion)
{
	PtrPersona empleadoEliminar = static_cast<PtrPersona>(removerDeLista(empleados, posicion));
	delete empleadoEliminar;
	insertarDatoLista(empleados, empleadoNuevo, posicion);
}


void centro::mostrarAnimales()
{
	PtrAnimal animalMostrar = NULL;
	PtrLista listaAuxiliar = crearLista();
	agregarLista(listaAuxiliar, animales);
	
	while ( !listaVacia(listaAuxiliar) )
	{
		animalMostrar = static_cast<PtrAnimal>(getCabecera(listaAuxiliar));
		animalMostrar->mostrar();
		PtrLista listaDestruir = listaAuxiliar;
		listaAuxiliar = getResto(listaAuxiliar);
		listaDestruir = destruirLista(listaDestruir, false);
	}

	listaAuxiliar = destruirLista(listaAuxiliar, false);
	printf("\n\n\n");
}

void centro::mostrarEmpelados()
{
	PtrPersona empleadoMostrar = NULL;
	PtrLista listaAuxiliar = crearLista();
	agregarLista(listaAuxiliar, empleados);

	while ( !listaVacia(listaAuxiliar) )
	{
		empleadoMostrar = static_cast<PtrPersona>(getCabecera(empleados));
		empleadoMostrar->mostrar();
		PtrLista listaDestruir = listaAuxiliar;
		listaAuxiliar = getResto(listaAuxiliar);
		listaDestruir = destruirLista(listaDestruir, false);
	}

	listaAuxiliar = destruirLista(listaAuxiliar, false);
	printf("\n\n\n");
}

void centro::ordenarAnimalesEdad()
{
	PtrAnimal animalPrimero = NULL;
	PtrAnimal animalSegundo = NULL;
	PtrAnimal animalAuxiliar = NULL;
	int largo = longitudLista(animales);
	int salto = ( largo / 2 );
	bool cambios = true;

	while (salto > 0)
	{
		cambios = false;

		for (int i = 0 ; i < largo-salto ; i++)
		{
			animalPrimero = static_cast<PtrAnimal>(getDatoLista(animales, i));
			animalSegundo = static_cast<PtrAnimal>(getDatoLista(animales, i + salto));
			
			if ( animalPrimero->getEdad() > animalSegundo->getEdad())
			{
				cambios = true;
				animalAuxiliar = static_cast<PtrAnimal>(removerDeLista(animales, i));
				insertarDatoLista(animales, static_cast<PtrAnimal>(animalAuxiliar), i + salto);
			}
		}

		if ( !cambios )
		{
			salto = ( salto / 2 );
		}
	}
}

void centro::ordenarAnimalesPeso()
{
	PtrAnimal animalPrimero = NULL;
	PtrAnimal animalSegundo = NULL;
	PtrAnimal animalAuxiliar = NULL;
	int largo = longitudLista(animales);
	int salto = (largo / 2);
	bool cambios = true;

	while (salto > 0)
	{
		cambios = false;

		for (int i = 0; i < largo - salto; i++)
		{
			animalPrimero = static_cast<PtrAnimal>(getDatoLista(animales, i));
			animalSegundo = static_cast<PtrAnimal>(getDatoLista(animales, i + salto));

			if (animalPrimero->getPeso() > animalSegundo->getPeso())
			{
				cambios = true;
				animalAuxiliar = static_cast<PtrAnimal>(removerDeLista(animales, i));
				insertarDatoLista(animales, static_cast<PtrAnimal>(animalAuxiliar), i + salto);
			}
		}

		if (!cambios)
		{
			salto = (salto / 2);
		}
	}
}

void centro::ordenarAnimalesAltura()
{
	PtrAnimal animalPrimero = NULL;
	PtrAnimal animalSegundo = NULL;
	PtrAnimal animalAuxiliar = NULL;
	int largo = longitudLista(animales);
	int salto = (largo / 2);
	bool cambios = true;

	while (salto > 0)
	{
		cambios = false;

		for (int i = 0; i < largo - salto; i++)
		{
			animalPrimero = static_cast<PtrAnimal>(getDatoLista(animales, i));
			animalSegundo = static_cast<PtrAnimal>(getDatoLista(animales, i + salto));

			if (animalPrimero->getAltura() > animalSegundo->getAltura())
			{
				cambios = true;
				animalAuxiliar = static_cast<PtrAnimal>(removerDeLista(animales, i));
				insertarDatoLista(animales, static_cast<PtrAnimal>(animalAuxiliar), i + salto);
			}
		}

		if (!cambios)
		{
			salto = (salto / 2);
		}
	}
}

void centro::ordenarAnimalesEspecie()
{
	PtrAnimal animalPrimero = NULL;
	PtrAnimal animalSegundo = NULL;
	PtrAnimal animalAuxiliar = NULL;
	int largo = longitudLista(animales);
	int salto = (largo / 2);
	int resultadoComparacion = 0;
	bool cambios = true;

	while (salto > 0)
	{
		cambios = false;

		for (int i = 0; i < largo - salto; i++)
		{
			animalPrimero = static_cast<PtrAnimal>(getDatoLista(animales, i));
			animalSegundo = static_cast<PtrAnimal>(getDatoLista(animales, i + salto));
			resultadoComparacion = animalPrimero->getEspecie().compare(animalSegundo->getEspecie());

			if ( resultadoComparacion > 0 )
			{
				cambios = true;
				animalAuxiliar = static_cast<PtrAnimal>(removerDeLista(animales, i));
				insertarDatoLista(animales, static_cast<PtrAnimal>(animalAuxiliar), i + salto);
			}
		}

		if (!cambios)
		{
			salto = (salto / 2);
		}
	}
}

void centro::ordenarAnimalesRaza()
{
	PtrAnimal animalPrimero = NULL;
	PtrAnimal animalSegundo = NULL;
	PtrAnimal animalAuxiliar = NULL;
	int largo = longitudLista(animales);
	int salto = (largo / 2);
	int resultadoComparacion = 0;
	bool cambios = true;

	while (salto > 0)
	{
		cambios = false;

		for (int i = 0; i < largo - salto; i++)
		{
			animalPrimero = static_cast<PtrAnimal>(getDatoLista(animales, i));
			animalSegundo = static_cast<PtrAnimal>(getDatoLista(animales, i + salto));
			resultadoComparacion = animalPrimero->getRaza().compare(animalSegundo->getRaza());

			if (resultadoComparacion > 0)
			{
				cambios = true;
				animalAuxiliar = static_cast<PtrAnimal>(removerDeLista(animales, i));
				insertarDatoLista(animales, static_cast<PtrAnimal>(animalAuxiliar), i + salto);
			}
		}

		if (!cambios)
		{
			salto = (salto / 2);
		}
	}
}

void centro::ordenarAnimalesCategoria()
{
	PtrAnimal animalPrimero = NULL;
	PtrAnimal animalSegundo = NULL;
	PtrAnimal animalAuxiliar = NULL;
	int largo = longitudLista(animales);
	int salto = (largo / 2);
	int resultadoComparacion = 0;
	bool cambios = true;

	while (salto > 0)
	{
		cambios = false;

		for (int i = 0; i < largo - salto; i++)
		{
			animalPrimero = static_cast<PtrAnimal>(getDatoLista(animales, i));
			animalSegundo = static_cast<PtrAnimal>(getDatoLista(animales, i + salto));
			resultadoComparacion = animalPrimero->getCategoria().compare(animalSegundo->getCategoria());

			if (resultadoComparacion > 0)
			{
				cambios = true;
				animalAuxiliar = static_cast<PtrAnimal>(removerDeLista(animales, i));
				insertarDatoLista(animales, static_cast<PtrAnimal>(animalAuxiliar), i + salto);
			}
		}

		if (!cambios)
		{
			salto = (salto / 2);
		}
	}
}

void centro::ordenarAnimalesBiologia()
{
	PtrAnimal animalPrimero = NULL;
	PtrAnimal animalSegundo = NULL;
	PtrAnimal animalAuxiliar = NULL;
	int largo = longitudLista(animales);
	int salto = (largo / 2);
	int resultadoComparacion = 0;
	bool cambios = true;

	while (salto > 0)
	{
		cambios = false;

		for (int i = 0; i < largo - salto; i++)
		{
			animalPrimero = static_cast<PtrAnimal>(getDatoLista(animales, i));
			animalSegundo = static_cast<PtrAnimal>(getDatoLista(animales, i + salto));
			resultadoComparacion = animalPrimero->getBiologia().compare(animalSegundo->getBiologia());

			if (resultadoComparacion > 0)
			{
				cambios = true;
				animalAuxiliar = static_cast<PtrAnimal>(removerDeLista(animales, i));
				insertarDatoLista(animales, static_cast<PtrAnimal>(animalAuxiliar), i + salto);
			}
		}

		if (!cambios)
		{
			salto = (salto / 2);
		}
	}
}

void centro::ordenarAnimalesGenero()
{
	PtrAnimal animalPrimero = NULL;
	PtrAnimal animalSegundo = NULL;
	PtrAnimal animalAuxiliar = NULL;
	int largo = longitudLista(animales);
	int salto = (largo / 2);
	int resultadoComparacion = 0;
	bool cambios = true;

	while (salto > 0)
	{
		cambios = false;

		for (int i = 0; i < largo - salto; i++)
		{
			animalPrimero = static_cast<PtrAnimal>(getDatoLista(animales, i));
			animalSegundo = static_cast<PtrAnimal>(getDatoLista(animales, i + salto));
			resultadoComparacion = animalPrimero->getGenero().compare(animalSegundo->getGenero());

			if (resultadoComparacion > 0)
			{
				cambios = true;
				animalAuxiliar = static_cast<PtrAnimal>(removerDeLista(animales, i));
				insertarDatoLista(animales, static_cast<PtrAnimal>(animalAuxiliar), i + salto);
			}
		}

		if (!cambios)
		{
			salto = (salto / 2);
		}
	}
}

void centro::ordenarEmpleadosNombre()
{
	PtrPersona empleadoPrimero = NULL;
	PtrPersona empleadoSegundo = NULL;
	PtrPersona empleadoAuxiliar = NULL;
	int largo = longitudLista(empleados);
	int salto = (largo / 2);
	int resultadoComparacion = 0;
	bool cambios = true;

	while (salto > 0)
	{
		cambios = false;

		for (int i = 0; i < largo - salto; i++)
		{
			empleadoPrimero = static_cast<PtrPersona>(getDatoLista(empleados, i));
			empleadoSegundo = static_cast<PtrPersona>(getDatoLista(empleados, i + salto));
			resultadoComparacion = empleadoPrimero->getNombre().compare(empleadoSegundo->getNombre());

			if (resultadoComparacion > 0)
			{
				cambios = true;
				empleadoAuxiliar = static_cast<PtrPersona>(removerDeLista(empleados, i));
				insertarDatoLista(empleados, static_cast<PtrPersona>(empleadoAuxiliar), i + salto);
			}
		}

		if (!cambios)
		{
			salto = (salto / 2);
		}
	}
}

void centro::ordenarEmpleadosApellido()
{
	PtrPersona empleadoPrimero = NULL;
	PtrPersona empleadoSegundo = NULL;
	PtrPersona empleadoAuxiliar = NULL;
	int largo = longitudLista(empleados);
	int salto = (largo / 2);
	int resultadoComparacion = 0;
	bool cambios = true;

	while (salto > 0)
	{
		cambios = false;

		for (int i = 0; i < largo - salto; i++)
		{
			empleadoPrimero = static_cast<PtrPersona>(getDatoLista(empleados, i));
			empleadoSegundo = static_cast<PtrPersona>(getDatoLista(empleados, i + salto));
			resultadoComparacion = empleadoPrimero->getApellido().compare(empleadoSegundo->getApellido());

			if (resultadoComparacion > 0)
			{
				cambios = true;
				empleadoAuxiliar = static_cast<PtrPersona>(removerDeLista(empleados, i));
				insertarDatoLista(empleados, static_cast<PtrPersona>(empleadoAuxiliar), i + salto);
			}
		}

		if (!cambios)
		{
			salto = (salto / 2);
		}
	}
}

void centro::ordenarEmpleadosAmbos()
{
	PtrPersona empleadoPrimero = NULL;
	PtrPersona empleadoSegundo = NULL;
	PtrPersona empleadoAuxiliar = NULL;
	int largo = longitudLista(empleados);
	int salto = (largo / 2);
	int resultadoComparacion_1 = 0;
	int resultadoComparacion_2  = 0;
	bool cambios = true;

	while (salto > 0)
	{
		cambios = false;

		for (int i = 0; i < largo - salto; i++)
		{
			empleadoPrimero = static_cast<PtrPersona>(getDatoLista(empleados, i));
			empleadoSegundo = static_cast<PtrPersona>(getDatoLista(empleados, i + salto));
			resultadoComparacion_1 = empleadoPrimero->getNombre().compare(empleadoSegundo->getNombre());
			resultadoComparacion_2 = empleadoPrimero->getApellido().compare(empleadoSegundo->getApellido());

			if (resultadoComparacion_1 >= 0 && resultadoComparacion_2 > 0 )
			{
				cambios = true;
				empleadoAuxiliar = static_cast<PtrPersona>(removerDeLista(empleados, i));
				insertarDatoLista(empleados, static_cast<PtrPersona>(empleadoAuxiliar), i + salto);
			}
			else if (resultadoComparacion_1 > 0 && resultadoComparacion_2 >= 0)
			{
				cambios = true;
				empleadoAuxiliar = static_cast<PtrPersona>(removerDeLista(empleados, i));
				insertarDatoLista(empleados, static_cast<PtrPersona>(empleadoAuxiliar), i + salto);
			}
		}

		if (!cambios)
		{
			salto = (salto / 2);
		}
	}
}

void centro::ordenarEmpleadosCuil()
{
	PtrPersona empleadoPrimero = NULL;
	PtrPersona empleadoSegundo = NULL;
	PtrPersona empleadoAuxiliar = NULL;
	int largo = longitudLista(empleados);
	int salto = (largo / 2);
	int resultadoComparacion = 0;
	bool cambios = true;

	while (salto > 0)
	{
		cambios = false;

		for (int i = 0; i < largo - salto; i++)
		{
			empleadoPrimero = static_cast<PtrPersona>(getDatoLista(empleados, i));
			empleadoSegundo = static_cast<PtrPersona>(getDatoLista(empleados, i + salto));
			resultadoComparacion = empleadoPrimero->getCuil()->getCuil().compare(empleadoSegundo->getCuil()->getCuil());

			if (resultadoComparacion > 0 )
			{
				cambios = true;
				empleadoAuxiliar = static_cast<PtrPersona>(removerDeLista(empleados, i));
				insertarDatoLista(empleados, static_cast<PtrPersona>(empleadoAuxiliar), i + salto);
			}
		}

		if (!cambios)
		{
			salto = (salto / 2);
		}
	}
}

void centro::filtrarAnimalAltura(int alturaBuscada)
{
	PtrAnimal animalAuxiliar = NULL;
	PtrLista listaAuxiliar = crearLista();
	agregarLista(listaAuxiliar, animales);
	
	while ( !listaVacia(listaAuxiliar) )
	{
		animalAuxiliar = static_cast<PtrAnimal>(getCabecera(listaAuxiliar));
		PtrLista listaDestruir = listaAuxiliar;
		listaAuxiliar = getResto(listaAuxiliar);
		listaDestruir = destruirLista(listaDestruir, false);

		if (animalAuxiliar->getAltura() == alturaBuscada)
		{
			animalAuxiliar->mostrar();
		}
	}
	listaAuxiliar = destruirLista(listaAuxiliar, false);
}

void centro::filtrarAnimalEdad(int edadBuscada)
{
	PtrAnimal animalAuxiliar = NULL;
	PtrLista listaAuxiliar = crearLista();
	agregarLista(listaAuxiliar, animales);

	while (!listaVacia(listaAuxiliar))
	{
		animalAuxiliar = static_cast<PtrAnimal>(getCabecera(listaAuxiliar));
		PtrLista listaDestruir = listaAuxiliar;
		listaAuxiliar = getResto(listaAuxiliar);
		listaDestruir = destruirLista(listaDestruir, false);

		if (animalAuxiliar->getAltura() == edadBuscada)
		{
			animalAuxiliar->mostrar();
		}
	}
	listaAuxiliar = destruirLista(listaAuxiliar, false);
}

void centro::filtrarAnimalPeso(int pesoBuscada)
{
	PtrAnimal animalAuxiliar = NULL;
	PtrLista listaAuxiliar = crearLista();
	agregarLista(listaAuxiliar, animales);

	while (!listaVacia(listaAuxiliar))
	{
		animalAuxiliar = static_cast<PtrAnimal>(getCabecera(listaAuxiliar));
		PtrLista listaDestruir = listaAuxiliar;
		listaAuxiliar = getResto(listaAuxiliar);
		listaDestruir = destruirLista(listaDestruir, false);

		if (animalAuxiliar->getAltura() == pesoBuscada)
		{
			animalAuxiliar->mostrar();
		}
	}
	listaAuxiliar = destruirLista(listaAuxiliar, false);
}

void centro::filtrarAnimalEspecie(string especieBuscada)
{
	PtrAnimal animalAuxiliar = NULL;
	int resultadoComparacion = 0;
	PtrLista listaAuxiliar = crearLista();
	agregarLista(listaAuxiliar, animales);

	while (!listaVacia(listaAuxiliar))
	{
		animalAuxiliar = static_cast<PtrAnimal>(getCabecera(listaAuxiliar));
		PtrLista listaDestruir = listaAuxiliar;
		listaAuxiliar = getResto(listaAuxiliar);
		listaDestruir = destruirLista(listaDestruir, false);
		resultadoComparacion = animalAuxiliar->getEspecie().compare(especieBuscada);

		if (resultadoComparacion == 0)
		{
			animalAuxiliar->mostrar();
		}
	}
	listaAuxiliar = destruirLista(listaAuxiliar, false);
}

void centro::filtrarAnimalRaza(string razaBuscada)
{
	PtrAnimal animalAuxiliar = NULL;
	int resultadoComparacion = 0;
	PtrLista listaAuxiliar = crearLista();
	agregarLista(listaAuxiliar, animales);

	while (!listaVacia(listaAuxiliar))
	{
		animalAuxiliar = static_cast<PtrAnimal>(getCabecera(listaAuxiliar));
		PtrLista listaDestruir = listaAuxiliar;
		listaAuxiliar = getResto(listaAuxiliar);
		listaDestruir = destruirLista(listaDestruir, false);
		resultadoComparacion = animalAuxiliar->getRaza().compare(razaBuscada);

		if (resultadoComparacion == 0)
		{
			animalAuxiliar->mostrar();
		}
	}
	listaAuxiliar = destruirLista(listaAuxiliar, false);
}

void centro::filtrarAnimalCategoria(string categoriaBuscada)
{
	PtrAnimal animalAuxiliar = NULL;
	int resultadoComparacion = 0;
	PtrLista listaAuxiliar = crearLista();
	agregarLista(listaAuxiliar, animales);

	while (!listaVacia(listaAuxiliar))
	{
		animalAuxiliar = static_cast<PtrAnimal>(getCabecera(listaAuxiliar));
		PtrLista listaDestruir = listaAuxiliar;
		listaAuxiliar = getResto(listaAuxiliar);
		listaDestruir = destruirLista(listaDestruir, false);
		resultadoComparacion = animalAuxiliar->getEspecie().compare(categoriaBuscada);

		if (resultadoComparacion == 0)
		{
			animalAuxiliar->mostrar();
		}
	}
	listaAuxiliar = destruirLista(listaAuxiliar, false);
}

void centro::filtrarAnimalBiologia(string biologiaBuscada)
{
	PtrAnimal animalAuxiliar = NULL;
	int resultadoComparacion = 0;
	PtrLista listaAuxiliar = crearLista();
	agregarLista(listaAuxiliar, animales);

	while (!listaVacia(listaAuxiliar))
	{
		animalAuxiliar = static_cast<PtrAnimal>(getCabecera(listaAuxiliar));
		PtrLista listaDestruir = listaAuxiliar;
		listaAuxiliar = getResto(listaAuxiliar);
		listaDestruir = destruirLista(listaDestruir, false);
		resultadoComparacion = animalAuxiliar->getEspecie().compare(biologiaBuscada);

		if (resultadoComparacion == 0)
		{
			animalAuxiliar->mostrar();
		}
	}
	listaAuxiliar = destruirLista(listaAuxiliar, false);
}

void centro::filtrarAnimalGenero(string generoBuscada)
{
	PtrAnimal animalAuxiliar = NULL;
	int resultadoComparacion = 0;
	PtrLista listaAuxiliar = crearLista();
	agregarLista(listaAuxiliar, animales);

	while (!listaVacia(listaAuxiliar))
	{
		animalAuxiliar = static_cast<PtrAnimal>(getCabecera(listaAuxiliar));
		PtrLista listaDestruir = listaAuxiliar;
		listaAuxiliar = getResto(listaAuxiliar);
		listaDestruir = destruirLista(listaDestruir, false);
		resultadoComparacion = animalAuxiliar->getEspecie().compare(generoBuscada);

		if (resultadoComparacion == 0)
		{
			animalAuxiliar->mostrar();
		}
	}
	listaAuxiliar = destruirLista(listaAuxiliar, false);
}

void centro::filtrarEmpleadoNombre(string nombreBuscado)
{
	PtrPersona empleadoAuxiliar = NULL;
	int resultadoComparacion = 0;
	PtrLista listaAuxiliar = crearLista();
	agregarLista(listaAuxiliar, empleados);

	while (!listaVacia(listaAuxiliar))
	{
		empleadoAuxiliar = static_cast<PtrPersona>(getCabecera(listaAuxiliar));
		PtrLista listaDestruir = listaAuxiliar;
		listaAuxiliar = getResto(listaAuxiliar);
		listaDestruir = destruirLista(listaDestruir, false);
		resultadoComparacion = empleadoAuxiliar->getNombre().compare(nombreBuscado);

		if (resultadoComparacion == 0)
		{
			empleadoAuxiliar->mostrar();
		}
	}
	listaAuxiliar = destruirLista(listaAuxiliar, false);
}

void centro::filtrarEmpleadoApellido(string apellidoBuscado)
{
	PtrPersona empleadoAuxiliar = NULL;
	int resultadoComparacion = 0;
	PtrLista listaAuxiliar = crearLista();
	agregarLista(listaAuxiliar, empleados);

	while (!listaVacia(listaAuxiliar))
	{
		empleadoAuxiliar = static_cast<PtrPersona>(getCabecera(listaAuxiliar));
		PtrLista listaDestruir = listaAuxiliar;
		listaAuxiliar = getResto(listaAuxiliar);
		listaDestruir = destruirLista(listaDestruir, false);
		resultadoComparacion = empleadoAuxiliar->getApellido().compare(apellidoBuscado);

		if (resultadoComparacion == 0)
		{
			empleadoAuxiliar->mostrar();
		}
	}
	listaAuxiliar = destruirLista(listaAuxiliar, false);
}

void centro::filtrarEmpleadoCalle(string calleBuscado)
{
	PtrPersona empleadoAuxiliar = NULL;
	int resultadoComparacion = 0;
	PtrLista listaAuxiliar = crearLista();
	agregarLista(listaAuxiliar, empleados);

	while (!listaVacia(listaAuxiliar))
	{
		empleadoAuxiliar = static_cast<PtrPersona>(getCabecera(listaAuxiliar));
		PtrLista listaDestruir = listaAuxiliar;
		listaAuxiliar = getResto(listaAuxiliar);
		listaDestruir = destruirLista(listaDestruir, false);
		resultadoComparacion = empleadoAuxiliar->getDomicilio()->getCalle().compare(calleBuscado);

		if (resultadoComparacion == 0)
		{
			empleadoAuxiliar->mostrar();
		}
	}
	listaAuxiliar = destruirLista(listaAuxiliar, false);
}

void centro::filtrarEmpleadoNumero(int numeroBuscada)
{
	PtrPersona empleadoAuxiliar = NULL;
	PtrLista listaAuxiliar = crearLista();
	agregarLista(listaAuxiliar, empleados);

	while (!listaVacia(listaAuxiliar))
	{
		empleadoAuxiliar = static_cast<PtrPersona>(getCabecera(listaAuxiliar));
		PtrLista listaDestruir = listaAuxiliar;
		listaAuxiliar = getResto(listaAuxiliar);
		listaDestruir = destruirLista(listaDestruir, false);

		if (empleadoAuxiliar->getDomicilio()->getNumero() == numeroBuscada)
		{
			empleadoAuxiliar->mostrar();
		}
	}
	listaAuxiliar = destruirLista(listaAuxiliar, false);
}

void centro::filtrarEmpleadoLocalidad(string localidadBuscado)
{
	PtrPersona empleadoAuxiliar = NULL;
	int resultadoComparacion = 0;
	PtrLista listaAuxiliar = crearLista();
	agregarLista(listaAuxiliar, empleados);

	while (!listaVacia(listaAuxiliar))
	{
		empleadoAuxiliar = static_cast<PtrPersona>(getCabecera(listaAuxiliar));
		PtrLista listaDestruir = listaAuxiliar;
		listaAuxiliar = getResto(listaAuxiliar);
		listaDestruir = destruirLista(listaDestruir, false);
		resultadoComparacion = empleadoAuxiliar->getDomicilio()->getLocalidad().compare(localidadBuscado);

		if (resultadoComparacion == 0)
		{
			empleadoAuxiliar->mostrar();
		}
	}
}

void centro::filtrarEmpleadoEdad(int edadBuscada)
{
	PtrPersona empleadoAuxiliar = NULL;
	PtrLista listaAuxiliar = crearLista();
	agregarLista(listaAuxiliar, empleados);

	while (!listaVacia(listaAuxiliar))
	{
		empleadoAuxiliar = static_cast<PtrPersona>(getCabecera(listaAuxiliar));
		PtrLista listaDestruir = listaAuxiliar;
		listaAuxiliar = getResto(listaAuxiliar);
		listaDestruir = destruirLista(listaDestruir, false);

		if (empleadoAuxiliar->getEdad() == edadBuscada)
		{
			empleadoAuxiliar->mostrar();
		}
	}
	listaAuxiliar = destruirLista(listaAuxiliar, false);
}

void centro::filtrarEmpleadoAntiguedad(int antiguedadBuscada)
{
	PtrPersona empleadoAuxiliar = NULL;
	PtrLista listaAuxiliar = crearLista();
	agregarLista(listaAuxiliar, empleados);

	while (!listaVacia(listaAuxiliar))
	{
		empleadoAuxiliar = static_cast<PtrPersona>(getCabecera(listaAuxiliar));
		PtrLista listaDestruir = listaAuxiliar;
		listaAuxiliar = getResto(listaAuxiliar);
		listaDestruir = destruirLista(listaDestruir, false);

		if (empleadoAuxiliar->getAntiguedad() == antiguedadBuscada)
		{
			empleadoAuxiliar->mostrar();
		}
	}
	listaAuxiliar = destruirLista(listaAuxiliar, false);
}

void centro::filtrarEmpleadoCuil(string cuilBuscado)
{
	PtrPersona empleadoAuxiliar = NULL;
	int resultadoComparacion = 0;
	PtrLista listaAuxiliar = crearLista();
	agregarLista(listaAuxiliar, empleados);

	while (!listaVacia(listaAuxiliar))
	{
		empleadoAuxiliar = static_cast<PtrPersona>(getCabecera(listaAuxiliar));
		PtrLista listaDestruir = listaAuxiliar;
		listaAuxiliar = getResto(listaAuxiliar);
		listaDestruir = destruirLista(listaDestruir, false);
		resultadoComparacion = empleadoAuxiliar->getCuil()->getCuil().compare(cuilBuscado);

		if (resultadoComparacion == 0)
		{
			empleadoAuxiliar->mostrar();
		}
	}
}

PtrAnimal centro::buscarAnimalManual()
{
	int respuesta = 0;
	int eleccionEntero = 0;
	string eleccionString;
	int cantidadDisponible = 0;
	int resultadoComparacion = 0;
	cout << "1. Buscar por edad" << endl;
	cout << "2. Buscar por altura" << endl;
	cout << "3. Buscar por peso" << endl;
	cout << "4. Buscar por especie" << endl;
	cout << "5. Buscar por raza" << endl;
	cout << "6. Buscar por categoria" << endl;
	cout << "7. Buscar por biologia" << endl;
	cout << "8. Buscar por genero" << endl;
	cout << "0. Volver" << endl;
	cin >> respuesta;

	switch (respuesta)
	{
		case 1:
			cout << "Seleccione la edad: ";
			cin >> eleccionEntero;
			break;
		case 2:
			cout << "Seleccione la altura: ";
			cin >> eleccionEntero;
			break;
		case 3:
			cout << "Seleccione el peso: ";
			cin >> eleccionEntero;
			break;
		case 4:
			cout << "Seleccione la especie: ";
			cin >> eleccionString;
			break;
		case 5:
			cout << "Seleccione la raza: ";
			cin >> eleccionString;
			break;
		case 6:
			cout << "Seleccione la categoria: ";
			cin >> eleccionString;
			break;
		case 7:
			cout << "Seleccione la biologia: ";
			cin >> eleccionString;
			break;
		case 8:
			cout << "Seleccione la genero: ";
			cin >> eleccionString;
			break;
		case 0:
			return NULL;
			break;
	}

	PtrAnimal animalAuxiliar = NULL;
	PtrLista listaAuxiliar = crearLista();
	PtrLista listaRecopilar = crearLista();
	agregarLista(listaAuxiliar, empleados);

	while (!listaVacia(listaAuxiliar))
	{
		animalAuxiliar = static_cast<PtrAnimal>(getCabecera(listaAuxiliar));
		PtrLista listaDestruir = listaAuxiliar;
		listaAuxiliar = getResto(listaAuxiliar);
		listaDestruir = destruirLista(listaDestruir, false);

		switch (respuesta)
		{
			case 1:
				if (animalAuxiliar->getEdad() == eleccionEntero)
				{
					cout << cantidadDisponible << " ";
					animalAuxiliar->mostrar();
					cantidadDisponible++;
					insertarDatoLista(listaRecopilar, static_cast<PtrAnimal>(animalAuxiliar), 0);
				}
				break;
			case 2:
				if (animalAuxiliar->getAltura() == eleccionEntero)
				{
					cout << cantidadDisponible << " ";
					animalAuxiliar->mostrar();
					cantidadDisponible++;
					insertarDatoLista(listaRecopilar, static_cast<PtrAnimal>(animalAuxiliar), 0);
				}
				break;
			case 3:
				if (animalAuxiliar->getPeso() == eleccionEntero)
				{
					cout << cantidadDisponible << " ";
					animalAuxiliar->mostrar();
					cantidadDisponible++;
					insertarDatoLista(listaRecopilar, static_cast<PtrAnimal>(animalAuxiliar), 0);
				}
				break;
			case 4:
				resultadoComparacion = animalAuxiliar->getEspecie().compare(eleccionString);
				if (resultadoComparacion == 0)
				{
					cout << cantidadDisponible << " ";
					animalAuxiliar->mostrar();
					cantidadDisponible++;
					insertarDatoLista(listaRecopilar, static_cast<PtrAnimal>(animalAuxiliar), 0);
				}
				break;
			case 5:
				resultadoComparacion = animalAuxiliar->getRaza().compare(eleccionString);
				if (resultadoComparacion == 0)
				{
					cout << cantidadDisponible << " ";
					animalAuxiliar->mostrar();
					cantidadDisponible++;
					insertarDatoLista(listaRecopilar, static_cast<PtrAnimal>(animalAuxiliar), 0);
				}
				break;
			case 6:
				resultadoComparacion = animalAuxiliar->getCategoria().compare(eleccionString);
				if (resultadoComparacion == 0)
				{
					cout << cantidadDisponible << " ";
					animalAuxiliar->mostrar();
					cantidadDisponible++;
					insertarDatoLista(listaRecopilar, static_cast<PtrAnimal>(animalAuxiliar), 0);
				}
				break;
			case 7:
				resultadoComparacion = animalAuxiliar->getBiologia().compare(eleccionString);
				if (resultadoComparacion == 0)
				{
					cout << cantidadDisponible << " ";
					animalAuxiliar->mostrar();
					cantidadDisponible++;
					insertarDatoLista(listaRecopilar, static_cast<PtrAnimal>(animalAuxiliar), 0);
				}
				break;
			case 8:
				resultadoComparacion = animalAuxiliar->getGenero().compare(eleccionString);
				if (resultadoComparacion == 0)
				{
					cout << cantidadDisponible << " ";
					animalAuxiliar->mostrar();
					cantidadDisponible++;
					insertarDatoLista(listaRecopilar, static_cast<PtrAnimal>(animalAuxiliar), 0);
				}
				break;
			case 0:
				return NULL;
				break;
		}
	}

	cout << "Elige el que buscaba";
	cin >> respuesta;
	animalAuxiliar = static_cast<PtrAnimal>(getDatoLista(listaRecopilar, respuesta));
	listaRecopilar = destruirLista(listaRecopilar, false);

	return animalAuxiliar;
}

PtrPersona centro::buscarEmpleadoManual()
{
	int respuesta = 0;
	int eleccionEntero = 0;
	string eleccionString;
	int cantidadDisponible = 0;
	int resultadoComparacion = 0;
	cout << "1. Buscar por nombre" << endl;
	cout << "2. Buscar por apellido" << endl;
	cout << "3. Buscar por calle" << endl;
	cout << "4. Buscar por numero" << endl;
	cout << "5. Buscar por localidad" << endl;
	cout << "6. Buscar por cuil" << endl;
	cout << "7. Buscar por edad" << endl;
	cout << "8. Buscar por antiguedad" << endl;
	cout << "0. Volver" << endl;
	cin >> respuesta;

	switch (respuesta)
	{
	case 1:
		cout << "Seleccione el nombre: ";
		cin >> eleccionString;
		break;
	case 2:
		cout << "Seleccione el apellido: ";
		cin >> eleccionString;
		break;
	case 3:
		cout << "Seleccione la calle: ";
		cin >> eleccionEntero;
		break;
	case 4:
		cout << "Seleccione el numero: ";
		cin >> eleccionEntero;
		break;
	case 5:
		cout << "Seleccione la localidad: ";
		cin >> eleccionString;
		break;
	case 6:
		cout << "Seleccione el cuil: ";
		cin >> eleccionString;
		break;
	case 7:
		cout << "Seleccione la edad: ";
		cin >> eleccionEntero;
		break;
	case 8:
		cout << "Seleccione la antiguedad: ";
		cin >> eleccionEntero;
		break;
	case 0:
		return NULL;
		break;
	}

	PtrPersona empleadoAuxiliar = NULL;
	PtrLista listaAuxiliar = crearLista();
	PtrLista listaRecopilar = crearLista();
	agregarLista(listaAuxiliar, empleados);

	while (!listaVacia(listaAuxiliar))
	{
		empleadoAuxiliar = static_cast<PtrPersona>(getCabecera(listaAuxiliar));
		PtrLista listaDestruir = listaAuxiliar;
		listaAuxiliar = getResto(listaAuxiliar);
		listaDestruir = destruirLista(listaDestruir, false);

		switch (respuesta)
		{
		case 1:
			resultadoComparacion = empleadoAuxiliar->getNombre().compare(eleccionString);
			if (resultadoComparacion == 0)
			{
				cout << cantidadDisponible << " ";
				empleadoAuxiliar->mostrar();
				cantidadDisponible++;
				insertarDatoLista(listaRecopilar, static_cast<PtrPersona>(empleadoAuxiliar), 0);
			}
			break;
		case 2:
			resultadoComparacion = empleadoAuxiliar->getApellido().compare(eleccionString);
			if (resultadoComparacion == 0)
			{
				cout << cantidadDisponible << " ";
				empleadoAuxiliar->mostrar();
				cantidadDisponible++;
				insertarDatoLista(listaRecopilar, static_cast<PtrPersona>(empleadoAuxiliar), 0);
			}
			break;
		case 3:
			resultadoComparacion = empleadoAuxiliar->getDomicilio()->getCalle().compare(eleccionString);
			if (resultadoComparacion == 0)
			{
				cout << cantidadDisponible << " ";
				empleadoAuxiliar->mostrar();
				cantidadDisponible++;
				insertarDatoLista(listaRecopilar, static_cast<PtrPersona>(empleadoAuxiliar), 0);
			}
			break;
		case 4:
			if (empleadoAuxiliar->getDomicilio()->getNumero() == eleccionEntero)
			{
				cout << cantidadDisponible << " ";
				empleadoAuxiliar->mostrar();
				cantidadDisponible++;
				insertarDatoLista(listaRecopilar, static_cast<PtrPersona>(empleadoAuxiliar), 0);
			}
			break;
		case 5:
			resultadoComparacion = empleadoAuxiliar->getDomicilio()->getLocalidad().compare(eleccionString);
			if (resultadoComparacion == 0)
			{
				cout << cantidadDisponible << " ";
				empleadoAuxiliar->mostrar();
				cantidadDisponible++;
				insertarDatoLista(listaRecopilar, static_cast<PtrPersona>(empleadoAuxiliar), 0);
			}
			break;
		case 6:
			resultadoComparacion = empleadoAuxiliar->getCuil()->getCuil().compare(eleccionString);
			if (resultadoComparacion == 0)
			{
				cout << cantidadDisponible << " ";
				empleadoAuxiliar->mostrar();
				cantidadDisponible++;
				insertarDatoLista(listaRecopilar, static_cast<PtrPersona>(empleadoAuxiliar), 0);
			}
			break;
		case 7:
			if (empleadoAuxiliar->getEdad() == eleccionEntero)
			{
				cout << cantidadDisponible << " ";
				empleadoAuxiliar->mostrar();
				cantidadDisponible++;
				insertarDatoLista(listaRecopilar, static_cast<PtrPersona>(empleadoAuxiliar), 0);
			}
			break;
		case 8:
			if (empleadoAuxiliar->getAntiguedad() == eleccionEntero)
			{
				cout << cantidadDisponible << " ";
				empleadoAuxiliar->mostrar();
				cantidadDisponible++;
				insertarDatoLista(listaRecopilar, static_cast<PtrPersona>(empleadoAuxiliar), 0);
			}
			break;
		case 0:
			return NULL;
			break;
		}
	}

	cout << "Elige el que buscaba";
	cin >> respuesta;
	empleadoAuxiliar = static_cast<PtrPersona>(getDatoLista(listaRecopilar, respuesta));
	listaRecopilar = destruirLista(listaRecopilar, false);

	return empleadoAuxiliar;
}