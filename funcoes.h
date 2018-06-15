struct elemento{
    int linha;
    int coluna;
    float valor;
    struct elemento *prox;
    struct elemento *ant;
};

void menu();

int verificalinha(int, int);

int verificacoluna(int, int);

int fim();
