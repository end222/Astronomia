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

		if (i != datos.numLibros)
		{
			score = atoi(strtok(NULL, delim));
		}
	}

	i = 0;
	while (i < datos.numLibrerias)
	{
		cin.getline(line,1000);
		cout << "Bucle " << i << endl;
		datos.libs[i].numeroLibros = atoi(strtok(line, delim));
		datos.libs[i].signup = atoi(strtok(NULL, delim));
		datos.libs[i].booksPerDay = atoi(strtok(NULL, delim));
		cout << " He llegado" << endl;

		int j = 0;
		cin.getline(line,1000);
		int bookId = atoi(strtok(line, delim));
		while (j < datos.libs[i].numeroLibros)
		{
			datos.libs[i].libros[j] = bookId;
			j++;
			
			if (j != datos.libs[i].numeroLibros)
			{
				bookId = atoi(strtok(NULL, delim));
			}
		}
		i++;
	}


	// Algoritmo
	
	// Output
	
	cout << datos.numLibrerias << endl;
	i = 0;
	while (i < datos.numLibrerias)
	{
		cout << i << " " << datos.libs[i].numeroLibros << endl;
		int j = 0;
		while (j < datos.libs[i].numeroLibros)
		{
			cout << datos.libs[i].libros[j] << flush;
			if (j != datos.libs[i].numeroLibros)
			{
				cout << " " << flush;
			}
		}
	}
}
