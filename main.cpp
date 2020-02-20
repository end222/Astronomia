#include <iostream>
#include <string>

const int MAX = 10000;

struct libreria
{
	int numeroLibros;
	int libros[MAX];
	int scan;
};

struct general
{
	int numLibros;
	int numLibrerias;
	int scores[MAX];
	bool taken[MAX];
	libreria libs[MAX];
};
void readInput()
{
	// Se lee la primera linea
	char line[1000];
	cin.getline(line,1000);
	// El delimitador es un espacio en blanco
	char delim[] = " ";
	int i = 0;
	int numeroFotos = atoi(strtok(line, delim));
	while(i < numeroFotos){
		foto fotoameter;
		fotoameter.id = i;
		int j = 0;
		cin.getline(line,1000);
		char* orientacion = strtok(line, delim);
		char trueOrientacion = *orientacion;
		fotoameter.orientacion = trueOrientacion;
		int numTags = atoi(strtok(NULL, delim));
		while(j < numTags){
			fotoameter.tags.push_back(strtok(NULL,delim));
			j++;
		}
		fotoameter.numTags = j;
		listaFotos.push_back(fotoameter);
		i++;
	}
}

int main()
{
	general datos;

	// Put everything to zero so as to avoid errors
	for(int i = 0; i < MAX; i++)
	{
		datos.taken[i] = false;
	}
}
