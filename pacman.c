#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int acabou(){
    return 0;
}

int ehdirecaovalida(char direcao){
    return direcao == CIMA || direcao == BAIXO || direcao == DIREITA || direcao == ESQUERDA;
}

void move(char direcao) {

    // eh possivel matar funcao do tipo void com return
    // verifica se a direcao digitada eh valida
    if(!ehdirecaovalida(direcao)) 
        return;

    // analisa se eh uma posicao valida
    int proximox = heroi.x;
    int proximoy = heroi.y;

    // direcao usando padrao wasd
    // pegando a info de onde o heroi vai anadar
    switch (direcao){
        case ESQUERDA:
            proximoy--;
            break;

        case DIREITA:
            proximoy++;
            break;

        case CIMA:
            proximox--;
            break;
        
        case BAIXO:
            proximox++;
            break;
    }

    if(!ehvalida(&m, proximox, proximoy)) 
        return;

    if(!ehvazia(&m, proximox, proximoy)) 
        return;
    
    andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);
    heroi.x = proximox;
    heroi.y = proximoy;
}

int main(){

    lemapa(&m);
    encontrachar(&m, &heroi, HEROI);

    do{
        imprimemapa(&m);

        char comando;
        scanf(" %c", &comando);

        move(comando);

    } while (!acabou());
    
    liberamapa(&m); 
}