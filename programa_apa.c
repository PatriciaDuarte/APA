#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define nMax 200 

int n; 
int Matriz[nMax][nMax]; 
int corVertice[nMax]; 



void zeraMatriz() 
{
    int i, j; 

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            Matriz[i][j] = 0; 
        }
    }
}

void atribuiAdjacencia()
{

    int l, a, b; 

        scanf("%d", &l); 

        while(l--) 
        {
            scanf("%d %d", &a, &b); 
            Matriz[a][b] = Matriz[b][a] = 1; 
        }
}

void imprimeMatriz() 
{
    int i,j; 

    printf("Matriz de adjacencia: \n\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", Matriz[i][j]); 
        }
        printf("\n");
    }
    printf("\n");
}

void semCor() 
{
	int i; 

	for(i = 0; i < n; i++)
    {
        corVertice[i] = 0; 
	}
}

int colorir(int i, int c) 
{
	int j; 
	corVertice[i] = c;

	for(j = 0; j < n; j++)
    {
		if(Matriz[i][j] == 1) 
		{
			if(corVertice[j] == 0) 
			{
				if (colorir(j, 3-c) == 0) 
				{
                    return 0;
				}
			}
			else
			{
			    if(corVertice[j] == c) 
			    {
                    return 0;
			    }
			}
		}
	}
	return 1;
}

int main()
{
	setlocale(LC_ALL,"Portuguese"); 

    freopen("entrada.txt", "r", stdin); 

    while(scanf("%d", &n) == 1) 
    {
        if (n == 0) 
        {
            break;
        }

        zeraMatriz(); 
        atribuiAdjacencia(); 
        imprimeMatriz();
        semCor(); 

        if(colorir(0,1) == 1) 
        {
            printf("O grafo é bicolor, ou seja, pode ser colorido com apenas 2 cores.\n\n");
        }
        else 
        {
            printf("O grafo não é bicolor, ou seja, não pode ser colorido com apenas 2 cores.\n\n");
        }

    }

    return 0;
}



