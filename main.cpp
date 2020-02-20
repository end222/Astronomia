#include <iostream>
#include <string>
#include <string.h>

using namespace std;

const int MAX = 10000;
 


struct libreria
{
	int numeroLibros;
	int* libros = new int[MAX];
	int signup;
	int booksPerDay;
	int factor;
};

struct general
{
	int numLibros;
	int numLibrerias;
	int dias;
	int* scores = new int[MAX];
	bool* taken = new bool[MAX];
	libreria* libs = new libreria[MAX];
};


void swap(libreria* a, libreria* b)  
{  
    libreria t = *a;  
    *a = *b;  
    *b = t;  
}  

int partition (libreria arr[], int low, int high)  
{  
    libreria pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j].factor < pivot.factor)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}

void quickSort(libreria arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}

void printArray(libreria arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i].factor << " ";  
    cout << endl;  
}  



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

		if (i != datos.numLibros)
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
		datos.libs[i].factor = datos.libs[i].booksPerDay - datos.libs[i].signup;
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
	printArray(datos.libs, datos.numLibrerias);
	// Sort libraries
	quickSort(datos.libs, 0, datos.numLibrerias - 1);
	printArray(datos.libs, datos.numLibrerias);
	
	// Output
	int today = 0;
	int* selectedBooks = new int[MAX];
	
	cout << datos.numLibrerias << endl;
	i = 0;
	int booksShipped;
	while (i < datos.numLibrerias)
	{
		cout << i << " " << datos.libs[i].numeroLibros << endl;
		int j = 0;
		booksShipped = 0;
		today += datos.libs[i].signup;
		int maxBooks = (datos.dias - today) * datos.libs[i].booksPerDay;
		while (j < datos.libs[i].numeroLibros && booksShipped < maxBooks)
		{
			if(!datos.taken[datos.libs[i].libros[j]]){
				// if book is not taken
				selectedBooks[booksShipped] = datos.libs[i].libros[j];
				booksShipped++;
			}
			cout << datos.libs[i].libros[j] << flush;
			j++;
			if (j != datos.libs[i].numeroLibros)
			{
				cout << " " << flush;
			}
			else
			{
				cout << endl;
			}
		}
		i++;
	}

	return 0;
}
