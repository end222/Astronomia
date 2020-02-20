#include <iostream>
#include <string>
#include <string.h>

using namespace std;

const int MAX = 10000;

struct libreria
{
	int numeroLibros;
	int libros[MAX];
	int signup;
	int booksPerDay;
};

struct general
{
	int numLibros;
	int numLibrerias;
	int dias;
	int scores[MAX];
	bool taken[MAX];
	libreria libs[MAX];
};
/*
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
*/
int main()
{
	general datos;

	// Put everything to zero so as to avoid errors
	for(int i = 0; i < MAX; i++)
	{
		datos.taken[i] = false;
	}
	
	// Se lee la primera linea
	char line[1000];
	cin.getline(line,1000);
	// El delimitador es un espacio en blanco
	char delim[] = " ";
	int i = 0;

	datos.numLibros = atoi(strtok(line, delim));
	datos.numLibrerias = atoi(strtok(NULL, delim));
	datos.dias = atoi(strtok(NULL, delim));

	cin.getline(line,1000);

	int score = atoi(strtok(line, delim));
	while (i < datos.numLibros)
	{
		datos.scores[i] = score;
		i++;

		if (i == datos.numLibros)
		{
			score = atoi(strtok(NULL, delim));
		}
	}

	i = 0;
	while (i < datos.numLibrerias)
	{
		cin.getline(line,1000);
		datos.libs[i].numeroLibros = atoi(strtok(line, delim));
		datos.libs[i].signup = atoi(strtok(NULL, delim));
		datos.libs[i].booksPerDay = atoi(strtok(NULL, delim));

		int j = 0;
		while (j < datos.libs[i].numeroLibros)
		{

		}
	}
}
