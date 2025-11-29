#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

int acabou();
void move(char direcao);

int ehdirecaovalida(char direcao);

int destinofantasma(int xatul, int yatual, int* xdestino, int* ydestino);
void fantasmas();

