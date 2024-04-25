#include <stdio.h>          //Bliblioteca de comunicação com o usuário
#include <stdlib.h>         //Bliblioteca de alocação de espaço de memória
#include <locale.h>         //Bliblioteca de alocações de texto por região
#include <string.h>         //Biblioteca responsavel por cuidar da string

int registro()                                       //Função responsavel por cadastrar os usuários no sistema      
{
    char arquivo[40];                                //Inicio da criação das variáveis/string
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];                                  //Final da criação das variáveis/string

    printf("Digite o CPF a ser cadastrado: ");       //Coletando informações do usuário
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
        printf("Não foi possivel abrir o arquivo, não localizado!\n");
    }

    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }
    system("pause");
}

int deletar()
{
    char cpf[40];
    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);
    remove(cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if (file == NULL)
    {
        printf("O usuário não se encontra no sistema!.\n");
        system("pause");
    }
}                                                           //Final da seleção

int main()
{
    int opcao=0;                                            //Definindo variaveis
    int laco=1;

    char senhadigitada[]="a";
    int comparacao;

    printf("### Cartório da EBAC ###\n\n");
    printf("Login de admistrador\n\nDigite a sua senha: ");
    scanf("%s", senhadigitada);

    comparacao = strcmp (senhadigitada,"admin");

    if (comparacao == 0)
    {
        system ("cls");
        for (laco=1;laco=1;)                                    //Inicio do Laço
        {
            system("cls");
            setlocale(LC_ALL, "Portuguese_Brazil");             //Definindo a linguagem 

            printf("### Cartório da EBAC ###\n\n");             //Inicio do menu
            printf("ESCOLHA A opção DESEJADA DO MENU:\n\n");
            printf("\t1 - Registrar nomes\n");
            printf("\t2 - Consultar nomes\n");
            printf("\t3 - Deletar nomes\n");                  //Fim do menu
            printf("\t4 - Sair do sistema\n\n");
            printf("opção: ");

            scanf("%d", &opcao);                                //Armazena a escolha do usuário
            system("cls");                                      //Responsavel por limpar a tela

            switch(opcao)                                     
            {
                case 1:
                    registro();                                  //Chama as funçoes
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

                default :
                    printf("Essa opção não esta disponivel!\n");
                    system("pause");
                    break;
            }                                                     
        }                                                         //Fim do laço
    }
    else
        printf("Senha incorreta!");
}