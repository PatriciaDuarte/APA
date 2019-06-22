/*Nome:Patrícia Duarte da Silva*/
#include<stdio.h>
#include<stdlib.h>


void merge(int vetor[], int comeco, int meio, int fim) 
{
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim)
	{
        if(vetor[com1] < vetor[com2]) 
		{
            vetAux[comAux] = vetor[com1];
            com1++;
        } else 
		{
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio)
	{  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) 
	{   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++)
	{    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim)
{
    if (comeco < fim) 
	{
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

int main()
{
	int A[10] = {0,3,2,1,6,8,5,4,7,9};
 	int i;
  
    printf("\nVetor desordenado:\n ");
	for (i=0;i<10;i++)
    	printf ("A[%d] = %d \n",i, A[i]);
  		mergeSort(A,0,9);
  		
  	printf("\nVetor ordenado:\n ");	
	for (i=0;i<10;i++) 
   		printf ("A[%d] = %d \n ",i, A[i]);
 			
  return 0;
}   

/* End. */
