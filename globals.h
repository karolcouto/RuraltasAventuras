#ifndef GLOBAIS_H_INCLUDED
#define GLOBAIS_H_INCLUDED

//ESTRUTURAS;
typedef struct
{
    char nome[20];
    int inteligencia;
    int forca;
    int carisma;
    int energia;
    int posicao;
    int pontuacao;
} atributos;
atributos personagens;
atributos fernanda;


typedef struct
{
    char item1[30];
    char item2[30];
    char item3[30];
    int item4;
    int item5;
} inventario;
inventario itens;

#endif // GLOBAIS_H_INCLUDED
