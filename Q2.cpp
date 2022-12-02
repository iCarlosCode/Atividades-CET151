#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

char * obter_string();
using namespace std;

int main()
{
    // Cria as variáveis e ponteiros
    char *nome;
    char *sobrenome;
    int tamanho_nome = 0;

    // Obtém o nome
    cout << "Digite seu primeiro nome:";
    nome = obter_string();
    
    // Obtém o sobrenome
    cout << "Digite seu sobrenome:";
    sobrenome = obter_string();

    // Aloca memória suficiente pra caber o nome completo no nome
    tamanho_nome = strlen(nome) + strlen(sobrenome);
    nome = (char *) realloc(nome, tamanho_nome * sizeof(char));
    if (nome == NULL)
      exit(1);
    strcat(nome, sobrenome);

    // Mostra na tela o resultado
    cout << nome << endl;
    // Mostra o tamanho
    cout << "O nome tem " << tamanho << "caracteres." << endl;

    // Libera a memória
    free(nome);
    free(sobrenome);

    return 0;
}

char * obter_string() 
{
    // Cria os ponteiros
    char * string1;
    char * string_temp = (char *) malloc(256 * sizeof(char));
    int tamanho = 0;

    // Obtém o que foi digitado pelo usuário e coloca na memória
    if (string_temp == NULL)
        exit(1);    
    fgets(string_temp, 256 * sizeof(char), stdin);
    tamanho = strlen(string_temp);

    // Remove o \n
    *(string_temp + tamanho -1)    = '\0';
    
    // Coloca o valor no ponteiro da string que será usada e aloca dinamicamente a memória necessária
    string1 = (char *) malloc(tamanho * sizeof(char));
    if (string1 == NULL)
        exit(1);
    strcpy(string1, string_temp);

    // Libera a memória do ponteiro temporário
    free(string_temp);
    return string1;
}
