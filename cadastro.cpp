#include <stdio.h>  // fun��es fundamentais de programas C que lidam com entrada e sa�da de dados
#include <locale.h> // fun��o para definir a configura��o de localiza��o em um programa
#include <string.h> // Fun��es relacionadas a strings (str...)
#include <stdlib.h> // Fun��o system

struct cadastro {
    char email[40];
    char senha[9];
    char excluirEmail[40];
};

struct cadastro addEmail; // Vari�vel para adicionar email
struct cadastro removerEmail; // Vari�vel para remover email

// melhoria:
	// estudar fun�ao strchr para obrigatoriedade do usuario colocar "@email.com"
	// Adicionar fun��o que de a op��o para o usuario Sair no Meio do Cadastro
	// criar struct principal dentro do main. Estudar sobre os parametros da fun��o
	// escrever nomes de variaveis menores, mais simples e intuitivas


// Fun��o para incluir um email no arquivo
int incluirEmail() {
    FILE *addEmail2;
    addEmail2 = fopen("arquivo-de-cadastro.txt", "a"); // Abre o arquivo para escrita no final

    // Verifica se o arquivo foi aberto com sucesso
    if (addEmail2 == NULL) {
        printf("Erro ao abrir arquivos");
        return 0;
    }

    // Solicita o email e a senha do usu�rio
    printf("Digite o email:\n");
    scanf("%s", addEmail.email);
    printf("Digite a senha (m�ximo de 8 caracteres):\n");
    scanf("%s", addEmail.senha);

    // Verifica se a senha tem exatamente 8 caracteres
    if (strlen(addEmail.senha) != 8) {
        printf("----------------------------------------------------\n");
        printf("Senha inv�lida. Deve conter exatamente 8 caracteres.\n");
        printf("----------------------------------------------------\n");
        system("pause");
        system("cls");
        return 0;
    }

    // Escreve o email e a senha no arquivo
    fprintf(addEmail2, "Email:%s\n", addEmail.email);
    fprintf(addEmail2, "Senha:%s\n", addEmail.senha);
    printf("--------------------------------\n");
    printf("Email cadastrado com sucesso\n");
    printf("--------------------------------\n");

    fclose(addEmail2);
    system("pause");
    system("cls");
    return 0;
}

// Fun��o para excluir um email do arquivo
int excluirEmail() {
    FILE *excluirEmail2;
    FILE *arquivoTemporario;
    excluirEmail2 = fopen("arquivo-de-cadastro.txt", "r"); // Abre o arquivo para leitura
    arquivoTemporario = fopen("arquivo-temporario.txt", "w"); // Abre o arquivo tempor�rio para escrita

    // Verifica se os arquivos foram abertos com sucesso
    if (excluirEmail2 == NULL) {
        printf("Erro ao abrir arquivos");
        return 0;
    }

    printf("Digite o email que deseja excluir:\n");
    scanf("%s", removerEmail.excluirEmail);
    printf("\n");

    int emailEncontrado = 0;

    while (fscanf(excluirEmail2, "Email:%s\nSenha:%s\n", removerEmail.email, removerEmail.senha) == 2) {
        if (strcmp(removerEmail.email, removerEmail.excluirEmail) != 0) {
            fprintf(arquivoTemporario, "Email:%s\nSenha:%s\n", removerEmail.email, removerEmail.senha);
        } else {
            emailEncontrado = 1;
        }
    }

    // Fecha os arquivos
    fclose(excluirEmail2);
    fclose(arquivoTemporario);

    // Remove o arquivo original
    remove("arquivo-de-cadastro.txt");

    // Renomeia o arquivo tempor�rio de volta para o nome original
    rename("arquivo-temporario.txt", "arquivo-de-cadastro.txt");

    if (emailEncontrado == 1) {
        printf("Email deletado com sucesso\n");
    } else {
        remove("arquivo-temporario.txt");
        printf("\nEmail n�o encontrado");
    }

    system("pause");
    printf("\n");
    system("cls");
    return 0;
}

// Fun��o para exibir um relat�rio dos emails
int relatorio() {
    FILE *relatorioEmail;
    relatorioEmail = fopen("arquivo-de-cadastro.txt", "r"); // Abre o arquivo para leitura

    // Verifica se o arquivo foi aberto com sucesso
    if (relatorioEmail == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 0;
    }

    printf("RELATORIO DE EMAIL:\n");
    printf("-------------------\n");

    // L� e imprime os emails do arquivo
    while (fscanf(relatorioEmail, "Email:%s\nSenha:%s\n", addEmail.email, addEmail.senha) == 2) {
        printf("Email: %s\n", addEmail.email);
        printf("Senha: %s\n\n", addEmail.senha);
    }

    fclose(relatorioEmail);
    system("pause");
    printf("\n");
    system("cls");
    return 0;
}

// Fun��o principal
int main() {
    setlocale(LC_ALL, "portuguese");
    int resposta;

    do {
        printf("Digite o n�mero correspondente � op��o desejada:\n");
        printf("1- Adicionar email\n");
        printf("2- Remover email\n");
        printf("3- Relat�rio\n");
        printf("4- Sair\n");
        scanf("%d", &resposta);

        system("cls");

        switch (resposta) {
            case 1:
                incluirEmail();
                break;

            case 2:
                excluirEmail();
                break;

            case 3:
                relatorio();
                break;

            case 4:
                printf("--------------------------------\n");
                printf("Programa finalizado");
                return 0;
                break;
        }
    } while (resposta != 4);

    return 0;
}

