/*
 * main.c
 * 
 * Copyright 2021 Mateo Estrada Ramirez <mateo@EliteBook-8470p>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 * Warshall Algorithm
 * 
 */
 
#include <stdio.h>
#include <stdlib.h>

int computeSize();

int ** allocateMatrix(int size);
void freeMemory(int ** matrix, int size);

void computeMatrix(int **matrix, int size);

void printMatrix(int **matrix, int size);

int ** warshall(int **matrix, int size); 
void printW (int **matrix, int size, int k);

void printResult(int **matrix, int size);

int main(int argc, char **argv)
{
	int matrixSize= computeSize();
	
	int **matrix=allocateMatrix(matrixSize);
	int **w;
	
	computeMatrix(matrix, matrixSize);
	
	w=warshall(matrix, matrixSize);
	
	printResult(w, matrixSize);
	
	freeMemory(matrix, matrixSize);

	return 0;
}

int computeSize()
{
	int size;
	printf("Ingrese el número de nodos del grafo\n");
	scanf("%d", &size);
	fflush(stdin);
	return size;
}

int ** allocateMatrix(int size)
{
	int **matrix= (int **) malloc(size * sizeof(int*));
	
	for (int i=0; i < size; i++)
	{
			matrix[i]=(int*)malloc(size * sizeof(int));
	}
	
	return matrix;
}

void freeMemory(int ** matrix, int size)
{
	int * currentPointer;
	
	for(int i=0; i<size; i++)
	{
			currentPointer=matrix[i];
			free(currentPointer);
	}
	
	free(matrix);
}

void printMatrix(int **matrix, int size)
{
		for (int i=0; i<size; i++)
		{
			printf("\n[");
			
			for(int j=0; j<size; j++)
			{
					printf(" %d ",matrix[i][j]);
			}
			
			printf("]\n\n");
		}
}

void computeMatrix(int **matrix, int size)
{
		for(int i=0; i<size; i++)
		{
			for(int j=0; j<size; j++)
			{
				printf("Ingrese el valor de la matriz de adyacencias\n");
				printf("en la posición %d, %d \n", i, j);
				
				scanf("%d", &matrix[i][j]);
				
				printMatrix(matrix, size);
				
				fflush(stdin);
			}
			
		}
}

int ** warshall(int **matrix, int size)
{
	int ** w = matrix;
	
	for (int k =0 ; k<size; k++)
	{
		for(int i=0; i<size; i++)
		{
			for(int j=0; j<size; j++)
			{
				w[i][j] = w[i][j] || (w[i][k] && w[k][j]);
			}
		}
		printW(w, size, k);
	}
	
	return w;
}

void printW (int **matrix, int size, int k)
{
		printf("Para W(%d) la matriz es:\n\n\n",k+1);
		printMatrix(matrix, size);
}

void printResult(int **matrix, int size)
{
		printf("La matriz de adyacencias es:\n\n\n");
		printMatrix(matrix, size);
}
