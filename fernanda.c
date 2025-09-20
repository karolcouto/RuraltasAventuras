#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include <locale.h>
#include "globals.h"
#include "functions.h"

void fernandinha()
{

    int i=0,tamanho=1,teste_carisma=0,casos=1,pe=0;
    char comando;
    pe=personagens.energia;



    srand(time(NULL));

    limpar_tela();

    fernanda.energia=4;

    FILE *page1,*page2,*page8,*page3,*page4,*page5,*page6,*page7,*page9,*page10,*page11,*page12,*page13;

    page1=fopen("paginaf1.txt","r");
    page2=fopen("paginaf2.txt","r");
    page8=fopen("paginaf8.txt","r");
    page3=fopen("paginaf3.txt","r");
    page4=fopen("paginaf4.txt","r");
    page5=fopen("paginaf5.txt","r");
    page6=fopen("paginaf6.txt","r");
    page7=fopen("paginaf7.txt","r");
    page9=fopen("paginaf9.txt","r");
    page10=fopen("paginaf10.txt","r");
    page11=fopen("paginaf11.txt","r");
    page12=fopen("paginaf12.txt","r");
    page13=fopen("paginaf13.txt","r");

    imprime(page1);


    scanf(" %c",&comando);

    if(comando=='a'|| comando=='A')  //cumprimentar
    {
        limpar_tela();
        imprime(page2);
        scanf(" %c",&comando);

        limpar_tela();//calculando carisma
        teste_carisma=dado(10);
        printf("Valor do dado: %d\nValor do seu carisma atual:%d\n\n",teste_carisma,personagens.carisma);
        if(teste_carisma<=personagens.carisma)
        {
            personagens.pontuacao++;
            printf("Voce foi carismatico :)\n\n\n");
            imprime(page3);
            scanf(" %c",&comando);//ir no mark ou assistir aula?

        }
        else if(teste_carisma>personagens.carisma)
        {

            printf("Voce nao foi carismatico o bastante :(\n\n\n");
            imprime(page4);

            printf("Pressione ENTER para continuar>>");

            char k= getchar();
            k=getchar();

            limpar_tela();
            batalha(pe,&comando,&personagens.forca,&fernanda.energia);
        }

    }
    else if(comando=='b'||comando=='B')   //pegar a forca
    {
        limpar_tela();
        imprime(page8);

        printf("Pressione ENTER para continuar>>");

        char k= getchar();
        k=getchar();

        limpar_tela();
        batalha(pe,&comando,&personagens.forca,&fernanda.energia);
    }

    if(comando=='c'|| comando=='C') //depois da batalha
    {

        if(fernanda.energia==0) //personagem venceu
        {
            fernanda.energia==4;
            personagens.pontuacao+=3;

            imprime(page10);

            scanf(" %c",&comando);

            if(comando=='a'|| comando=='A')  //foi no mark
            {
                foinomark(page5,&comando);
            }
            else if(comando=='b' || comando=='B')  //assistiu a aula
            {
                limpar_tela();
                imprime(page6);
                scanf(" %c",&comando);
                assistiuaula(&personagens.inteligencia,&comando,&casos);
            }

        }
        else  //personagem perdeu
        {
            personagens.posicao=2;
            fernanda.energia=4;
            casos=0;
            imprime(page11);
            scanf(" %c",&comando);
            assistiuaula(&personagens.inteligencia,&comando,&casos);
        }
    }



    if(comando=='a'|| comando=='A') //foi no mark
    {
        foinomark(page5,&comando);
    }

    if(comando=='b' || comando=='B') //assistiu a aula
    {
        limpar_tela();
        imprime(page6);

        scanf(" %c",&comando);
        assistiuaula(&personagens.inteligencia,&comando,&casos);

    }






}

void batalha(int pe,char *comando,int *pf,int *fe)
{

    int faces, forca_ataque_vilao=0, forca_ataque_personagem=0, h=0, n=0;

    char* ataques[]= {"rajadao de duvidas pertinentes para deixar ela desnorteada","tapinha singelo","sorriso brilhante para ofuscar os olhos dela","danca babadeira para deixar ela desnorteada"};

    atributos fernanda;
    fernanda.forca=3;

    while(*fe>0 && pe>0)
    {
        forca_ataque_vilao= dado(10) + fernanda.forca;

        h=0;

        while(h==0)
        {
            printf("+-------------------------------------------------+\n");
            printf("| Fernanda te golpeou com uma forca de ataque: %d  |\n",forca_ataque_vilao);
            printf("|                                                 |\n");
            printf("|   escolha seu ataque para calcular sua forca.   |\n");
            printf("+-------------------------------------------------+\n\n");
            printf("[I]Usar inteligencia\n");
            printf("[F]Usar forca\n");
            printf("[C]Usar carisma\n");
            printf("[E]Usar energia\n\n");
            printf("Sua escolha: ");
            scanf(" %c", comando);
            limpar_tela();
            printf("\nVoce revidou com um ");

            if(*comando=='i'|| *comando=='I')
            {
                printf("%s",ataques[0]);
                h=1;


            }
            else if(*comando=='f'|| *comando=='F')
            {
                printf("%s",ataques[1]);
                h=1;

            }
            else if(*comando=='c'|| *comando=='C')
            {
                printf("%s",ataques[2]);
                h=1;

            }
            else if(*comando=='e'|| *comando=='E')
            {
                printf("%s",ataques[3]);
                h=1;

            }
            else
            {
                limpar_tela();
                printf("Resposta inválida.\n\n");
                h=0;
            }
        }


        forca_ataque_personagem= dado(10) + *pf;

        printf(" com uma forca de ataque: %d\n\n",forca_ataque_personagem);


        if(forca_ataque_personagem>forca_ataque_vilao)
        {
            personagens.pontuacao++;
            *fe=*fe-1;
            printf("+----------------------------------+\n");
            printf("|    Seu ataque foi mais forte!    |\n");
            printf("|                                  |\n");
            printf("|      Energia de Fernanda:-1      |\n");
            printf("|                                  |\n");
            printf("|     Sua energia restante: %d      |\n",pe);
            printf("| Energia restante de Fernanda: %d  |\n",*fe);
            printf("+----------------------------------+\n\n");
        }
        else if(forca_ataque_personagem==forca_ataque_vilao)
        {
            printf("+----------------------------------+\n");
            printf("|  Ambos(as) desviaram dos ataques |\n");
            printf("|                                  |\n");
            printf("|     Sua energia restante: %d      |\n",pe);
            printf("| Energia restante de Fernanda: %d  |\n",*fe);
            printf("+----------------------------------+\n\n");

        }
        else if(forca_ataque_personagem<forca_ataque_vilao)
        {
            pe=pe-1;
            printf("+----------------------------------------+\n");
            printf("| O ataque de Fernanda foi mais forte :( |\n");
            printf("|                                        |\n");
            printf("|             Sua energia:-1             |\n");
            printf("|                                        |\n");
            printf("|        Sua energia restante: %d         |\n",pe);
            printf("|    Energia restante de Fernanda: %d     |\n",*fe);
            printf("+----------------------------------------+\n\n");

        }

        if(*fe==0)
        {
            printf("VOCE MEIO QUE DIVOU PARABENS WINNER!!!!!\n\n");
            printf(" \\( ^ U ^ )/");

        }
        else if(pe==0)
        {
            printf("ixi voce perdeu ;(\n");
        }

        while(h)
        {
            h=0;
            printf("\nPressione c para continuar>>\n");
            scanf(" %c", comando);

            if(*comando=='c' || *comando=='C')
            {

                limpar_tela();

            }
            else
            {
                limpar_tela();
                printf("RESPOSTA INVALIDA\n\n");
                h=1;
            }
        }

        forca_ataque_personagem=0;
        forca_ataque_vilao=0;

    }
}

int dado(int faces)
{

    return (rand()% faces) +1;
}

void limpar_tela()
{
    system("cls");
}

void imprime(FILE *fp)
{
    char texto[5500];
    int i=0;

    while(!feof(fp))
    {
        fscanf(fp,"%c",&texto[i]);
        i++;
    }
    texto[i] = '\0';
    printf("%s",texto);

}

void assistiuaula(int *pi,char *comando,int *casos)
{

    FILE *page7,*page9,*page12,*page13;
    page9=fopen("paginaf9.txt","r");
    page7=fopen("paginaf7.txt","r");
    page12=fopen("paginaf12.txt","r");
    page13=fopen("paginaf13.txt","r");

    int teste_inteligencia=0;

    limpar_tela();
    teste_inteligencia=dado(10);
    personagens.pontuacao++;
    printf("Valor do dado: %d\nValor da sua inteligencia atual:%d\n\n",teste_inteligencia,*pi);
    if(teste_inteligencia<=*pi)
    {

        printf("Voce foi inteligente!\n\n\n");
        personagens.pontuacao++;
        if(*casos==1)
        {
            imprime(page7);//foi no mark
            personagens.posicao=1;
            itens.item5=1;
            system("pause");

        }
        if(*casos==0)
        {
            imprime(page13);

            system("pause");
        }
    }
    else if(teste_inteligencia>*pi)
    {

        printf("Voce foi burrinho(a) :(\n\n\n");

        if(*casos==1)
        {
            imprime(page9);//foi no marksalvar();//autosave

            system("pause");

        }
    }
}

void foinomark(FILE *page5,char *comando)
{
    personagens.posicao=1;
    itens.item5=1;
    limpar_tela();
    imprime(page5);

    printf("Pressione ENTER para continuar>>");

    char k= getchar();
    k=getchar();

}
