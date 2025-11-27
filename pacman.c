#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"

char** mapa;
int linhas;
int colunas;

void liberamapa(){
    for (int i = 0; i < colunas; i++){
        free(mapa[i]);
    }
    free(mapa);
}

void lemapa(){
    FILE* f;
    f = fopen("mapa.txt", "r");

    if(f == 0){
        printf("Erro na leitura do mapa D:\n");
        exit(1);
    }

    fscanf(f, "%d %d", &linhas, &colunas);

    alocamapa();

    for(int i = 0; i < 5; i++){
        fscanf(f, "%s", mapa[i]);
    }

    fclose(f);
}

void alocamapa(){
    mapa = malloc(sizeof(char*) * linhas);
    for(int i = 0; i < colunas; i++){
        mapa[i] = malloc(sizeof(char) * (colunas +1));
    }
}

int main(){

    lemapa();

    for(int i = 0; i < 5; i++){
        printf("%s\n", mapa[i]);
    }

    liberamapa();
    
}