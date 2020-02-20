#include <iostream>
#include <string>
#include <string.h>

using namespace std;

const int MAX = 1000000;
const int MAX2 = 1000000;

struct libreria
{
	int id;
	int numeroLibros;
	int* libros = new int[MAX2];
	int signup;
	int booksPerDay;
	int factor;
};

struct general
{
	int numLibros;
	int numLibrerias;
	int dias;
	int* scores = new int[MAX2];
	bool* taken = new bool[MAX2];
	libreria* libs = new libreria[MAX2];
	int* selectedBooks = new int[MAX2];
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

int main()
{
	general datos;
	int totalBooks = 0;

	// Put everything to zero so as to avoid errors
	for(int i = 0; i < MAX; i++)
	{
		datos.taken[i] = false;
	}
	
	// Se lee la primera linea
	char line[MAX];
	cin.getline(line,MAX);
	// El delimitador es un espacio en blanco
	char delim[] = " ";
	int i = 0;

	datos.numLibros = atoi(strtok(line, delim));
	datos.numLibrerias = atoi(strtok(NULL, delim));
	datos.dias = atoi(strtok(NULL, delim));

	cin.getline(line,MAX);
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
		cin.getline(line,MAX);
		datos.libs[i].id = i;
		datos.libs[i].numeroLibros = atoi(strtok(line, delim));
		datos.libs[i].signup = atoi(strtok(NULL, delim));
		datos.libs[i].booksPerDay = atoi(strtok(NULL, delim));
		datos.libs[i].factor = - (datos.libs[i].booksPerDay - datos.libs[i].signup);

		int j = 0;
		cin.getline(line,MAX);
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
	// Sort libraries
	quickSort(datos.libs, 0, datos.numLibrerias - 1);
	

	int actualLibs = 0;
	// Output
	int today = 0;
	
	i = 0;
	int booksShipped;
	while (i < datos.numLibrerias)
	{
		int j = 0;
		booksShipped = 0;
		today += datos.libs[i].signup;
		int maxBooks = (datos.dias - today) * datos.libs[i].booksPerDay;
		while (j < datos.libs[i].numeroLibros && booksShipped < maxBooks)
		{
			if(!datos.taken[datos.libs[i].libros[j]]){
				// if book is not taken
				datos.selectedBooks[booksShipped] = datos.libs[i].libros[j];

				booksShipped++;
				totalBooks++;
				datos.taken[datos.libs[i].libros[j]] = true;
				/*
				cout << datos.libs[i].libros[j] << flush;
				if (j < datos.libs[i].numeroLibros - 1 && booksShipped < maxBooks)
				{
					cout << " " << flush;
				}
				*/
			}
			j++;

		}
		if(booksShipped > 0){
			actualLibs++;
		}
		i++;
	}

	// Output
	today = 0;
	
	for(int i = 0; i < MAX; i++)
	{
		datos.taken[i] = false;
	}
	cout << actualLibs << endl;
	i = 0;
	while (i < datos.numLibrerias)
	{
		int j = 0;
		booksShipped = 0;
		today += datos.libs[i].signup;
		int maxBooks = (datos.dias - today) * datos.libs[i].booksPerDay;
		while (j < datos.libs[i].numeroLibros && booksShipped < maxBooks)
		{
			if(!datos.taken[datos.libs[i].libros[j]]){
				// if book is not taken
				datos.selectedBooks[booksShipped] = datos.libs[i].libros[j];

				booksShipped++;
				datos.taken[datos.libs[i].libros[j]] = true;
				/*
				cout << datos.libs[i].libros[j] << flush;
				if (j < datos.libs[i].numeroLibros - 1 && booksShipped < maxBooks)
				{
					cout << " " << flush;
				}
				*/
			}
			j++;

		}
		if(booksShipped > 0){
			cout << datos.libs[i].id << " " << booksShipped << endl;
			for(int k = 0; k < booksShipped; k++){
				cout << datos.selectedBooks[k] << flush;
				if(k < booksShipped - 1){
					cout << " " << flush;
				}
				else{
					cout << endl;
				}
			}
		}
		i++;
	}
	cout << totalBooks << endl;

	return 0;
}
