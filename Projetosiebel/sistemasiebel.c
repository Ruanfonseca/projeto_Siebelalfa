#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define tam 50

typedef struct 
{
	long int codigo;
 	char nome[50];
 	int qtdestoque;
 	int qtdmin;
 	float preco; 
}FRUTA;
typedef struct 
{
	long int codigo;
 	char nome[50];
 	int qtdestoque;
 	int qtdmin;
 	float preco; 
	
}CARNE;
typedef struct 
{
	long int codigo;
 	char nome[50];
 	int qtdestoque;
 	int qtdmin;
 	float preco; 
	
}FRIOS;
typedef struct 
{
	long int codigo;
 	char nome[50];
 	int qtdestoque;
 	int qtdmin;
 	float preco; 
}MERCEARIA;
typedef struct 
{
	long int codigo;
 	char nome[50];
 	int qtdestoque;
 	int qtdmin;
 	float preco; 
}PADARIA;


 	int frutasfunc(void){
 		  FILE *banco;
		  FRUTA frutas[100];
		  int op,quantidade = 0,saida;
		  int i;
   puts("                 SECAO DE FRUTAS                      ");
   puts("+----------------------------------------------------+");
   puts("  Digite [1] para inserir ou [2] para consultar dados ");
     scanf("%i",&op);
	 if(op ==1){
       puts("Quantos tipos de frutas sao?");
	 	scanf("%i",&quantidade);//aqui eu armazeno o numero de tipos de frutas que usuário quer
	    for(i = 0;i <= quantidade ; i++){
        printf("Digite o nome da fruta [%i] : ",i);
	     scanf("%s",&frutas[i].nome);
	      banco = fopen("arquivo.txt","w");
        if (banco == NULL){
         printf("ERRO! O arquivo não foi aberto!\n");
		   }
		  fprintf(banco,"%s",frutas[i].nome); 
	        fclose(banco);
	        getch();
              printf("Codigo do produto[%i] : ",i);
	             scanf("%i",&frutas[i].codigo);
		      puts("\n");
	       }	
	       puts("Escolha [0] para sair ou [1] para voltar ao menu principal");
	           scanf("%i",&saida);
	        if(saida == 1){
		         funcao_layout();//chamo essa função para o usuário voltar para o menu
	          }
            else{
              system("cls");
                puts("Ate logo Bye");
			}
    }
	      
     else if(op == 2){
        consulta_banco(frutas[i].nome);
		} 
    }
    
 	int carnesfunc(void){
 		  FILE *banco;
		  CARNE carne[100];
		  int op1,quantidade1 = 0,saida1;
		  int k;
   puts("                 SECAO DE CARNES                      ");
   puts("+----------------------------------------------------+");
   puts("  Digite [1] para inserir ou [2] para consultar dados ");
     scanf("%i",&op1);
	 if(op1 ==1){
       puts("Quantos tipos de frutas sao?");
	 	scanf("%i",&quantidade1);//aqui eu armazeno o numero de tipos de frutas que usuário quer
	    for(k = 0;k <= quantidade1 ; k++){
        printf("Digite o nome da fruta [%i] : ",k);
	     scanf("%s",&carne[k].nome);
	      banco = fopen("arquivo.txt","w");
        if (banco == NULL){
         printf("ERRO! O arquivo não foi aberto!\n");
		   }
		  fprintf(banco,"%s",carne[k].nome); 
	        fclose(banco);
	        getch();
              printf("Codigo do produto[%d] : ",k);
	             scanf("%i",&carne[k].codigo);
		      puts("\n");
	       }	
	       puts("Escolha [0] para sair ou [1] para voltar ao menu principal");
	           scanf("%i",&saida1);
	        if(saida1 == 1){
		         funcao_layout();//chamo essa função para o usuário voltar para o menu
	          }
            else{
              system("cls");
                puts("Ate logo Bye");
			}
    }
	      
     else if(op1 == 2){
        consulta_banco(carne[k].nome);
		} 
    }
    
    
    
    
    
    
    
    
 int consulta_banco(char palavra[70]){
		FILE *banco;
		char frase [70];
		char opcao;
		int j,f;
		banco = fopen("arquivo.txt","r");
		while(fgets(frase,70,banco) != NULL){
			if(strcmp(palavra,frase)){
                printf("PRODUTO :%s ",frase);
               for (f = 1; f < 2; f++){
             /* gerando valores aleatórios entre zero e 50 */
                printf("Quantidade em estoque %d ", rand() % 50);
               }
              }
		      fclose(banco);
		      getch();
	          system("cls");//para limpar a tela do ms-dos
	         puts("Deseja continuar a utilização?[S]sim - [N]nao");
	         scanf("%c",&opcao);
             if(opcao == 's'){
              funcao_layout();   	
	         }
          else{
     	   puts("Ate logo Bye");
		   system("cls");
            getchar();
	       }
        }
 
   }
			 
int funcao_layout(void){
  int valor;
  puts("   Seja bem vindo ao Sistema de Cadastro Siebel  ");
  puts("+------------------------------------------------+");
  puts("Digite o numero correspondente ao Produto abaixo\n");
  puts("FRUTA [1] ");//já foi
   puts("CARNE[2] ");
   puts("FRIOS[3] ");
   puts("MERCEARIA[4] ");
   puts("PADARIA[5] ");
   puts("Para sair digite [0] ");
  scanf("%i",&valor);
 switch(valor){
	 case 1 :
	 frutasfunc();
	 	break;
	 case 2 :
	 carnesfunc();
	 	break;
	 case 0 :
	 	puts("BYE BYE");
	 	break;
	 default :
	 	break;
   }
 
  }

int main(void){
	
     funcao_layout();
}
 
