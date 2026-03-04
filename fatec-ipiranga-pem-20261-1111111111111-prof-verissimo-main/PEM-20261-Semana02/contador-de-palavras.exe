#include <stdio.h>
#include <string.h>

int main () {
    int i, contador = 0;
    char frase[40];
    printf("Digite uma frase: ");
    fgets(frase, 40, stdin);
    for(i = 0; i < strlen(frase); i++){
        if(frase[i] !=' ' && (i == 0 || frase[i - 1] == ' ')){
                contador++;
        }
    }
    printf("A frase tem %d de palavras", contador);
    return 0;
}