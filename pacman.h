#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define BOMBA 'b'

int acabou();
void move(char direcao);

int ehdirecaovalida(char direcao);

int destinofantasma(int xatul, int yatual, int* xdestino, int* ydestino);
void fantasmas();

void explodepilula();
void explodepilula2(int x, int y, int somax, int somay, int qntd);

