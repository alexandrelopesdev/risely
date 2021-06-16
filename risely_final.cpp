#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
  
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}



int main(){
	system("color 3F");
	int opcao;
	printf("\n\n\n\n\n\n\n							Hi");
	delay(2);
	system("cls");
	
	printf("\n\n\n\n\t\t\t\tCovid-19 eh uma mensagem da natureza\n\t\t\t\tpara a humanidade, dizem pesquisadores");
	delay(5);
	system("cls");
	system("color 1F");
    do { // menu de opções
        
        printf("1) Inserir no inicio		2) Imprimir\n\n3) Inserir no fim		4) Remover\n\n6) Dividir lista		5) Sair\n");
        scanf("%d", &opcao);

        switch(opcao) {
        case 1:
        	
                
            break;
        case 2:
            
            break;
        case 3:
           
            break;
        case 4:
           
            break;
        case 5:
                 
        case 6:
          
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while(opcao != 5);

}
