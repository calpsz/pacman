#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int acabou(){
    return 0;
}

void move(char direcao) {

    // eh possivel matar funcao do tipo void com return
    if(direcao != 'a' && direcao != 'd' && direcao != 'w' && direcao != 's') return;

    // analisa se eh uma posicao valida
    int proximox = heroi.x;
    int proximoy = heroi.y;

    // direcao usando padrao wasd
    // pegando a info de onde o heroi vai anadar
    switch (direcao){
        case 'a':
            proximoy--;
            break;

        case 'd':
            proximoy++;
            break;

        case 'w':
            proximox--;
            break;
        
        case 's':
            proximox++;
            break;
    }

    if(proximox >= m.linhas) return;
    if(proximoy >= m.colunas) return;
    if(m.matriz[proximox][proximoy] != '.') return;

    m.matriz[proximox][proximoy] = '@';
    m.matriz[heroi.x][heroi.y] = '.';
    heroi.x = proximox;
    heroi.y = proximoy;
    
}

int main(){

    lemapa(&m);
    encontrachar(&m, &heroi, '@');

    do{
        imprimemapa(&m);

        char comando;
        scanf(" %c", &comando);

        move(comando);

    } while (!acabou());
    
    liberamapa(&m); 
}