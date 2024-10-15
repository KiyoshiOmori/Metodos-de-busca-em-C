#include<stdio.h>
#include<ctype.h>
#include<conio2.h>
#define TF 10
 /*
   metodos de busca
   Para arranjos desordenados: 
  -Busca exaustiva - linha 14
  -Busca exaustiva com sentinela - Linha 24
  Para arranjos ordenados:
  -Busca sequencial indexada
  -Busca binaria
 */

int BuscaExaustiva(int vet[TF], int TL, int chave)
{
	int pos=0;
	while(pos < TL && chave != vet[pos])
		pos++;
	if(pos < TL) //Achou
		return pos;
	return -1;
}

int BuscaComSentinela(int vet[TF+1], int TL, int chave)
{
	int pos = 0;
	vet[TL] = chave; //inserir sentinela
	while(chave != vet[pos])
		pos++;
	if(pos < TL)
		return pos;
	return -1;
}

int BuscaSequencialIndexada(int vet[TF],int TL, int chave) //Vetor ordenado
{
	int pos = 0;
	while(pos < TL && chave > vet[pos])
		pos++;
	if(pos < TL && chave == vet[pos])
		return pos;
	return -1;
}

int BuscaBinaria(int vet[TF], int TL, int chave)
{
	int inicio = 0, fim = TL - 1, meio = fim/2;
	while(inicio < fim && chave != vet[meio])
	{
		if(chave > vet[meio])
			inicio = meio + 1;
		else
			fim = meio -1;
		meio = (inicio + fim)/2;
	}
	if(chave == vet[meio])//achou
		return meio;
	return -1;
}
