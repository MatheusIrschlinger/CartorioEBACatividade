#include <stdio.h>          //Bliblioteca de comunica��o com o usu�rio
#include <stdlib.h>         //Bliblioteca de aloca��o de espa�o de mem�ria
#include <locale.h>         //Bliblioteca de aloca��es de texto por regi�o
#include <string.h>         //Biblioteca responsavel por cuidar da string

int registro()                                       //Fun��o responsavel por cadastrar os usu�rios no sistema      
{
    char arquivo[40];                                //Inicio da cria��o das vari�veis/string
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];                                  //Final da cria��o das vari�veis/string

    printf("Digite o CPF a ser cadastrado: ");       //Coletando informa��o do usu�rio
    scanf("%s",cpf);                                 //%s refere-se as string

    strcpy(arquivo, cpf);           //responsavel por copiar os valores das string

    FILE *file;                     //Cria o arquivo
    file = fopen(arquivo,"w");      //Cria o arquivo / "W" significa escrever
    fprintf (file, cpf);            //Salva o valor
    fclose (file);                  //Fecha o arquivo

    file = fopen(arquivo, "a");     //o "A" singnifica atualizar um arquivo ja existente
    fprintf (file,",");
    fclose (file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf (file, nome);
    fclose (file);

    file = fopen(arquivo, "a");
    fprintf (file,",");
    fclose (file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf (file, sobrenome);
    fclose (file);

    file = fopen(arquivo, "a");
    fprintf (file,",");
    fclose (file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf (file, cargo);
    fclose (file);

    file = fopen(arquivo, "a");
    fprintf (file,",");
    fclose (file);

    system("pause");
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");                         //O "R" significa ler

    if (file == NULL)
    {
        printf("N�o foi possivel abrir o arquivo, n�o localizado!\n");
    }

    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas s�o as informa�oes do usu�rio: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    system("pause");
}


int deletar()
{
   char cpf[40];

   printf("Digite o CPF do usu�rio a ser deletado: ");
   scanf("%s", cpf);

   remove(cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("O usu�rio n�o se encontra no sistema!.\n");
        system("pause");
    }
}                                                           //Final da sele��o

int main()
{
    int opcao=0;                                            //Definindo variaveis
    int laco=1;

    for (laco=1;laco=1;)                                    //Inicio do La�o
    {
        system("cls");

        setlocale(LC_ALL, "Portuguese_Brazil");             //Definindo a linguagem 

        printf("### Cart�rio da EBAC ###\n\n");             //Inicio do menu
        printf("ESCOLHA A OP��O DESEJADA DO MENU:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");                  //Fim do menu
        printf("\t4 - Sair do sistema\n\n");
        printf("Op��o: ");

        scanf("%d", &opcao);                                //Armazena a escolha do usu�rio

        system("cls");                                      //Responsavel por limpar a tela

        switch(opcao)                                     
        {
            case 1:
                registro();                                  //Chama as fun��es
                break;

            case 2:
                consulta();
                break;

            case 3:
                deletar();
                break;

            case 4:
                printf("Obrigado por utilizar o nosso sistema!");
                return 0;
                break;

            default:
                printf("Essa op��o n�o esta disponivel!\n");
                system("pause");
                break;
        }                                                     

    }                                                         //Fim do la�o
}