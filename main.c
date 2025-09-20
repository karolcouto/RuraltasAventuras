#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "functions.h"
#include "globals.h"

//FUNCAO PRINCIPAL;
int main()
{

    int n;

    setlocale(LC_ALL, "Portuguese");

    while(1)
    {

        system("cls");

        tela();

        scanf(" %d", &n);

        if(n==1)
            inicio();


        if(n==2)
            continuar();

        if(n==3)
            descricao();

        if(n==4)
            sair();

        if(n==5)
        {
            system("cls");

            imprimir_pontuacao();
            printf("\n\n");
            system("pause");
        }
    }
}

//TELA;
void tela()
{
    FILE *rural;
    char ascii[101];

    printf("\n\n\n\n\n\n");

    rural = fopen("TITULO ASCII.txt","r");

    while(!feof(rural))
    {
        fgets(ascii, 100, rural);
        printf("%s", ascii);
    }
    fclose(rural);

    printf("                                        A hist�ria de um aluno na rural\n\n\n");
    printf("                                        DIGITE UM N�MERO PARA PROSSEGUIR:\n\n");
    printf("                                                [1] Inicio >\n");
    printf("                                                [2] Continuar >\n");
    printf("                                                [3] Descri��o >\n");
    printf("                                                [4] Sair >\n");
    printf("                                                [5] Ver rank atual >\n\n");
    printf("                                                  Sua op��o: ");
}

//INICIO;
void inicio()
{
    system("cls");

    char name[20];
    int h=0, v=0;
    personagens.posicao=0;

    printf("                                           BEM-VINDO � RURAL!\n\n");
    printf("                                           Digite seu nome: ");

    scanf("%s", personagens.nome);

    //strcpy(personagens.nome, name); ?

    while(v==0)
    {
        v=personagem(v);
    }

    while(h==0)
    {
        h=item(h);
    }

    salvar();//autosave
    capitulo1();
}

//CONTINUAR;
void continuar()
{
    FILE *continua;

    continua= fopen("informacoes.dat","rb");

    fread(&personagens, sizeof(atributos), 1, continua);

    fread(&itens, sizeof(inventario), 1, continua);

    local();

    fclose(continua);
}

//DESCRICAO;
void descricao()
{
    limpar_tela();
    FILE *d=fopen("descricao.txt","r");
    imprime(d);
    system("pause");
    printf("\n\n");
    limpar_tela();
}

//SALVAR;
void salvar()
{
    FILE *salva;

    salva=fopen("informacoes.dat","wb");

    fwrite(&personagens, sizeof(atributos), 1, salva);

    fwrite(&itens, sizeof(inventario), 1, salva);

    fclose(salva);

}

//PONTUACAO;
void pontuacao()
{

}

//SAIR;
void sair()
{
    salvar();
    exit(0);
}

//PERSONAGEM (CHAMADA NA FUNCAO INICIO);
int personagem(int v)
{
    char n;
    int i;
    FILE *p,*p1;
    p=fopen("personagens.txt","r");
    p1=fopen("personagens2.txt","r");
    system("cls");


    imprime(p);
    printf("\n");
    imprime(p1);


    printf("Escolha: ");
    scanf(" %c", &n);

    if((n=='A') || (n=='a'))
    {
        personagens.inteligencia=6;
        personagens.forca=3;
        personagens.carisma=4;
        personagens.energia=4;
        personagens.posicao=0;
        printf("Voc� selecionou categoria: nerdola.\n");
        printf("PRESSIONE ENTER PARA CONTINUAR >");
        v=1;
        char j= getchar();
        j=getchar();
    }
    else if((n=='B') || (n=='b'))
    {
        personagens.inteligencia=3;
        personagens.forca=6;
        personagens.carisma=3;
        personagens.energia=5;
        personagens.posicao=0;
        printf("Voc� selecionou categoria: bombado.\n");
        printf("PRESSIONE ENTER PARA CONTINUAR >");
        v=1;
        char j= getchar();
        j=getchar();
    }
    else if((n=='C') || (n=='c'))
    {
        personagens.inteligencia=4;
        personagens.forca=3;
        personagens.carisma=6;
        personagens.energia=4;
        personagens.posicao=0;
        printf("Voc� selecionou categoria: puxa-saco.\n");
        printf("PRESSIONE ENTER PARA CONTINUAR >");
        v=1;
        char j= getchar();
        j=getchar();
    }
    else if((n=='D') || (n=='d'))
    {
        personagens.inteligencia=4;
        personagens.forca=4;
        personagens.carisma=3;
        personagens.energia=6;
        personagens.posicao=0;
        printf("Voc� selecionou categoria: Aluno com sono regulado.\n");
        printf("PRESSIONE ENTER PARA CONTINUAR >");
        v=1;
        char j= getchar();
        j=getchar();
    }
    else
    {
        v=0;
    }

    return v;
}

//ITEM (CHAMADA NA FUNCAO INICIO);
int item(int h)
{
    int i;

    system("cls");

    printf("Voc� tem em sua mochila um caderno, uma caneta e seu celular, voc� tem direito a mais 1 item,");
    printf("escolha com sabedoria...\n\n");

    printf("[1]Bandeja do bandejao:\n");
    printf("Funciona como um escudo, te livra de receber dano de 1 golpe da batalha.\n\n");

    printf("[2]Trento:\n");
    printf("Recupera sua energia em 2 pontos.\n\n");

    printf("[3]Desodorante:\n");
    printf("Aumenta seu carisma em 2 pontos.\n\n");

    scanf("%d", &i);

    if(i==1)
    {
        strcpy(itens.item1, "Caderno");
        strcpy(itens.item2, "Caneta");
        strcpy(itens.item3, "Celular");
        itens.item4=1;
        printf("Voc� selecionou: Bandeja do bandejao.\n");
        printf("PRESSIONE ENTER PARA CONTINUAR >");
        char c= getchar();
        c=getchar();
        h=1;
    }
    else if(i==2)
    {
        strcpy(itens.item1, "Caderno");
        strcpy(itens.item2, "Caneta");
        strcpy(itens.item3, "Celular");
        itens.item4=2;
        printf("Voc� selecionou: Trento.\n");
        printf("PRESSIONE ENTER PARA CONTINUAR >");
        char c= getchar();
        c=getchar();
        h=1;
    }
    else if(i==3)
    {
        strcpy(itens.item1, "Caderno");
        strcpy(itens.item2, "Caneta");
        strcpy(itens.item3, "Celular");
        itens.item4=3;
        printf("Voc� selecionou: Desodorante.\n");
        printf("PRESSIONE ENTER PARA CONTINUAR >");
        char c= getchar();
        c=getchar();
        h=1;
    }
    else
    {
        h=0;
    }

    return h;
}

