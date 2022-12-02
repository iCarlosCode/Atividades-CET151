#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

char * obter_string();
using namespace std;

int main()
{
    // Cria os ponteiros das 3 strings
    char *string1;
    char *string2;
    char *string3;
    
    // Obtém as strings
    cout << "Digite a primeira string:";
    string1 = obter_string();
    
    cout << "Digite a segunda string:";
    string2 = obter_string();
    
    cout << "Digite a terceira string:";
    string3 = obter_string();
    
    // Checa e imprime as strings em ordens alfabéticas
    if (strcmp(string1, string2) < 0)
    {
        if (strcmp(string2, string3) <= 0)
            cout << string1 << endl << string2 << endl << string3 << endl;
        else if (strcmp(string3, string1) <= 0)
            cout << string3 << endl << string1 << endl << string2 << endl;
        else if (strcmp(string2, string3) >= 0)
            cout << string1 << endl << string3 << endl << string2 << endl;
    }
    else
    {
        if (strcmp(string1, string3) <= 0)
            cout << string2 << endl << string1 << endl << string3 << endl;
        else if (strcmp(string3, string2) <= 0)
           cout << string3 << endl << string2 << endl << string1 << endl;
        else if (strcmp(string1, string3) >= 0)
           cout << string2 << endl << string3 << endl << string1 << endl;
    }
    
    // Libera a memória
    free(string1);
    free(string2);
    free(string3);    

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