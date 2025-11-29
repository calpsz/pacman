#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

// m->matriz eh igual a (*m).matriz
// estamos acessando o struct MAPA m atraves de seu ponteiro

void encontrachar(MAPA* m, POSICAO* p, char c){
    for(int i = 0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; j++){
            if(m->matriz[i][j] == c){
                p->x = i;
                p->y = j;
                break;
            }
        }
    }
}

void liberamapa(MAPA* m){
    for (int i = 0; i < m->linhas; i++){
        free(m->matriz[i]);
    }
    free(m->matriz);
}

void lemapa(MAPA* m){
    FILE* f;
    f = fopen("mapa.txt", "r");

    if(f == 0){
        printf("Erro na leitura do mapa D:\n");
        exit(1);
    }

    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));

    alocamapa(m);

    for(int i = 0; i < 5; i++){
        fscanf(f, "%s", m->matriz[i]);
    }

    fclose(f);
}

void alocamapa(MAPA* m){
    m->matriz = malloc(sizeof(char*) * m->linhas);

    for(int i = 0; i < m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char) * (m->colunas +1));
    }
}

void imprimemapa(MAPA* m){
    for(int i = 0; i < 5; i++){
         printf("%s\n", m->matriz[i]);
    }
}

int ehvalida(MAPA* m, int x, int y){
    if(x >= m->linhas) return 0;
    if(y >= m->colunas) return 0;

    return 1;
}

int ehvazia(MAPA* m, int x, int y){
    //basicamente um boolean
    return m->matriz[x][y] == VAZIO;
}

void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino){
    char personagem = m->matriz[xorigem][yorigem];
    m->matriz[xdestino][ydestino] = personagem;
    m->matriz[xorigem][yorigem] = VAZIO;


}