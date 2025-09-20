#include<stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "functions.h"



void posner()
{

    personagens.posicao=4;
    limpar_tela();

    int h=1,i;
    char comando;
    int pontos=0;
    int v=0;
    FILE *pagep1,*pagep2,*pagep3,*pagep4,*pagep5,*pagep6,*pagep7,*pagep8,*q1,*quiztime,*q2,*q3,*q4;

    pagep1=fopen("paginap1.txt","r");
    pagep2=fopen("paginap2.txt","r");
    pagep3=fopen("paginap3.txt","r");
    pagep4=fopen("paginap4.txt","r");
    pagep5=fopen("paginap6.txt","r");
    pagep6=fopen("paginap6.txt","r");
    pagep7=fopen("paginap7.txt","r");
    pagep8=fopen("paginap8.txt","r");
    q1=fopen("questao1.txt","r");
    q2=fopen("questao2.txt","r");
    q3=fopen("questao3.txt","r");
    q4=fopen("questao4.txt","r");
    quiztime=fopen("horadoquiz.txt","r");

    while(v==0)
    {
        v=1;
        rewind(pagep1);
        imprime(pagep1);

        scanf(" %c",&comando);//acende ou nao a luz

        if(comando=='a'||comando=='A')
        {

            limpar_tela();
            imprime(pagep2);
            scanf(" %c",&comando);//implora ou desiste
        }
        else if(comando=='b'||comando=='B')
        {

            limpar_tela();
            imprime(pagep3);
            scanf(" %c",&comando);//implora ou desiste
        }
        else
        {
            limpar_tela();
            v=0;
        }
    }

    while(v)
    {
        v=0;
        if(comando=='a'||comando=='A')
        {
            limpar_tela();
            imprime(pagep4);//vai fazer a prova
            printf("PRESSIONE C PARA CONTINUAR>>\n");
            scanf(" %c",&comando);
        }
        else if(comando=='b'||comando=='B')
        {
            limpar_tela();

            imprime(pagep8);//fim


        }
        else
        {
            v=1;

        }
    }



    if(comando=='C'||comando=='c') //fazendo a prova
    {
        limpar_tela();


        h=1;

        while(h)
        {
            h=0;
            rewind(quiztime);
            imprime(quiztime);
            printf("PRESSIONE C PARA CONTINUAR>>\n");
            scanf(" %c",&comando);
            if(comando=='c'|| comando=='C')
            {
                limpar_tela();
            }
            else
            {
                h=1;
                limpar_tela();
            }
        }



        while(!h)
        {
            h=1;
            rewind(q1);
            imprime(q1);
            scanf(" %c",&comando);
            if(comando=='a'||comando=='A')
            {
                personagens.pontuacao++;
                pontos++;
                limpar_tela();
            }
            else if(comando=='b'||comando=='B')
            {
                limpar_tela();
            }
            else
            {
                h=0;
                limpar_tela();
            }
        }

        while(h)
        {
            h=0;
            rewind(q2);
            imprime(q2);
            scanf(" %c",&comando);
            if(comando=='b'||comando=='B')
            {
                personagens.pontuacao++;
                pontos++;
                limpar_tela();
            }
            else if(comando=='a'||comando=='A')
            {
                limpar_tela();
            }
            else
            {
                h=1;
                limpar_tela();
            }
        }

        while(!h)
        {
            h=1;
            rewind(q3);
            imprime(q3);
            scanf(" %c",&comando);
            if(comando=='a'||comando=='A')
            {
                personagens.pontuacao++;
                pontos++;
                limpar_tela();
            }
            else if(comando=='b'||comando=='B')
            {
                limpar_tela();
            }
            else
            {
                h=0;
                limpar_tela();
            }
        }

        while(h)
        {
            h=0;
            rewind(q4);
            imprime(q4);
            scanf(" %c",&comando);
            if(comando=='a'||comando=='A')
            {
                personagens.pontuacao++;
                pontos++;
                limpar_tela();
            }
            else if(comando=='b'||comando=='B')
            {
                limpar_tela();
            }
            else
            {
                h=1;
                limpar_tela();
            }
        }


        for(i=0; i<50; i++)
        {
            printf("CORRECAO EM ANDAMENTO 0%%   ||");
            limpar_tela();
        }

        for(i=0; i<50; i++)
        {
            printf("CORRECAO EM ANDAMENTO 20%%  |||||");
            limpar_tela();
        }

        for(i=0; i<50; i++)
        {
            printf("CORRECAO EM ANDAMENTO 50%%  |||||||||");
            limpar_tela();
        }

        for(i=0; i<50; i++)
        {
            printf("CORRECAO EM ANDAMENTO 70%%  |||||||||||||||");
            limpar_tela();
        }

        for(i=0; i<50; i++)
        {
            printf("CORRECAO EM ANDAMENTO 100%% |||||||||||||||||||");
            limpar_tela();
        }




        printf("\n[ Correcao feita! voce acertou %d / 4. ]\n\n",pontos);
        printf("___________________________________________\n\n");




        if(pontos==4)
        {
            personagens.pontuacao++;
            imprime(pagep6);



        }
        else
        {

            imprime(pagep7);


        }
    }
    personagens.pontuacao=personagens.pontuacao*10;

    printf("\n\nFIM!!!!\n\nSua pontuacao foi: %d!\n\nVoce deseja salvar sua pontuacao?\n\n[S] [N]\n",personagens.pontuacao);
    scanf(" %c",&comando);
    if(comando=='S'||comando=='s')
    {
        salvar_pontuacao(&personagens);
    }



}


void salvar_pontuacao(atributos *personagens)
{

    FILE *rank;
    rank=fopen("ranke.dat","ab");
    if(rank)
    {
        fwrite(personagens,sizeof(atributos),1,rank);

    }
    else
    {
        printf("O arquivo nao foi aberto.");
    }
    fclose(rank);
    personagens->pontuacao=0;
}

void imprimir_pontuacao()
{
    int i=0,j=0,k;

    atributos jogadores[1000];

    atributos troca;

    FILE *rank2,*rank1,*rank;
    rank1=fopen("ranke.dat","rb");
    rank2=fopen("ranke2.txt","w+");
    rank=fopen("rank_tela.txt","r");

    if(rank1 && rank2)
    {
        while(fread(&jogadores[i],sizeof(atributos),1,rank1))
        {

            fprintf(rank2,"Nome: %s\n\n",jogadores[i].nome);
            fprintf(rank2,"Pontuacao: %d\n\n",jogadores[i].pontuacao);
            i++;

        }




        for(k=0; k<i; k++)
        {
            for(j=0; j<i-1; j++)
            {

                if(jogadores[j].pontuacao<jogadores[j+1].pontuacao)
                {
                    troca=jogadores[j];
                    jogadores[j]=jogadores[j+1];
                    jogadores[j+1]=troca;

                }
            }
        }


        k=0;
        imprime(rank);
        for(j=0; j<i; j++)
        {
            k++;

            printf("\n            %d          |   ",k);

            printf("    %d        |",jogadores[j].pontuacao);

            printf("   %s\n",jogadores[j].nome);

        }
    }
    else
    {

        printf("O arquivo nao foi aberto.");

    }

    fclose(rank1);
    fclose(rank2);

}




