#include <stdio.h>  // funções fundamentais de programas C que lidam com entrada e saída de dados
#include <locale.h> // função para definir a configuração de localização em um programa
#include <string.h> // Funções relacionadas a strings (str...)
#include <stdlib.h> // Função system

struct cadastro {
    char email[40];
    char senha[9];
    char excluirEmail[40];
};

struct cadastro addEmail; // Variável para adicionar email
struct cadastro removerEmail; // Variável para remover email

// melhoria:
	// estudar funçao strchr para obrigatoriedade do usuario colocar "@email.com"
	// Adicionar função que de a opção para o usuario Sair no Meio do Cadastro
	// criar struct principal dentro do main. Estudar sobre os parametros da função
	// escrever nomes de variaveis menores, mais simples e intuitivas


// Função para incluir um email no arquivo
int incluirEmail() {
    FILE *addEmail2;
    addEmail2 = fopen("arquivo-de-cadastro.txt", "a"); // Abre o arquivo para escrita no final

    // Verifica se o arquivo foi aberto com sucesso
    if (addEmail2 == NULL) {
        printf("Erro ao abrir arquivos");
        return 0;
    }

    // Solicita o email e a senha do usuário
    printf("Digite o email:\n");
    scanf("%s", addEmail.email);
    printf("Digite a senha (máximo de 8 caracteres):\n");
    scanf("%s", addEmail.senha);

    // Verifica se a senha tem exatamente 8 caracteres
    if (strlen(addEmail.senha) != 8) {
        printf("----------------------------------------------------\n");
        printf("Senha inválida. Deve conter exatamente 8 caracteres.\n");
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

// Função para excluir um email do arquivo
int excluirEmail() {
    FILE *excluirEmail2;
    FILE *arquivoTemporario;
    excluirEmail2 = fopen("arquivo-de-cadastro.txt", "r"); // Abre o arquivo para leitura
    arquivoTemporario = fopen("arquivo-temporario.txt", "w"); // Abre o arquivo temporário para escrita

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

    // Renomeia o arquivo temporário de volta para o nome original
    rename("arquivo-temporario.txt", "arquivo-de-cadastro.txt");

    if (emailEncontrado == 1) {
        printf("Email deletado com sucesso\n");
    } else {
        remove("arquivo-temporario.txt");
        printf("\nEmail não encontrado");
    }

    system("pause");
    printf("\n");
    system("cls");
    return 0;
}

// Função para exibir um relatório dos emails
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

    // Lê e imprime os emails do arquivo
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

// Função principal
int main() {
    setlocale(LC_ALL, "portuguese");
    int resposta;

    do {
        printf("Digite o número correspondente à opção desejada:\n");
        printf("1- Adicionar email\n");
        printf("2- Remover email\n");
        printf("3- Relatório\n");
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

