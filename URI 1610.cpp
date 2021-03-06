#include <stdio.h>
#include <vector>

using namespace std;

#define MAXV 100000 //quantidade máxima de vértices

#define BRANCO 0
#define CINZA 1
#define PRETO 2
#define NULO -1

int falha;

vector<int> l[MAXV + 1]; //lista de adjacências
int N; //quantidade de vértices
int c[MAXV+1]; //cor
int d[MAXV+1]; //tempo de descoberta
int t[MAXV+1]; //tempo de término
int a[MAXV+1]; //antecessor na árvore de busca
int tempo; //tempo corrente durante execução do algoritmo

void DFS_VISIT(int u)
{
	c[u] = CINZA;
	tempo++;
	d[u] = tempo;

	int i,v;
	
	for(int v: l[u])
	{ //percorre cada elemento da lista l[u]
		
		if(c[v] == CINZA)
		{
			falha = 1;
		}
		if(c[v] == BRANCO)
		{
			a[v] = u;
			DFS_VISIT(v);
		}
		
	}

	c[u] = PRETO;
	tempo++;
	t[u] = tempo;
}

void DFS()
{
	int u;
	for(u = 1; u <= N; u++)
	{
		c[u] = BRANCO;
		d[u] = NULO;
		t[u] = NULO;
		a[u] = NULO;
	}

	tempo=0;

	for(u = 1; u <= N; u++)
	{
		if(c[u] == BRANCO)
			DFS_VISIT(u);
	}
}

void imprimir(int vet[])
{
	int i;
	for(i = 1; i <= N; i++)
	{
		printf("%d, ", vet[i]);
	}
	printf("\n");
}

void inicializar()
{
	int u;
	for(u = 0; u <= MAXV; u++)
	{
		l[u] = vector<int>(); //cria uma lista vazia para cada vértice u
	}
}

int main()
{

    int t;
    int a, b, n,m;
	int i, j;
	
	scanf("%d", &t);
	
	for(j = 0; j < t; j++)
    {
        inicializar();
       
        scanf("%d %d", &n, &m);
        
        falha = 0;
        N = n;    
        
        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            //l[u].pushback(v) torna v adjacente a u
	        l[b].push_back(a);
        }
        
	    DFS();
	    
	    if(falha)
	    {
	        printf("SIM\n");
	    }
	    else
	    {
	        printf("NAO\n");
	    }
    }

	return 0;
}
