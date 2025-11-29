#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

void move(char direcao);

int acabou();
int ehdirecaovalida(char direcao);

int destinofantasma(int xatul, int yatual, int* xdestino, int* ydestino);
void fantasmas();
