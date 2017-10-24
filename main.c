#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Fabricante
{
	char nome[50];
	char nacionalidade[50];
	int ano;
}Fabricante;

//======================================ASSINATURAS DAS FUNCOES===================================================
int Comparacao (Fabricante vet1, Fabricante vet2);
void shake_Sort(Fabricante *vetor, int n);
void escrVetor(Fabricante *Fabricante, int n);

//======================================FUNCAO PRINCIPAL=========================================================
int main()
{
	Fabricante  vetor[6];

	strcpy(vetor[0].nome, "Fiat");
	strcpy(vetor[0].nacionalidade, "Brasil");
	vetor[0].ano = 2000;

	strcpy(vetor[1].nome, "Fiat");
	strcpy(vetor[1].nacionalidade, "Brasil");
	vetor[1].ano = 1999;

	strcpy(vetor[2].nome, "Fox");
	strcpy(vetor[2].nacionalidade, "Colombia");
	vetor[2].ano = 1998;

	strcpy(vetor[3].nome, "Toyota");
	strcpy(vetor[3].nacionalidade, "Japao");
	vetor[3].ano = 1997;

	strcpy(vetor[4].nome, "Wolskwagen");
	strcpy(vetor[4].nacionalidade, "Coreia");
	vetor[4].ano = 1996;

	strcpy(vetor[5].nome, "Mazda");
	strcpy(vetor[5].nacionalidade, "Paraguai");
	vetor[5].ano = 1995;
	
	shake_Sort (vetor, 6);
	escrVetor (vetor, 6);
	return 0;
}

int Comparacao (Fabricante vet1, Fabricante vet2)
{
	if (strcmp(vet1.nome, vet2.nome) == 0)
	{
		if (strcmp(vet1.nacionalidade, vet2.nacionalidade) == 0)
		{
			if (vet1.ano == vet2.ano)
			{
				return(0);
			}
			else if(vet1.ano > vet2.ano)
			{
				return(1);
			}
			else
			{
				return(-1);
			}
		}
		else if(strcmp(vet1.nacionalidade, vet2.nacionalidade) == 1)
		{
			return(1);
		}
		else
		{
			return(-1);
		}
	}
	else if(strcmp(vet1.nome, vet2.nome) == 1)
	{
		return(1);
	}
	else
	{
		return(-1);
	}
}

void shake_Sort(Fabricante *vetor, int n)
{
	int bottom, top, swapped, i;
	Fabricante auxiliar;
	bottom = 0;
	top = n - 1;
	swapped = 0;
	while(swapped == 0 && bottom < top)
	{
		swapped = 1;
		for(i = bottom; i < top; i++)
		{
			if(Comparacao(vetor[i], vetor[i + 1]) == 1)
			{
				auxiliar = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = auxiliar;
				swapped = 0;
			}
		}
		top--;
		for(i = top; i > bottom; i--)
		{
			if(Comparacao(vetor[i], vetor[i - 1]) == -1)
			{
				auxiliar = vetor[i];
				vetor[i] = vetor[i - 1];
				vetor[i - 1] = auxiliar;
				swapped = 0;
			}
		}
		bottom++;
	}
}

void escrVetor(Fabricante *Fabricante, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\n %s\n %s\n %d \n\n", Fabricante[i].nome, Fabricante[i].nacionalidade, Fabricante[i].ano);
	}
}

