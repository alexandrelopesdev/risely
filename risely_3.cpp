#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
	
    int valor;
    char pais[56];
    int casos;
    int recuperados;
    int obitos;
    int casos_ativos;
    struct No *proximo;
    
} No;

typedef struct {
    No *inicio, *fim;
    int tam;
} Lista;



// inserção no início da lista
void inserirInicio(Lista *lista, char pais[56], 
     int casos, int recuperados, int obitos, int casos_ativos) {
   
    No *novo = (No*)malloc(sizeof(No)); // cria um novo nó
   
		   
   strcpy(novo->pais , pais);// (*novo).valor = valor
    novo->casos = casos;
    novo->	recuperados = recuperados;
    novo->obitos = obitos;
    novo->casos_ativos = casos_ativos;
    

    if(lista->inicio == NULL) { // a lista está vazia
        novo->proximo = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    } else { // a lista não está vazia
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }
    lista->tam++;
}


// inserir no final da lista
void inserirFim(Lista *lista, char pais[56], 
     int casos, int recuperados, int obitos, int casos_ativos) {
     	
    No *novo = (No*)malloc(sizeof(No)); // cria um novo nó
   		   
   strcpy(novo->pais , pais);// (*novo).valor = valor
    novo->casos = casos;
    novo->	recuperados = recuperados;
    novo->obitos = obitos;
    novo->casos_ativos = casos_ativos;
    
    novo->proximo = NULL;

    if(lista->inicio == NULL) { // lista vazia
        lista->inicio = novo;
        lista->fim = novo;
    } else { // lista não vazia
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
    lista->tam++;
}


// imprimir a lista
void imprimir(Lista *lista) {
    No *inicio = lista->inicio;
    
    printf("Tamanho da lista: %d\n", lista->tam);
    
    while(inicio != NULL) {
    	
    	printf("______________________________________________________________________________________\n");
    	printf("Pais		|Casos		 |Recuperados		|Obitos		 |Casos ativos|\n");
    	printf("________________|________________|______________________|________________|____________|\n");
		printf("%s	",  inicio-> pais);
		printf("|%d\t	", inicio->casos);
		printf(" |%d\t\t	", inicio->recuperados);
		printf("|%d\t\t", inicio->obitos);
		printf(" |%d\t		", inicio->casos_ativos);
		printf("\n________________|________________|______________________|________________|____________|\n");
       
      
        inicio = inicio->proximo;
    }
    printf("\n\n");
}


// remover um elemento da lista
void remover(Lista *lista, int casos) {
    No *inicio = lista->inicio; // ponteiro para o início da lista
    No * noARemover = NULL; // ponteiro para o nó a ser removido

    if(inicio != NULL && lista->inicio->casos == casos) { // remover 1º elemento
        noARemover = lista->inicio;
        lista->inicio = noARemover->proximo;
        if(lista->inicio == NULL)
            lista->fim = NULL;
    } else { // remoção no meio ou no final
        while(inicio != NULL && inicio->proximo != NULL && inicio->proximo->casos != casos) {
            inicio = inicio->proximo;
        }
        if(inicio != NULL && inicio->proximo != NULL) {
            noARemover = inicio->proximo;
            inicio->proximo = noARemover->proximo;
            if(inicio->proximo == NULL) // se o último elemento for removido
                lista->fim = inicio;
        }
    }
    if(noARemover) {
        free(noARemover); // libera a memória do nó
        lista->tam--; // decrementa o tamanho da lista
    }
}

// função que remove e retorna o primeiro nó
No* removerPrimeiroNO(Lista *lista) {
    if(lista->inicio != NULL) {
        No *no = lista->inicio;
        lista->inicio = no->proximo;
        lista->tam--;
        if(lista->inicio == NULL)
            lista->fim = NULL;
        return no;
    } else
        return NULL;
}



int main(){
	
	Lista lista, listaI, listaP; // criação de 3 listas
    int opcao, valor;

    // inicialização das listas
    lista.inicio = NULL;
    lista.fim = NULL;
    lista.tam = 0;

    listaI.inicio = NULL;
    listaI.fim = NULL;
    listaI.tam = 0;

    listaP.inicio = NULL;
    listaP.fim = NULL;
    listaP.tam = 0;

 printf("Digite um valor a ser inserido: ");
            scanf("%d", &valor);
            inserirFim(&lista, "Alexandre", 12, 13, 12, 14);
            
          
	imprimir(&lista);
	
	 remover(&lista, 12);
	imprimir(&lista);
}
