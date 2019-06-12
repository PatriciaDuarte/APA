/*
	Universidade Federal de Goi�s
	Catal�o, 16 de mar�o de 2019
	Professora: Dr.� N�bia	
	Discente:Patr�cia Duarte da Silva - 201514322
	Disciplina: APA
	Curso:Bacharelado em Ci�ncias da computa��o
*/
#include <limits.h> 
#include <stdio.h> 
#include <conio.h>
#include <locale.h>

// Uma fun��o de utilidade para obter o m�ximo de dois inteiros 
int max(int a, int b)
{
	 return (a > b) ? a : b; 
} 
  
/* Retorna o melhor pre�o dispon�vel para uma barra de comprimento n e
��� pre�o [] como pre�os de diferentes pe�as */
int cutRod(int preco[], int n) 
{ 
    if (n <= 0) 
        return 0; 
        
    int max_val = INT_MIN; 
  // Cortar recursivamente a barra em diferentes partes e comparar diferentes configura��es
    for (int i = 0; i < n; i++) 
        max_val = max(max_val, preco[i] + cutRod(preco, n - i - 1)); 
  
    return max_val; 
} 
  

int main() 
{
	setlocale(LC_ALL,"Portuguese");
    int vetor[] = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 25 }; 
    int tamanho = sizeof(vetor) / sizeof(vetor[0]); 
    printf("O valor m�ximo obtido � %d", cutRod(vetor, tamanho)); 
    
    return 0; 
} 
