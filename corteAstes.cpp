/*
	Universidade Federal de Goiás
	Catalão, 16 de março de 2019
	Professora: Dr.ª Núbia	
	Discente:Patrícia Duarte da Silva - 201514322
	Disciplina: APA
	Curso:Bacharelado em Ciências da computação
*/
#include <limits.h> 
#include <stdio.h> 
#include <conio.h>
#include <locale.h>

// Uma função de utilidade para obter o máximo de dois inteiros 
int max(int a, int b)
{
	 return (a > b) ? a : b; 
} 
  
/* Retorna o melhor preço disponível para uma barra de comprimento n e
    preço [] como preços de diferentes peças */
int cutRod(int preco[], int n) 
{ 
    if (n <= 0) 
        return 0; 
        
    int max_val = INT_MIN; 
  // Cortar recursivamente a barra em diferentes partes e comparar diferentes configurações
    for (int i = 0; i < n; i++) 
        max_val = max(max_val, preco[i] + cutRod(preco, n - i - 1)); 
  
    return max_val; 
} 
  

int main() 
{
	setlocale(LC_ALL,"Portuguese");
    int vetor[] = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 25 }; 
    int tamanho = sizeof(vetor) / sizeof(vetor[0]); 
    printf("O valor máximo obtido é %d", cutRod(vetor, tamanho)); 
    
    return 0; 
} 
