#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pacman.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;
int tempilula = 0;

int destinofantasma(int xatul, int yatual, int* xdestino, int* ydestino){
    
    int opcoes[4][2] = {
        { xatul  , yatual+1 },
        { xatul+1, yatual   },
        { xatul  , yatual-1 },
        { xatul-1, yatual   }
    };

    srand(time(0));
    for(int i = 0; i < 10; i++){
        int posicao = rand() % 4;

        if(podeandar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])){
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];

            return 1;
        }
    }

    return 0;
}

void fantasmas(){
    MAPA copia;

    copiamapa(&copia, &m);

    for(int i = 0; i < copia.linhas; i++) {
		for(int j = 0; j < copia.colunas; j++) {
			if(copia.matriz[i][j] == FANTASMA) {

				int xdestino;
				int ydestino;

				int encontrou = destinofantasma(i, j, &xdestino, &ydestino);

				if(encontrou) {
					andanomapa(&m, i, j, xdestino, ydestino);
				}
			}
		}
	}

    liberamapa(&copia);
    
}

int acabou(){
    POSICAO pos;
    int pacmannomapa = encontrachar(&m, &pos, HEROI);

    // se o pacman n tiver no mapa, o jogo acaba
    return !pacmannomapa;
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
    switch(direcao){
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

    if(!podeandar(&m, HEROI, proximox, proximoy)) 
        return;

    if(ehpersonagem(&m, PILULA, proximox, proximoy)){
        tempilula = 1;
    }
    
    andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);
    heroi.x = proximox;
    heroi.y = proximoy;
}

void explodepilula(){
    // analisa 3 posicoes pra direita
    for(int i = 1; i <= 3; i++){
        if(ehvalida(&m, heroi.x, heroi.y+i)){

            if(ehparede(&m, heroi.x, heroi.y+i)){
                break;
            }
        
            m.matriz[heroi.x][heroi.y+i] = VAZIO;
        }
    }
}

int main(){

    lemapa(&m);
    encontrachar(&m, &heroi, HEROI);

    do{
        printf("Tem pilula: %s\n", (tempilula ? "SIM" : "NAO"));
        imprimemapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);
        if(comando == BOMBA) explodepilula();

        fantasmas();

    } while (!acabou());
    
    liberamapa(&m); 
}