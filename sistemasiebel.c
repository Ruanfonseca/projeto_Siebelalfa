#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#define tam 50
#define tam1 1

typedef struct
{
	long int codigo;
	char nome[50];
	int qtdestoque;
	int qtdmin;
	float preco;
} FRUTA;
typedef struct
{
	long int codigo;
	char nome[50];
	int qtdestoque;
	int qtdmin;
	float preco;

} CARNE;
typedef struct
{
	long int codigo;
	char nome[50];
	int qtdestoque;
	int qtdmin;
	float preco;

} FRIOS;
typedef struct
{
	long int codigo;
	char nome[50];
	int qtdestoque;
	int qtdmin;
	float preco;
} MERCEARIA;
typedef struct
{
	long int codigo;
	char nome[50];
	int qtdestoque;
	int qtdmin;
	float preco;
} PADARIA;

int comparador(const char *s, const char *t)
{
	int ls = strlen(s), lt = strlen(t);
	int d[ls + 1][lt + 1], i, j;
	for (i = 0; i <= ls; i++)
		for (j = 0; j <= lt; j++)
			d[i][j] = -1;

	int dist(int i, int j)
	{
		if (d[i][j] >= 0) return d[i][j];

		int x;
		if (i == ls)
			x = lt - j;
		else if (j == lt)
			x = ls - i;
		else if (s[i] == t[j])
			x = dist(i + 1, j + 1);
		else
		{
			x = dist(i + 1, j + 1);

			int y;
			if ((y = dist(i, j + 1)) < x) x = y;
			if ((y = dist(i + 1, j)) < x) x = y;
			x++;
		}
		return d[i][j] = x;
	}
	return dist(0, 0);
}


int frutasfunc(void)
{
	FILE *bancodedados;
	FRUTA frutas[100];
	int op, quantidade = 0, saida;
	int i;
	puts("                 SECAO DE FRUTAS                      ");
	puts("+----------------------------------------------------+");
	puts("  Digite [1] para inserir ou [2] para consultar dados ");
	scanf("%i", &op);
	if(op == 1)
	{
		puts("Quantos tipos de frutas sao?");
		scanf("%i", &quantidade); //aqui eu armazeno o numero de tipos de frutas que usuário quer
		for(i = tam1; i <= quantidade ; i++)
		{
			printf("Digite o nome da fruta [%i] : ", i);
			scanf("%s", &frutas[i].nome);
			bancodedados = fopen("arquivo_banco.txt", "a");
			if (bancodedados == NULL)
			{
				printf("ERRO! O arquivo não foi aberto!\n");
			}
			if(fprintf(bancodedados, "\n%s", frutas[i].nome))
			{
				puts("Item inserido com sucesso");
			}
			fclose(bancodedados);
			fflush(stdin);
		}
		puts("Escolha [0] para sair ou [1] para voltar ao menu principal");
		scanf("%i", &saida);
		if(saida == 1)
		{
			funcao_layout();//chamo essa função para o usuário voltar para o menu
		}
		else
		{
			system("cls");
			puts("Ate logo Bye");
		}
	}

	else if(op == 2)
	{
		consultabanco();
	}
}

int carnesfunc(void)
{
	FILE *bancodedados;
	CARNE carne[100];
	int op1, quantidade1 = 0, saida1;
	int k;
	puts("                 SECAO DE CARNES                      ");
	puts("+----------------------------------------------------+");
	puts("  Digite [1] para inserir ou [2] para consultar dados ");
	scanf("%i", &op1);
	if(op1 == 1)
	{
		puts("Quantos tipos de Carnes Sao?");
		scanf("%i", &quantidade1); //aqui eu armazeno o numero de tipos de frutas que usuário quer
		for(k = tam1; k <= quantidade1 ; k++)
		{
			printf("Digite o nome da Carne [%i] : ", k);
			scanf("%s", &carne[k].nome);
			bancodedados = fopen("arquivo_banco.txt", "a");
			if (bancodedados == NULL)
			{
				printf("ERRO! O arquivo não foi aberto!\n");
			}
			if(fprintf(bancodedados, "\n%s", carne[k].nome))
			{
				puts("Item inserido com sucesso\n");
			}
		}
		fclose(bancodedados);
		fflush(stdin);
		puts("Escolha [0] para sair ou [1] para voltar ao menu principal");
		scanf("%i", &saida1);
		if(saida1 == 1)
		{
			funcao_layout();//chamo essa função para o usuário voltar para o menu
		}
		else
		{
			system("cls");
			puts("Ate logo Bye");
		}
	}

	else if(op1 == 2)
	{
		consultabanco();
	}
}

int friosfunc(void)
{
	FILE *bancodedados;
	FRIOS frios[100];
	int op2, quantidade2 = 0, saida2;
	int d;
	puts("                 SECAO DE FRIOS                      ");
	puts("+----------------------------------------------------+");
	puts("  Digite [1] para inserir ou [2] para consultar dados ");
	scanf("%i", &op2);
	if(op2 == 1)
	{
		puts("Quantos tipos de Derivados sao?");
		scanf("%i", &quantidade2); //aqui eu armazeno o numero de tipos de frutas que usuário quer
		for(d = tam1; d <= quantidade2 ; d++)
		{
			printf("Digite o nome do Derivado [%i] : ", d);
			scanf("%s", &frios[d].nome);
			bancodedados = fopen("arquivo_banco.txt", " a ");
			if (bancodedados == NULL)
			{
				printf("ERRO! O arquivo não foi aberto!\n");
			}
			if(fprintf(bancodedados, "\n%s", frios[d].nome))
			{
				puts("Item inserido com sucesso");
			}
			fclose(bancodedados);
			fflush(stdin);
		}
		puts("Escolha [0] para sair ou [1] para voltar ao menu principal");
		scanf("%i", &saida2);
		puts("\n");
		getch();
		if(saida2 == 1)
		{
			funcao_layout();//chamo essa função para o usuário voltar para o menu
		}
		else
		{
			system("cls");
			puts("Ate logo Bye");
		}
	}

	else if(op2 == 2)
	{
		consultabanco();
	}
}

int merceariafunc(void)
{
	FILE *bancodedados;
	MERCEARIA merc[100];
	int op3, quantidade3 = 0, saida3;
	int h;
	puts("                 SECAO DE MERCEARIA                      ");
	puts("+----------------------------------------------------+");
	puts("  Digite [1] para inserir ou [2] para consultar dados ");
	scanf("%i", &op3);
	if(op3 == 1)
	{
		puts("Quantos tipos de produtos sao?");
		scanf("%i", &quantidade3); //aqui eu armazeno o numero de tipos de frutas que usuário quer
		for(h = tam1; h <= quantidade3 ; h++)
		{
			printf("Digite o nome da Conserva [%i] : ", h);
			scanf("%s", &merc[h].nome);
			bancodedados = fopen("arquivo_banco.txt", " a ");
			if (bancodedados == NULL)
			{
				printf("ERRO! O arquivo não foi aberto!\n");
			}
			if(fprintf(bancodedados, "\n%s", merc[h].nome))
			{
				puts("Item inserido com sucesso");
			}

			fclose(bancodedados);
			fflush(stdin);
		}
		puts("Escolha [0] para sair ou [1] para voltar ao menu principal");
		scanf("%i", &saida3);
		puts("\n");
		if(saida3 == 1)
		{
			funcao_layout();//chamo essa função para o usuário voltar para o menu
		}
		else
		{
			system("cls");
			puts("Ate logo Bye");
		}
	}

	else if(op3 == 2)
	{
		consultabanco();
	}
}

int padariafunc(void)
{
	FILE *bancodedados;
	PADARIA padaria[100];
	int op4, quantidade4 = 0, saida4;
	int p, num[15];
	int frase [70];
	char opcao;
	int j, f;
	puts("                 SECAO DE PADARIA                      ");
	puts("+----------------------------------------------------+");
	puts("  Digite [1] para inserir ou [2] para consultar dados ");
	scanf("%i", &op4);
	if(op4 == 1)
	{
		puts("Quantos tipos de produtos sao?");
		scanf("%i", &quantidade4); //aqui eu armazeno o numero de tipos de frutas que usuário quer
		for(p = tam1; p <= quantidade4 ; p++)
		{
			printf("Digite o nome do Produto[%i] : ", p);
			scanf("%s", &padaria[p].nome);
			bancodedados = fopen("arquivo_banco.txt", " a ");
			if (bancodedados == NULL)
			{
				printf("ERRO! O arquivo não foi aberto!\n");
			}
			if(fprintf(bancodedados, "\n%s", padaria[p].nome))
			{
				puts("Item inserido com sucesso");
			}
			fclose(bancodedados);
		}
		fflush(stdin);
		//getch()
		puts("Escolha [0] para sair ou [1] para voltar ao menu principal");
		scanf("%i", &saida4);
		if(saida4 == 1)
		{
			funcao_layout();//chamo essa função para o usuário voltar para o menu
		}
		else
		{
			system("cls");
			puts("Ate logo Bye");
		}
	}
	if(op4 == 2)
	{
		consultabanco();
	}
	else
	{
		puts("Ate logo Bye");
		system("cls");
		getchar();
	}
}

int Geradordenum(int numero)
{
	int i;
	long int valor;
	/* inicializar o gerador de números aleatórios */
	/* com time(NULL) utilizei a biblioteca time.h para simular a quantidade de produtos no estoque  */
	srand((unsigned)time(NULL));
	for (i = 1; i < 2; i++)
	{
		/* para gerar números aleatórios de 0 a 50 */
		valor = rand() % 50;
	}
	return valor;
}

int consultabanco(void)
{
	FILE *bancodedados;
	bancodedados = fopen("arquivo_banco.txt", " r ");
	char nome[100];
	char frase[100];
	char aux[104], count;
	float preco;
	int y = 100, escolha, x = 0;
	int numestoque, qtdestoque;
	puts("Digite o nome do produto para realizar a consulta");
	scanf("%s", &nome);
	while(fgets(frase, 100, bancodedados) != NULL)
	{
		if(frase[strlen(frase) - 1] == '\n')
			frase[strlen(frase) - 1] = '\0';
		x = comparador(nome, frase);
		if(comparador(nome, frase) < y)
		{
			y = (comparador(nome, frase));
			strcpy(aux, frase);
		}
	}
	if(strcmp(nome, aux) == 0)
	{
		printf("Produto : %s\n", aux);
		fflush(stdin);
		printf("Sua quatidade em estoque : %li\n", Geradordenum(qtdestoque) / 3);
		fflush(stdin);
		printf("Seu Preco eh : R$%.2f a unidade\n", ((float)Geradordenum(preco) / 2)); //utilizando o cast para converter o inteiro para float
		//fflush(stdin);
	}
	//fflush(stdin);
	else
	{
		puts("Esse item nao existe no banco\n");
		//fflush(stdin);
	}
	puts("\n");
	fflush(stdin);
	puts("Deseja continuar a Consulta? [S] = sim ; [N] = nao");
	scanf("%c", &count);
	getchar();
	if(count == 's')
	{
		consultabanco();//usando a recursividade
	}
	else if(count == 'n')
	{
		puts("Deseja voltar ao menu principal? [1]SIM [2]NAO");
		scanf("%i", &escolha);
		if(escolha == 1)
		{
			funcao_layout();
		}
		else
		{
			puts("Obrigada Volte Sempre!!");
			system("cls");
			getchar();
		}
	}

	//printf("Codigo : %.2f ",codigo);
	fclose(bancodedados);
	fflush(stdin);
	printf("\n");

}

int apagaitem(void)
{
	FILE *bancodedados;
	bancodedados = fopen("arquivo_banco.txt", " r ");
	char nome[25], aux[25];
	char frase[100], escolha;
	int x, y;
	puts(" Digite o nome do produto abaixo ");
	scanf("%s", &nome);
	while(fgets(frase, 100, bancodedados) != NULL)
	{
		if(frase[strlen(frase) - 1] == '\n')
			frase[strlen(frase) - 1] = '\0';
		x = comparador(nome, frase);
		if(comparador(nome, frase) < y)
		{
			y = (comparador(nome, frase));
		}
	}
	fflush(stdin);
	fclose(bancodedados);
	if(strcmp(nome, frase))
	{
		bancodedados = fopen("arquivo_banco.txt", " a ");
		fprintf(bancodedados, "\n%s", NULL);
		fclose(bancodedados);
		puts("Item foi apagado com sucesso");
	}
	puts("Deseja retornar ao Menu Principal?[1] Sim ou [2] Nao");
	scanf("%i", &escolha);
	if(escolha == 1)
	{
		funcao_layout();
	}
	puts("BYE BYE");
	//fflush(stdin);
}

int configura(void)
{
	int resposta, resposta1;
	puts("  Deseja apagar algum Registro de produto do banco?      se Sim tecle [1]   ");
	puts("\n");
	printf("Ou");
	puts("\n");
	puts("   Deseja apagar o banco ?                                se sim tecle [2]   ");
	scanf("%i", &resposta);
	switch(resposta)
	{
	case 1 :
		apagaitem();
		break;
		system("cls");
	case 2 :
		getchar();
		puts("Banco de dados Apagado!!");
		remove("arquivo_banco.txt");
		break;
	}

}

int funcao_layout(void)
{
	int valor;
	char opcao;
	puts("   Seja bem vindo ao Sistema de Cadastro Siebel  ");
	puts(" +---------------------------------------------------+  ");
	puts("  Digite o numero correspondente ao Produto abaixo\n  ");
	puts("             FRUTA [1]                               ");//já foi
	puts("             CARNE[2]                                ");//ja foi
	puts("             FRIOS[3]                                ");//ja foi
	puts("             MERCEARIA[4]                            ");//ja foi
	puts("             PADARIA[5]                              ");//já foi
	puts("             CONFIGURACOES[6]                        ");
	puts("             Para sair digite [0]                    ");
	scanf("%i", &valor);
	puts("\n");
	switch(valor)
	{
	case 1 :
		frutasfunc();
		break;
		system("cls");
	case 2 :
		carnesfunc();
		break;
		system("cls");
	case 3 :
		friosfunc();
		break;
		system("cls");
	case 4 :
		merceariafunc();
		break;
		system("cls");
	case 5 :
		padariafunc();
		break;
		system("cls");
	case 6:
		configura();
		break;
		system("cls");
	case 0 :
		puts("BYE BYE");
		exit(0);
		
	default :
		puts("Voce digitou uma opcao errada");
		fflush(stdin);
		printf("Deseja tentar novamente? [s]sim ou qualquer tecla para nao\n");
		scanf("%c", &opcao);
		if(opcao == 's')
		{
			funcao_layout();
		}
		else
		{
			break;
		}
	}

}

int main(void)
{
	funcao_layout();
}

