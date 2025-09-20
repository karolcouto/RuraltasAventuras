#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

//FUNCOES DO INICIO;
void tela();
void menu2();
void inicio();
void continuar();
void descricao();
void salvar();
void info();
void pontuacao();
void sair();
int personagem(int v);
int item(int h);
void descricao();

//FUNCOES DOS CAPITULOS
void capitulo1();
void modo(FILE *fp);
void MARK();
int local();
int dados();

//CAPITULO DO RU
void RU();
void CURA();
void LUTA();
int tela_luta1(int juliaE, int personaE);

//CAPITULO FERNANDA
void limpar_tela();
void assistiuaula(int *pi,char *comando,int *casos);
void foinomark(FILE *page5,char *comando);
void batalha(int pe,char *comando,int *pf,int *fe);
int dado(int faces);
void imprime(FILE *fp);

//CAPITULO FERNANDA
void posner();
void salvar_pontuacao();
void imprimir_pontuacao();

#endif // FUNCOES_H_INCLUDED
