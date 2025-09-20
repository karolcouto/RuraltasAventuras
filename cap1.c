#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "functions.h"
#include "globals.h"

//HISTORIA;

void capitulo1()
{

    MARK(); //Fala com o Mark

    local(); //Pessoa escolhe para onde ela vai

}

void print(FILE *fp, int modo)
{

    char ascii[101];
    char letra;

    limpar_tela();

    if(fp==NULL)
    {
        printf("ERRO AO ABRIR");
    }

    //MODO LENTO;
    if(modo!=1) //Caractere por caractere
    {
        while (fscanf(fp, "%c", &letra) == 1)
        {
            printf("%c", letra);
            _sleep(1);
            if(letra == '\n')
                _sleep(70);
        }

    }

    //MODO RAPIDO;
    if(modo==1) //PRIMEIRO TEXTO - MARK
    {
        while (fgets(ascii, sizeof(ascii), fp) != NULL)
        {
            printf("%s", ascii);
        }
    }
}

void MARK()
{

    limpar_tela();

    //VARIAVEIS
    FILE *mark, *mark1, *mark2;
    int escolha, modo;

    //ESCOLHE ENTRE OS DOIS MODOS
    printf("Se deseja o modo rápido, digite 1>>\n");
    printf("Se não, digite qualquer outro número>>\n");
    printf("Escolha: ");
    scanf(" %d", &modo);

    mark=fopen("FASE1.txt", "r");
    mark1=fopen("MARK1.txt", "r");
    mark2=fopen("MARK2.txt", "r");

    print(mark, modo);

    //PRIMEIRA ESCOLHA;

    printf("\n");
    printf("                                         Sua escolha: ");
    scanf(" %d", &escolha); // ESCOLHA 1 - MARK

    printf("\n");

    //ESCOLHA 1
    if(escolha==1)
    {
        print(mark1, modo);
    }

    //ESCOLHA 2
    if(escolha==2)
    {
        print(mark2, modo);
    }

    printf("\n\n");
    system("pause");
    //printf("Pressione ENTER para continuar>>");
    //char k= getchar();
    //k=getchar();

    limpar_tela();

}




int local()
{

    int opcao=0;


    while(opcao==0)
    {
        limpar_tela();
        printf("Para qual local deseja ir?\n");
        printf("[1] RU (precisa de um ticket)\n");
        printf("[2] SALA 310 MULTIMIDIA\n");
        printf("[3] LABORATORIO\n");
        printf("[4] VOLTAR AO MENU\n");
        printf("Sua escolha: ");
        scanf(" %d", &opcao);

        if(opcao==1 && itens.item5==1)
        {
            RU();//nessa funcao o itens.item5 vai pra 0 para nao ter como vir pra ca denovo

            opcao=0;
        }
        else if(opcao==1 && itens.item5==0)
        {
            printf("Voce nao possui o item ticket do bandejao\n");
            printf("Escolha novamente>>\n");

            printf("Pressione ENTER para continuar>>");

            char k= getchar();
            k=getchar();

            opcao=0;
        }
        else if(opcao==2 && personagens.posicao==0)
        {
            fernandinha();//nessa funcao o personagem.posicao vai pra 1 ou 2 para nao ter como vir pra ca denovo

            salvar();//autosave
            opcao=0;

        }
        else if(opcao==2 && personagens.posicao!=0 )
        {
            printf("A sala esta ocupada por outra turma\n");
            printf("Escolha novamente>>\n");
            //itens.item5==1;

            printf("Pressione ENTER para continuar>>");

            char k= getchar();
            k=getchar();

            opcao=0;
        }
        else if(opcao==3 && personagens.posicao==2 )
        {

            posner();
            opcao=0;
            printf("Pressione ENTER para continuar>>");

            char k= getchar();
            k=getchar();


        }
        else if(opcao==3 && personagens.posicao!=2 )
        {
            printf("A sala esta ocupada por outra turma\n");
            printf("Escolha novamente>>\n");
            //itens.item5==1;

            printf("Pressione ENTER para continuar>>");

            char k= getchar();
            k=getchar();
            opcao=0;
        }
        else if(opcao==4)
        {

        }

    }

}

void RU()
{

    FILE *RU, *RU2;
    int modo, v=0, escolha;
    itens.item5=0;
    personagens.posicao=2;
    salvar();//autosave

    RU=fopen("RU.txt","r");
    RU2=fopen("RU2.txt","r");

    limpar_tela();

    printf("Se deseja o modo rápido, digite 1>>\n");
    printf("Se não, digite qualquer outro número>>\n");
    printf("Escolha: ");
    scanf(" %d", &modo);

    limpar_tela();

    //MODO LENTO;
    print(RU, modo);

    printf("\n\n");
    printf("             Sua escolha: ");

    //ESCOLHA 1 - SE DEFENDER DO ATAQUE
    while(v==0)
    {
        scanf(" %d", &escolha);

        switch(escolha)
        {
        case 1:
        {
            if(itens.item4==1) //BANDEJA DO BANDEJAO
            {
                itens.item4=0;
                v=1;
            }
            else
            {
                printf("VOCE NAO POSSUI BANDEJA DO BANDEJAO\n");
                printf("ESCOLHA NOVAMENTE: ");
                v=0;
            }
            break;
        }
        case 2: //RECEBEU O GOLPE
        {
            personagens.carisma=personagens.carisma-2;
            v=1;
            break;
        }
        case 3: //DEFENDEU DO GOLPE
        {
            personagens.forca=personagens.forca-2;
            v=1;
            break;
        }
        case 4: //DESVIOU DO GOLPE
        {
            personagens.energia=personagens.energia-1;
            v=1;
            break;
        }
        default:
        {
            printf("ESCOLHA UMA OPCAO VALIDA: ");
            v=0;
            break;
        }
        }
    }

    printf("\n\n");

    //MODO LENTO;
    print(RU2, modo);

    v=0;

    info();

    printf("\n\n");
    printf("             Sua escolha: ");

    while(v==0) // ESCOLHA 2 - LUTA OU CURA
    {
        scanf(" %d", &escolha);

        if(escolha==1) //TENTAR ACHAR SOLUCAO
        {
            //TEM INTELIGENCIA SUFICIENTE
            if(personagens.inteligencia>=5)
            {
                CURA();
                v=1;
                personagens.pontuacao++;
            }
            else
            {
                printf("VOCE NAO POSSUI INTELIGENCIA SUFICIENTE\n");
                printf("INTELIGENCIA ATUAL: %d\n", personagens.inteligencia);
                printf("Escolha novamente: ");
                escolha=0;
                v=0;
            }
        }
        else if(escolha==2) //LUTA
        {
            LUTA();
            v=2;
        }
        else
        {
            printf("ESCOLHA UMA OPCAO VALIDA: ");
            v=0;
        }
    }

}

void CURA()
{

    FILE *RU3, *RU4;
    int modo, v=0, escolha;

    RU3=fopen("RU3.txt","r");
    RU4=fopen("RU4.txt","r");

    limpar_tela();

    printf("Se deseja o modo rápido, digite 1>>\n");
    printf("Se não, digite qualquer outro número>>\n");
    printf("Escolha: ");
    scanf(" %d", &modo);

    limpar_tela();

    print(RU3, modo);

    printf("\n\n");
    printf("Sua escolha: ");

    // ESCOLHA4 - SALVAR A JULIA OU LUTAR - DEPENDE DA ENERGIA
    while(v==0)
    {
        scanf(" %d", &escolha);

        limpar_tela();

        if(escolha==1 && personagens.energia>1)
        {
            print(RU4, modo);

            printf("Pressione ENTER para continuar>>");
            char k=getchar();
            k=getchar();

            local();
            v=1;
        }
        else if(escolha==2)
        {
            LUTA();
            v=1;
        }
        else
        {
            printf("DIGITE UM NUMERO VALIDO\n");
            v=0;
        }
    }
}

void LUTA()
{

    FILE *RU5, *RU6, *RU7;
    int face, v=0, escolha, modo;
    int ataque_pessoa, ataque_julia, juliaE=3, personaE;

    personaE=personagens.energia;

    RU5=fopen("RU5.txt","r");
    RU6=fopen("RU6.txt","r");
    RU7=fopen("RU7.txt","r");

    limpar_tela();

    printf("Se deseja o modo rápido, digite 1>>\n");
    printf("Se não, digite qualquer outro número>>\n");
    printf("Escolha: ");
    scanf(" %d", &modo);

    limpar_tela();

    print(RU5, modo);

    printf("\n");
    system("pause");
    printf("Pressione ENTER para continuar>>");
    char k= getchar();
    k=getchar();

    //BATALHA
    while(v==0)
    {
        ataque_julia= tela_luta1(juliaE, personaE);

        scanf(" %d", &escolha);

        switch(escolha)
        {
        case 1:
        {
            if(itens.item4==1)
            {
                itens.item4=0;
                v=0;
                printf("                                          VOCE BLOQUEOU O ATAQUE\n");
                printf("\n\n");
                printf("                                      Pressione ENTER para continuar>>");

                char k= getchar();
                k=getchar();
                break;
            }
            else
            {
                printf("                                          VOCE NAO POSSUI BANDEJA DO BANDEJAO\n");
                v=0;
                printf("\n\n");
                printf("                                                   Escolha novamente: ");
                scanf(" %d", &escolha);
            }
        }
        case 2:
        {
            if(itens.item4==2)
            {
                itens.item4=0;
                v=0;
                personaE=personaE+2;
                printf("                                          VOCE UTILIZOU TRENTO (ENERGIA+2)\n");
                printf("\n\n");
                printf("                                           Pressione ENTER para continuar>>");

                char k= getchar();
                k=getchar();
                break;
            }
            else
            {
                printf("                                          VOCE NAO POSSUI TRENTO\n");
                printf("\n\n");
                printf("                                             Escolha novamente: ");
                scanf(" %d", &escolha);
                v=0;
            }
        }
        case 3:
        {
            ataque_pessoa=dados(10)+(personagens.forca);
            printf("                                       SEU ATAQUE: %d\n", ataque_pessoa);
            printf("\n");

            if(ataque_pessoa>ataque_julia)
            {
                printf("                                   SEU ATAQUE FOI MAIS PODEROSO!\n");
                printf("                                          JULIA: -1\n");
                juliaE--;
                v=0;
                printf("\n\n");
                printf("                                  Pressione ENTER para continuar>>");

                char k= getchar();
                k=getchar();
                personagens.pontuacao++;

                break;
            }
            else if(ataque_pessoa==ataque_julia)
            {
                printf("                           SEU ATAQUE FOI IGUAL! OS DOIS PERDEM ENERGIA.\n");
                printf("                           VOCE: -1                            JULIA: -1\n");
                juliaE--;
                personaE--;
                printf("\n\n");
                printf("                                   Pressione ENTER para continuar>>");

                char k= getchar();
                k=getchar();
                v=0;
                break;
            }
            else
            {
                personaE--;
                printf("                                   SEU ATAQUE FOI MAIS FRACO!\n");
                printf("                                           VOCE: -1\n");
                printf("\n\n");
                printf("                                  Pressione ENTER para continuar>>");

                char k= getchar();
                k=getchar();
                v=0;
                break;
            }
        }
        default:
        {
            printf("                                          ESCOLHA UMA OPCAO VALIDA: ");
            scanf(" %d", &escolha);
            v=0;
            break;
        }
        }

        if(juliaE==0)
        {
            personagens.pontuacao+=3;
            limpar_tela();
            printf("                    ___________________________________________________________\n");
            printf("                    |                                                         |\n");
            printf("                    |          VOCE             X             Monstro         |\n");
            printf("                    |          %d                              %d               |\n", personaE, juliaE);
            printf("                    ___________________________________________________________\n\n\n");
            printf("                               ----------------------------\n");
            printf("                               |  VOCE GANHOU!!! SLAYYY   |\n");
            printf("                               ----------------------------\n");
            printf("\n\n");
            printf("                               Pressione ENTER para continuar>>");

            char k= getchar();
            k=getchar();
            v=1;
        }
        else if(personaE==0)
        {
            limpar_tela();
            printf("                    ___________________________________________________________\n");
            printf("                    |                                                         |\n");
            printf("                    |          VOCE             X             Monstro         |\n");
            printf("                    |          %d                              %d               |\n", personaE, juliaE);
            printf("                    ___________________________________________________________\n\n\n");
            printf("                               ----------------------------\n");
            printf("                               |    VOCE PERDEU!!! vixi   |\n");
            printf("                               ----------------------------\n");
            printf("\n\n");
            printf("                               Pressione ENTER para continuar>>");

            char k= getchar();
            k=getchar();
            v=2;
        }
    }

    if(v==1)
    {
        print(RU6, modo);
        itens.item5=2; //COLHER DE COMIDA DA JULIA
        printf("\n\n");
        printf("Pressione ENTER para continuar>>");

        char k= getchar();
        k=getchar();
        //salvar();
        local();
    }
    else if(v==2)
    {
        print(RU7, modo);
        printf("\n\n");
        printf("Pressione ENTER para continuar>>");

        char k= getchar();
        k=getchar();
        //salvar();
        local();
    }
}

int tela_luta1(int juliaE, int personaE)
{

    FILE *asciibatalha;
    char* ataques[]= {"TAPA","MORDIDAO","QUEDA DE BRACO","RESPIGOS DA AGUA DOS TALHERES","ARRANHAO"};
    int juliaF=3, juliaA, i;
    char ascii[101];

    juliaA=dados()+juliaF;
    i=(rand()%4);

    limpar_tela();

    asciibatalha= fopen("asciibatalha.txt","r");

    while(!feof(asciibatalha))
    {
        fgets(ascii, 100, asciibatalha);
        printf("%s", ascii);
    }

    fclose(asciibatalha);

    printf("\n\n\n");
    printf("                    ___________________________________________________________\n");
    printf("                    |                                                         |\n");
    printf("                    |          VOCE             X             Monstro         |\n");
    printf("                    |          %d                              %d               |\n", personaE, juliaE);
    printf("                    ___________________________________________________________\n\n\n");
    printf("                        JULIA UTILIZOU ATAQUE: %s\n", ataques[i]);
    printf("                        FORCA: %d\n", juliaA);
    printf("                        FORCA MAXIMA: 13\n\n");
    printf("                               x---VOCE:------------------------x\n");
    printf("                               |[1] Utiliza bandeja do bandejao |\n");
    printf("                               |[2] Utiliza trento (Energia +2) |\n");
    printf("                               |[3] Tenta revidar               |\n");
    printf("                               x--------------------------------x\n");

    printf("                                       SUA ESCOLHA: ");

    return juliaA;

}

void info()
{
    printf("        x---------ATRIBUTOS----------x\n");
    printf("        |ENERGIA: %d                 |\n", personagens.energia);
    printf("        |INTELIGENCIA: %d            |\n", personagens.inteligencia);
    printf("        |FORCA: %d                   |\n", personagens.forca);
    printf("        |CARISMA: %d                 |\n", personagens.carisma);
    printf("        x----------------------------x\n");
}

int dados()
{

    int i, o;

    srand(time(NULL));

    i=1+(rand()%10);

    return i;
}
